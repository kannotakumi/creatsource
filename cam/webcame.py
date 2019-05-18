import numpy as np
import cv2

cap = cv2.VideoCapture(0)
 
while (True):
    ret,frame = cap.read()
    t = 127
    cv2.imshow('frame',frame)
    
    path = "photo.jpg"

    if cv2.waitKey(1):
        #cv2.imwrite(path,frame)
        img = cv2.imread("photo.jpg")
        gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

        ret, th2 = cv2.threshold(gray, t, 255, cv2.THRESH_BINARY)

        cv2.imwrite("test.jpg", th2)
        continue
    if cv2.waitKey(0):
        break

