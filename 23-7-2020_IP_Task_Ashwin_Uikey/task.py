import cv2
img=cv2.imread(r"E:\RoboSpark Task\23-7-2020_IP_Task_Ashwin_Uikey\text.jpg")
cv2.imshow("original",img)

#read image
grayimg=cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
hsvimg=cv2.cvtColor(img,cv2.COLOR_RGB2HSV)

#convert to gray and hsv
cv2.imshow("gray",grayimg)
cv2.imshow("hsv",hsvimg)

#resize
resizeimg=cv2.resize(img,(350,320))
cv2.imshow("resize image",resizeimg)

#print
print("Dimensions of Original Image : ",img.shape,img.size)
print("Dimensions of Resized Image : ",resizeimg.shape,resizeimg.size)

#threshold
ret,thresh0 = cv2.threshold(grayimg,150,255,cv2.THRESH_BINARY)
ret,thresh1 = cv2.threshold(grayimg,150,255,cv2.THRESH_BINARY_INV)
ret,thresh2 = cv2.threshold(grayimg,150,255,cv2.THRESH_OTSU)

cv2.imshow("Binary",thresh0)
cv2.imshow("Binary Inversion",thresh1)
cv2.imshow("OTSU",thresh2)

#adaptive
mean = cv2.adaptiveThreshold(grayimg,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,3,2)
gauss = cv2.adaptiveThreshold(grayimg,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,3,2)

cv2.imshow("Mean",mean)
cv2.imshow("Gauss",gauss)


#saving images
titles = ['original','resized','gray_image','HSV_image','binary','binary_inv','otsu','mean','gauss']
names = [img,resizeimg,grayimg,hsvimg,thresh0,thresh1,thresh2,mean,gauss]

for i in range(len(titles)):
    cv2.imwrite(f"E:/RoboSpark Task/23-7-2020_IP_Task_Ashwin_Uikey/{titles[i]}.jpg",names[i])


cv2.waitKey(0)
cv2.destroyAllWindows()