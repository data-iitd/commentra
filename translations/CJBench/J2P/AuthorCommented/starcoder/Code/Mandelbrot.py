
import math
import sys
from PIL import Image, ImageDraw

class Main:
    def __init__(self):
        pass

    def main(self):
        try:
            imageWidth = int(input().strip())
            imageHeight = int(input().strip())
            figureCenterX = float(input().strip())
            figureCenterY = float(input().strip())
            figureWidth = float(input().strip())
            maxStep = int(input().strip())
            useColorCoding = bool(input().strip())
            fileName = input().strip()

            image = self.getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding)
            image.save(fileName)
            print("Main set image saved to " + fileName)
        except ValueError as e:
            print("Error: Please enter valid numeric values. " + e.args[0])
        except IOError as e:
            print("Error saving the image: " + e.args[0])
        except Exception as e:
            print("Error: " + e.args[0])

    def getImage(self, imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding):
        if imageWidth <= 0:
            raise ValueError("imageWidth should be greater than zero")

        if imageHeight <= 0:
            raise ValueError("imageHeight should be greater than zero")

        if maxStep <= 0:
            raise ValueError("maxStep should be greater than zero")

        image = Image.new("RGB", (imageWidth, imageHeight))
        figureHeight = figureWidth / imageWidth * imageHeight

        for imageX in range(imageWidth):
            for imageY in range(imageHeight):
                figureX = figureCenterX + ((imageX / imageWidth - 0.5) * figureWidth)
                figureY = figureCenterY + ((imageY / imageHeight - 0.5) * figureHeight)

                distance = self.getDistance(figureX, figureY, maxStep)

                image.putpixel((imageX, imageY), self.colorCodedColorMap(distance) if useColorCoding else self.blackAndWhiteColorMap(distance))

        return image

    def blackAndWhiteColorMap(self, distance):
        return (0, 0, 0) if distance >= 1 else (255, 255, 255)

    def colorCodedColorMap(self, distance):
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

    def getDistance(self, figureX, figureY, maxStep):
        a = figureX
        b = figureY
        currentStep = 0
        for step in range(maxStep):
            currentStep = step
            aNew = a * a - b * b + figureX
            b = 2 * a * b + figureY
            a = aNew

            if a * a + b * b > 4:
                break

        return currentStep / (maxStep - 1)

if __name__ == "__main__":
    Main().main()

