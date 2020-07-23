import cv2


# reading of image
img = cv2.imread("text.jpg")
cv2.imshow("original",img)

# color conversion

img_gray = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
img_hsv =  cv2.cvtColor(img,cv2.COLOR_RGB2HSV)

cv2.imshow("grayscale",img_gray)
cv2.imshow("hsv",img_hsv)

# resizing original image

img_resize = cv2.resize(img,(300,300))
cv2.imshow("resized",img_resize)

print("Shape and Size of original image : " , img.shape , img.size)
print("Shape and Size of resized image : " , img_resize.shape , img_resize.size)


# Simple thresholding

ret,thresh_binary = cv2.threshold(img_gray,150,255,cv2.THRESH_BINARY)
ret,thresh_binary_inv = cv2.threshold(img_gray,150,255,cv2.THRESH_BINARY_INV)
ret,thresh_otsu = cv2.threshold(img_gray,150,255,cv2.THRESH_OTSU)

cv2.imshow("simple binary",thresh_binary)
cv2.imshow("simple binary inv",thresh_binary_inv)
cv2.imshow("simple otsu",thresh_otsu)


# adaptive thresholding

ad_thresh_mean = cv2.adaptiveThreshold(img_gray,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,5,2)
ad_thresh_guass = cv2.adaptiveThreshold(img_gray,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,5,2)

cv2.imshow("adaptive mean",ad_thresh_mean)
cv2.imshow("adaptive guass",ad_thresh_guass)




# saving images

cv2.imwrite("grayscale.jpg",img_gray)
cv2.imwrite("hsv.jpg",img_hsv)
cv2.imwrite("simple_binary.jpg",thresh_binary)
cv2.imwrite("simple_binary_inv.jpg",thresh_binary_inv)
cv2.imwrite("simple_otsu.jpg",thresh_otsu)
cv2.imwrite("adaptive_mean.jpg",ad_thresh_mean)
cv2.imwrite("adaptive_guass.jpg",ad_thresh_guass)



print("ALL IMAGES HAVE BEEN SAVED")



cv2.waitKey(0)
cv2.destroyAllWindows()