import math
import sys
from PIL import Image

# Main function to generate the image
def main():
    # Read image dimensions and figure parameters from user input
    imageWidth = int(input().strip())
    imageHeight = int(input().strip())
    figureCenterX = float(input().strip())
    figureCenterY = float(input().strip())
    figureWidth = float(input().strip())
    maxStep = int(input().strip())
    useColorCoding = bool(input().strip())
    fileName = input().strip()

    # Generate the image based on the provided parameters
    image = getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding)

    # Save the generated image to the specified file
    image.save(fileName)
    print("Main set image saved to " + fileName)

# Method to generate a black and white color map based on distance
def blackAndWhiteColorMap(distance):
    if distance >= 1:
        return (0, 0, 0) # Black for distances >= 1
    else:
        return (255, 255, 255) # White for distances < 1

# Method to generate a color-coded color map based on distance
def colorCodedColorMap(distance):
    if distance >= 1:
        return (0, 0, 0) # Black for distances >= 1
    else:
        # Calculate hue, saturation, and value for color coding
        hue = 360 * distance
        saturation = 1
        val = 255
        hi = int(math.floor(hue / 60)) % 6
        f = hue / 60 - math.floor(hue / 60)
        v = int(val)
        p = 0
        q = int(val * (1 - f * saturation))
        t = int(val * (1 - (1 - f) * saturation))

        # Determine the RGB color based on the hue
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

# Method to calculate the distance for the given figure coordinates
def getDistance(figureX, figureY, maxStep):
    a = figureX
    b = figureY
    currentStep = 0

    # Iterate to determine the escape time for the point
    for step in range(maxStep):
        currentStep = step
        aNew = a * a - b * b + figureX # Update a based on the Main formula
        b = 2 * a * b + figureY # Update b based on the Main formula
        a = aNew

        # Check if the point escapes the boundary
        if a * a + b * b > 4:
            break # Exit if the point escapes

    return currentStep / (maxStep - 1) # Return normalized distance

# Method to generate the image based on the provided parameters
def getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding):
    # Validate input parameters for image dimensions and max steps
    if imageWidth <= 0:
        raise ValueError("imageWidth should be greater than zero")
    if imageHeight <= 0:
        raise ValueError("imageHeight should be greater than zero")
    if maxStep <= 0:
        raise ValueError("maxStep should be greater than zero")

    # Create a new image to hold the generated image
    image = Image.new("RGB", (imageWidth, imageHeight))
    figureHeight = figureWidth / imageWidth * imageHeight # Calculate figure height based on aspect ratio

    # Loop through each pixel in the image
    for imageX in range(imageWidth):
        for imageY in range(imageHeight):
            # Calculate the corresponding figure coordinates for the current pixel
            figureX = figureCenterX + ((imageX / imageWidth - 0.5) * figureWidth)
            figureY = figureCenterY + ((imageY / imageHeight - 0.5) * figureHeight)

            # Calculate the distance for color mapping
            distance = getDistance(figureX, figureY, maxStep)

            # Set the pixel color based on the distance and color coding preference
            image.putpixel((imageX, imageY), useColorCoding and colorCodedColorMap(distance) or blackAndWhiteColorMap(distance))

    return image # Return the generated image

# Call the main function to start the program
if __name__ == "__main__":
    main()

