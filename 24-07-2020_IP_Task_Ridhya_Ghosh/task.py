import cv2
import numpy as np

img = cv2.imread("flower.jpg")
res = cv2.resize(img,(600,400))
cv2.imshow("resized",res)


# masking

# 23,91,0 and 45,255,255 are the values for masking yellow color

rgbl = np.array([23,91,0],np.uint8)
rgbh = np.array([45,255,255],np.uint8)
mask = cv2.inRange(res,rgbl,rgbh)

cv2.imshow("masked",mask)









# blurring

kernel = np.array(([1,2,3],[2,2,1],[2,4,3]) , np.uint8)

#filter 2d
fil = cv2.filter2D(res,-1,kernel)
cv2.imshow("2d filter",fil)

#average blur
avg = cv2.blur(res,(5,5))
cv2.imshow("average",avg)

#median blur
median = cv2.medianBlur(res,5)
cv2.imshow("median",median)


#guassian blur
guass = cv2.GaussianBlur(res,(5,5),0)
cv2.imshow("guass",guass)

#bilateral blur
bilateral = cv2.bilateralFilter(res,5,111,111)
cv2.imshow("bilateral",bilateral)


# drawing and writing on image

pts = np.array([[250,400],[215,320],[375,320],[340,400]],np.int32)
pts = pts.reshape((-1,1,2))


image1 = cv2.fillPoly(res,[pts],(19,69,139))



font = cv2.FONT_HERSHEY_SCRIPT_SIMPLEX
cv2.putText(image1,'Unknown flower',(75,50),font,2,(255,255,0))
cv2.imshow("test",image1)



#saving images

cv2.imwrite("resized.jpg",res)
cv2.imwrite("filter2d.jpg",fil)
cv2.imwrite("average_blur.jpg",avg)
cv2.imwrite("masked.jpg",mask)
cv2.imwrite("median_blur.jpg",median)
cv2.imwrite("guassian_blur.jpg",guass)
cv2.imwrite("bilateral.jpg",bilateral)
cv2.imwrite("text_pot.jpg",image1)




cv2.waitKey(0)
cv2.destroyAllWindows()