import numpy as np
import cv2

def main():
    img = cv2.imread('Hide-the-Pain-Harold.jpg')
    img = img + 100
    cv2.imshow('image', img)
    cv2.waitKey(0)

if __name__ == '__main__':
    main()
