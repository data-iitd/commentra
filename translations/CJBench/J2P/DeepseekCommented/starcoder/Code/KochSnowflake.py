import math
import sys
from PIL import Image, ImageDraw

class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"[{self.x}, {self.y}]"

    def add(self, vector):
        return Vector2(self.x + vector.x, self.y + vector.y)

    def subtract(self, vector):
        return Vector2(self.x - vector.x, self.y - vector.y)

    def multiply(self, scalar):
        return Vector2(self.x * scalar, self.y * scalar)

    def rotate(self, angleInDegrees):
        radians = angleInDegrees * math.pi / 180
        ca = math.cos(radians)
        sa = math.sin(radians)
        return Vector2(ca * self.x - sa * self.y, sa * self.x + ca * self.y)

def iterate(initialVectors, steps):
    vectors = initialVectors
    for i in range(steps):
        vectors = iterationStep(vectors)
    return vectors

def iterationStep(vectors):
    newVectors = []
    for i in range(len(vectors) - 1):
        startVector = vectors[i]
        endVector = vectors[i + 1]
        newVectors.append(startVector)
        differenceVector = endVector.subtract(startVector).multiply(1.0 / 3)
        newVectors.append(startVector.add(differenceVector))
        newVectors.append(startVector.add(differenceVector).add(differenceVector.rotate(60)))
        newVectors.append(startVector.add(differenceVector.multiply(2)))
    newVectors.append(vectors[len(vectors) - 1])
    return newVectors

def getImage(vectors, imageWidth, imageHeight):
    image = Image.new("RGB", (imageWidth, imageHeight), (255, 255, 255))
    draw = ImageDraw.Draw(image)
    for i in range(len(vectors) - 1):
        x1 = int(vectors[i].x)
        y1 = int(vectors[i].y)
        x2 = int(vectors[i + 1].x)
        y2 = int(vectors[i + 1].y)
        draw.line((x1, y1, x2, y2), fill=(0, 0, 0))
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

def main():
    if len(sys.argv)!= 3:
        print("Usage: python3 main.py <imageWidth> <steps>")
        return
    imageWidth = int(sys.argv[1])
    steps = int(sys.argv[2])
    image = getMain(imageWidth, steps)
    image.save("output.png")
    print("Koch snowflake saved to output.png")

if __name__ == "__main__":
    main()

# 