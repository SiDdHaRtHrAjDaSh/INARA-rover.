# -*- coding: utf-8 -*-
"""
Created on Sat Feb 22 03:47:52 2020

@author: AVINASH
"""

import numpy as np
import cv2
import datetime
from firebase import firebase
import time

out = cv2.VideoWriter(
    'alertall.avi',
    cv2.VideoWriter_fourcc(*'MJPG'),
    15.,
    (640,480))

FBConn = firebase.FirebaseApplication('https://testrun-1db87.firebaseio.com/', None)
sdThresh = 17
font = cv2.FONT_HERSHEY_DUPLEX

def distMap(frame1, frame2):
    frame1_32 = np.float32(frame1)
    frame2_32 = np.float32(frame2)
    diff32 = frame1_32 - frame2_32
    norm32 = np.sqrt(diff32[:,:,0]**2 + diff32[:,:,1]**2 + diff32[:,:,2]**2)/np.sqrt(255**2 + 255**2 + 255**2)
    dist = np.uint8(norm32*255)
    return dist


cap = cv2.VideoCapture(0)

_, frame1 = cap.read()
_, frame2 = cap.read()

while(True):
    _, frame3 = cap.read()
    rows, cols, _ = np.shape(frame3)
    dist = distMap(frame1, frame3)

    frame1 = frame2
    frame2 = frame3

    # apply Gaussian smoothing
    mod = cv2.GaussianBlur(dist, (9,9), 0)

    # apply thresholding
    _, thresh = cv2.threshold(mod, 100, 255, 0)
    # calculate st dev test
    _, stDev = cv2.meanStdDev(mod)

    cv2.imshow('INARA', mod)
    cv2.putText(frame2, "Standard Deviation - {}".format(round(stDev[0][0],0)), (70, 70), font, 1, (255, 0, 255), 1, cv2.LINE_AA)
    cv2.putText(frame2, "Time - {}".format(datetime.datetime.now()), (70, 100), font, 1, (255, 0, 255), 1, cv2.LINE_AA)
    if cv2.waitKey(1) & 0xFF == 27:
        break
    if stDev > sdThresh:
            print("Motion detected!!!!!",datetime.datetime.now());
            Std_dev_magnitude = stDev[0][0]
            At_time = datetime.datetime.now()
            data_to_upload = {
                'Magnitude': Std_dev_magnitude,
                'At_time': At_time
                }
            #result = FBConn.post('/Motion detected near the soldier/',data_to_upload)
    out.write(frame3.astype('uint8'))
cap.release()
cv2.destroyAllWindows()
