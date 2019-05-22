#coding:utf-8
import numpy as np
import cv2
import sys
import os
import commands
#sh = "sudo /home/pi/./get_ping.sh"
#sh = "sudo tcpdump > /home/pi/get_ping.txt"
cap = cv2.VideoCapture(0)
#os.system(sh)
while (True):
    ret,frame = cap.read()
    #t = 127
    
    path = "photo.jpg"
    txt = "get_ping.txt"
    cv2.imshow('frame',frame)
    commands.getoutput("sudo /home/pi/mkf.sh")
    f = open(txt)

    s = f.read()
    if not s:
        continue
    else:
         cv2.imwrite(path, frame)
         img = cv2.imread(path)
         f.close()
         os.remove(txt)

    
    cv2.imshow("img",img)
    #cv2.imwrite("photp.jpg", frame)
   # if cv2.waitKey(1):
    #    cv2.imwrite(path,frame)
     #   img = cv2.imread("photo.jpg")
      #  gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
       # ret,th2 = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
       # th3, contours, hietarchy = cv2.findContours(th2, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
       # area = cv2.contourArea(contours[0])
       # cv2.imshow("frame",th3)
       # print(area)
       # continue
   # if cv2.waitKey(0):
    #    break

