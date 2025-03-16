
import math
import sys
from PIL import Image, ImageDraw

# Main method to start the program
def main():
    # Read input parameters from the user
    imageWidth = int(input().strip())
    imageHeight = int(input().strip())
    figureCenterX = float(input().strip())
    figureCenterY = float(input().strip())
    figureWidth = float(input().strip())
    maxStep = int(input().strip())
    useColorCoding = input().strip().lower() == "true"
    fileName = input().strip()

    # Create an image with the given dimensions
    image = getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding)

    # Save the image to a file
    image.save(fileName)
    print("Main: Image saved to " + fileName)

# Method to create the image based on the input parameters
def getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useDistanceColorCoding):
    if imageWidth <= 0:
        raise ValueError("imageWidth should be greater than zero")

    if imageHeight <= 0:
        raise ValueError("imageHeight should be greater than zero")

    if maxStep <= 0:
        raise ValueError("maxStep should be greater than zero")

    # Initialize the image with the given dimensions and color type
    image = Image.new("RGB", (imageWidth, imageHeight))
    draw = ImageDraw.Draw(image)

    figureHeight = figureWidth / imageWidth * imageHeight

    # Iterate through each pixel in the image and calculate its color based on the figure's position and distance
    for imageX in range(imageWidth):
        for imageY in range(imageHeight):
            figureX = figureCenterX + ((imageX / imageWidth - 0.5) * figureWidth)
            figureY = figureCenterY + ((imageY / imageHeight - 0.5) * figureHeight)
            distance = getDistance(figureX, figureY, maxStep)

            # Set the pixel's color based on the useDistanceColorCoding flag
            if useDistanceColorCoding:
                draw.point((imageX, imageY), colorCodedColorMap(distance))
            else:
                draw.point((imageX, imageY), blackAndWhiteColorMap(distance))

    return image

# Method to calculate the color based on the distance for color-coded images
def colorCodedColorMap(distance):
    if distance >= 1:
        return (0, 0, 0)
    else:
        hue = 360 * distance
        saturation = 1
        val = 255
        hi = int(math.floor(hue / 60)) % 6
        f = hue / 60 - math.floor(hue / 60)
        v = int(val)
        p = 0
        q = int(val * (1 - f * saturation))
        t = int(val * (1 - (1 - f) * saturation))

        # Determine the RGB values based on the HSL color space
        if hi == 0:
            return (v, t, p)
        elif hi == 1:
            return (q, v, p)
        elif hi == 2:
            return (p, v, t)
        elif hi == 3:
            return (p, q, v)
        elif hi == 4:
            return (t, p, v)
        else:
            return (v, p, q)

# Method to calculate the distance between the figure and the pixel
def getDistance(figureX, figureY, maxStep):
    a = figureX
    b = figureY
    currentStep = 0

    # Iterate through each step in the Main set calculation
    for step in range(maxStep):
        currentStep = step
        aNew = a * a - b * b + figureX
        b = 2 * a * b + figureY
        a = aNew

        # If the distance exceeds a certain threshold, break the loop
        if a * a + b * b > 4:
            break

    # Return the number of iterations as the distance
    return currentStep / (maxStep - 1)

# Method to calculate the black-and-white color based on the distance
def blackAndWhiteColorMap(distance):
    return (0, 0, 0) if distance >= 1 else (255, 255, 255)

# Main method to start the program
if __name__ == "__main__":
    try:
        main()
    except ValueError as e:
        print("Error: " + e.args[0])
    except IOError as e:
        print("Error saving the image: " + e.args[0])

# 