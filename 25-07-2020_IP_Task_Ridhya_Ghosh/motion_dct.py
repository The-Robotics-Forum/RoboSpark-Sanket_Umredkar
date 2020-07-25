import cv2
import numpy as np
from time import sleep


cap = cv2.VideoCapture(0)

# Creating old frame
ret, frame = cap.read()
old = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

# Lucas-Kanade Params which is used in Optical flow
lkParams = dict(winSize=(20, 20),
                maxLevel=4,
                criteria=(cv2.TermCriteria_EPS | cv2.TERM_CRITERIA_COUNT, 10, 0.03))





# Optical flow works by calculating the displacement vectors
# We generally use goodFeaturesToTrack() function to generate points for optical flow
# However for optical flow to work properly , the intensity of the selected points should be same throughout the motion of the object
# This is difficult to achieve in a webcam video
# So we have to create our own point
# Since the created point will be fixed optical flow will be able to calculate the displacement vector properly
# This will yield better results than goodFeaturesToTrack()




# Function for selecting the point on which optical flow will be applied
# We will use setMouseCallback() to select the clicked object.


def selectPoint(event, x, y, flags, params):
    global point, pointSelected, oldPoints
    if event == cv2.EVENT_LBUTTONDOWN:    # on clicking left mouse button
        point = (x, y)
        pointSelected = True
        oldPoints = np.array([[x, y]], dtype=np.float32)   # creates an array of the coordinates of the selected points


# Direction Detection Function
# since the video on the webcam is inverted we will use reverse conditions
# i.e. if x coordinate of new > x coordinate of old motion will be towards left and vice versa
def Direction(old, new):
    if new[0][0] + 1 < old[0][0]:
        dir = 'MOTION TOWARDS RIGHT'
    elif new[0][0] - 1 > old[0][0]:
        dir = 'MOTION TOWARDS LEFT'
    else:
        dir = 'NO MOTION'
    return dir








# Clicking on point and calling select point function
cv2.namedWindow("Frame")
pointSelected = False
point = ()
oldPoints = np.array([[]])
cv2.setMouseCallback("Frame", selectPoint)

while (True):


    ret, frame = cap.read()
    new = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)


    # If the point is selected we will use optical flow on that point to calculate its trajectory and coordinates of the stopping point
    if pointSelected is True:
        newPoints, status, error = cv2.calcOpticalFlowPyrLK(old, new, oldPoints, None, **lkParams)
        old = new.copy()
        dir = Direction(oldPoints, newPoints)  # detects the direction
        oldPoints = newPoints
        x, y = newPoints.ravel()   # converts array of coordinates back to coordinates
        cv2.circle(frame, (x, y), 5, (0, 255, 0), -1)   # creates dot on the point selected
        cv2.putText(frame, dir, (200, 450), cv2.FONT_HERSHEY_DUPLEX, 0.8, (255, 140, 0), 2)  # displaying direction

    # Executed when object is not selected
    else:
        dir = 'SELECT A POINT'
        cv2.putText(frame, dir, (200, 450), cv2.FONT_HERSHEY_TRIPLEX, 0.8, (0, 0, 255), 3)

    # Show Frame
    cv2.imshow("Frame", frame)

    # This is used so that direction text can be put on the image
    # If not used then the image will show select a point the entire time
    sleep(0.5)

    # Initializing Wait Key
    if(cv2.waitKey(1)==ord('q')):
        break


cap.release()

cv2.destroyAllWindows()