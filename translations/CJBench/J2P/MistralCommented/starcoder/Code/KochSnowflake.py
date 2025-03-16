
import math
import sys
from PIL import Image, ImageDraw

# <START-OF-CODE>

def iterate(initialVectors, steps):
    vectors = initialVectors # store the initial vectors in a local variable

    # iterate the given vectors a specified number of times
    for i in range(steps):
        vectors = iterationStep(vectors)

    # return the resulting vectors after the specified number of iteration steps
    return vectors

def iterationStep(vectors):
    newVectors = [] # create a new list to store the new vectors

    # iterate through each vector in the input list, except the last one
    for i in range(len(vectors) - 1):
        # get the current vector
        startVector = vectors[i]

        # get the next vector
        endVector = vectors[i + 1]

        # add the current vector to the new list
        newVectors.append(startVector)

        # calculate the difference vector between the current and next vectors
        differenceVector = endVector.subtract(startVector)

        # add the scaled difference vector to the current vector and add it to the new list
        newVectors.append(startVector.add(differenceVector.multiply(1.0 / 3)))

        # add the rotated difference vector to the current vector and add it to the new list
        newVectors.append(startVector.add(differenceVector.rotate(60)))

        # add the doubled difference vector to the current vector and add it to the new list
        newVectors.append(startVector.add(differenceVector.multiply(2)))

    # add the last vector to the new list
    newVectors.append(vectors[len(vectors) - 1])

    # return the new vectors after this iteration step
    return newVectors

def getMain(imageWidth, steps):
    if imageWidth <= 0: # check if the image width is valid
        raise ValueError("imageWidth should be greater than zero")

    # calculate offsetX and offsetY based on the image width
    offsetX = imageWidth / 10.0
    offsetY = imageWidth / 3.7

    # create the first three vectors
    vector1 = Vector2(offsetX, offsetY)
    vector2 = Vector2(imageWidth / 2.0, math.sin(math.pi / 3.0) * imageWidth * 0.8 + offsetY)
    vector3 = Vector2(imageWidth - offsetX, offsetY)

    # create an list to store the initial vectors
    initialVectors = []
    initialVectors.append(vector1)
    initialVectors.append(vector2)
    initialVectors.append(vector3)
    initialVectors.append(vector1)

    # iterate the vectors to generate the Koch snowflake
    vectors = iterate(initialVectors, steps)

    # generate the image of the Koch snowflake
    return getImage(vectors, imageWidth, imageWidth)

def getImage(vectors, imageWidth, imageHeight):
    image = Image.new("RGB", (imageWidth, imageHeight), (255, 255, 255)) # create a new image

    draw = ImageDraw.Draw(image) # create a ImageDraw object to draw on the image

    draw.rectangle((0, 0, imageWidth, imageHeight), fill=(255, 255, 255)) # fill the entire image with the background color

    draw.line((0, 0) + vectors[0], fill=(0, 0, 0), width=1) # draw a line between the first and second vector
    draw.line((vectors[0], vectors[1], vectors[2], vectors[3]), fill=(0, 0, 0), width=1) # draw a line between the second and third vector
    draw.line((vectors[3], vectors[4], vectors[5], vectors[6]), fill=(0, 0, 0), width=1) # draw a line between the third and fourth vector
    draw.line((vectors[6], vectors[7], vectors[8], vectors[9]), fill=(0, 0, 0), width=1) # draw a line between the fourth and first vector

    return image # return the image of the Koch snowflake

class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "[%f, %f]" % (self.x, self.y)

    def add(self, vector):
        x = self.x + vector.x
        y = self.y + vector.y
        return Vector2(x, y)

    def subtract(self, vector):
        x = self.x - vector.x
        y = self.y - vector.y
        return Vector2(x, y)

    def multiply(self, scalar):
        x = self.x * scalar
        y = self.y * scalar
        return Vector2(x, y)

    def rotate(self, angleInDegrees):
        radians = angleInDegrees * math.pi / 180
        ca = math.cos(radians)
        sa = math.sin(radians)
        x = ca * self.x - sa * self.y
        y = sa * self.x + ca * self.y
        return Vector2(x, y)

# 