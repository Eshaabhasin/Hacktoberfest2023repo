import cv2 as cv 
import numpy as np 


link = r'address'
im = cv.imread(link)
img = cv.resize(im, (500,500) ,interpolation=cv.INTER_AREA)
cv.imshow('image', img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('gray', gray)

#1. Laplacian
lap = cv.Laplacian(gray, cv.CV_64F)
lap = np.uint8(np.absolute(lap))
cv.imshow('Laplacian', lap)


#2. Sobel 
sabX = cv.Sobel(gray, cv.CV_64F, 1, 0)
sabY = cv.Sobel(gray, cv.CV_64F, 0, 1)
combo = cv.bitwise_or(sabX, sabY)

cv.imshow('SobelX', sabX)
cv.imshow('SobelY', sabY)
cv.imshow('2-Sum', combo) 


#3. Comapring with Canny
can =cv.Canny(img, 175, 150)
cv.imshow('Canny Image', can)
