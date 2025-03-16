import math
import sys
from PIL import Image, ImageDraw

# Main function: This is the entry point of the program. It reads the image width and steps from the user, generates the Koch snowflake image, and saves it to a file.
def main():
    imageWidth = int(sys.stdin.readline().strip())
    steps = int(sys.stdin.readline().strip())
    image = getMain(imageWidth, steps)
    filePath = sys.stdin.readline().strip()
    try:
        image.save(filePath)
        print("Koch snowflake saved to " + filePath)
    except Exception as e:
        print("Failed to save the image: " + str(e))

# iterate Function: This function takes a list of initial vectors and the number of steps, and returns the list of vectors after the specified number of iterations.
def iterate(initialVectors, steps):
    vectors = initialVectors
    for i in range(steps):
        vectors = iterationStep(vectors)
    return vectors

# getMain Function: This function initializes the vectors for the Koch snowflake and calls the iterate function to generate the final vectors. It then calls getImage to create the image.
def getMain(imageWidth, steps):
    if imageWidth <= 0:
        raise ValueError("imageWidth should be greater than zero")
    offsetX = imageWidth / 10.0
    offsetY = imageWidth / 3.7
    vector1 = Vector2(offsetX, offsetY)
    vector2 = Vector2(imageWidth / 2.0, math.sin(math.pi / 3.0) * imageWidth * 0.8 + offsetY)
    vector3 = Vector2(imageWidth - offsetX, offsetY)
    initialVectors = [vector1, vector2, vector3, vector1]
    vectors = iterate(initialVectors, steps)
    return getImage(vectors, imageWidth, imageWidth)

# iterationStep Function: This function performs a single iteration of the Koch snowflake algorithm, generating new vectors based on the previous vectors.
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

# getImage Function: This function creates a BufferedImage and draws the Koch snowflake on it using the provided vectors.
def getImage(vectors, imageWidth, imageHeight):
    image = Image.new("RGB", (imageWidth, imageHeight), (255, 255, 255))
    draw = ImageDraw.Draw(image)
    for i in range(len(vectors) - 1):
        x1 = int(vectors[i].x)
        y1 = int(vectors[i].y)
        x2 = int(vectors[i + 1].x)
        y2 = int(vectors[i + 1].y)
        draw.line([x1, y1, x2, y2], fill=(0, 0, 0), width=1)
    return image

# Vector2 Class: This class represents a 2D vector with methods for addition, subtraction, multiplication, and rotation.
class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __str__(self):
        return "[" + str(self.x) + ", " + str(self.y) + "]"
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

if __name__ == "__main__":
    main()

