
import math
import sys
import numpy as np
import matplotlib.pyplot as plt

class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "[{}, {}]".format(self.x, self.y)

    def __add__(self, other):
        return Vector2(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector2(self.x - other.x, self.y - other.y)

    def __mul__(self, scalar):
        return Vector2(self.x * scalar, self.y * scalar)

    def rotate(self, angleInDegrees):
        radians = angleInDegrees * math.pi / 180
        ca = math.cos(radians)
        sa = math.sin(radians)
        x = ca * self.x - sa * self.y
        y = sa * self.x + ca * self.y
        return Vector2(x, y)

def iterate(vectors, steps):
    for i in range(steps):
        vectors = iterationStep(vectors)
    return vectors

def iterationStep(vectors):
    newVectors = []
    for i in range(len(vectors) - 1):
        startVector = vectors[i]
        endVector = vectors[i + 1]
        newVectors.append(startVector)
        differenceVector = (endVector - startVector) * 1.0 / 3
        newVectors.append(startVector + differenceVector)
        newVectors.append(startVector + differenceVector + differenceVector.rotate(60))
        newVectors.append(startVector + differenceVector * 2)
    newVectors.append(vectors[-1])
    return newVectors

def getImage(vectors, imageWidth, imageHeight):
    image = np.zeros((imageHeight, imageWidth, 3), dtype=np.uint8)
    image[:, :] = 255
    for i in range(len(vectors) - 1):
        x1 = int(vectors[i].x)
        y1 = int(vectors[i].y)
        x2 = int(vectors[i + 1].x)
        y2 = int(vectors[i + 1].y)
        image = cv2.line(image, (x1, y1), (x2, y2), (0, 0, 0), 1)
    return image

def getMain(imageWidth, steps):
    if imageWidth <= 0:
        raise Exception("imageWidth should be greater than zero")
    offsetX = imageWidth / 10.0
    offsetY = imageWidth / 3.7
    vector1 = Vector2(offsetX, offsetY)
    vector2 = Vector2(imageWidth / 2.0, math.sin(math.pi / 3.0) * imageWidth * 0.8 + offsetY)
    vector3 = Vector2(imageWidth - offsetX, offsetY)
    initialVectors = [vector1, vector2, vector3, vector1]
    vectors = iterate(initialVectors, steps)
    return getImage(vectors, imageWidth, imageWidth)

if __name__ == "__main__":
    imageWidth = int(sys.argv[1])
    steps = int(sys.argv[2])
    image = getMain(imageWidth, steps)
    plt.imshow(image)
    plt.show()

