
import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.imageio.ImageIO;
def getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useDistanceColorCoding):
    if imageWidth <= 0:
        raise ValueError("imageWidth should be greater than zero")
    if imageHeight <= 0:
        raise ValueError("imageHeight should be greater than zero")
    if maxStep <= 0:
        raise ValueError("maxStep should be greater than zero")
    image = BufferedImage(imageWidth, imageHeight, BufferedImage.TYPE_INT_RGB)
    figureHeight = figureWidth / imageWidth * imageHeight
    for imageX in range(imageWidth):
        for imageY in range(imageHeight):
            figureX = figureCenterX + ((imageX / imageWidth - 0.5) * figureWidth)
            figureY = figureCenterY + ((imageY / imageHeight - 0.5) * figureHeight)
            distance = getDistance(figureX, figureY, maxStep)
            image.setRGB(imageX, imageY, useDistanceColorCoding? colorCodedColorMap(distance).getRGB() : blackAndWhiteColorMap(distance).getRGB())
    return image
def blackAndWhiteColorMap(distance):
    return distance >= 1 and Color(0, 0, 0) or Color(255, 255, 255)
def colorCodedColorMap(distance):
    if distance >= 1:
        return Color(0, 0, 0)
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
            return Color(v, t, p)
        elif hi == 1:
            return Color(q, v, p)
        elif hi == 2:
            return Color(p, v, t)
        elif hi == 3:
            return Color(p, q, v)
        elif hi == 4:
            return Color(t, p, v)
        else:
            return Color(v, p, q)
def getDistance(figureX, figureY, maxStep):
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
def main():
    scanner = Scanner(System.in)
    try:
        imageWidth = int(scanner.nextLine().trim())
        imageHeight = int(scanner.nextLine().trim())
        figureCenterX = float(scanner.nextLine().trim())
        figureCenterY = float(scanner.nextLine().trim())
        figureWidth = float(scanner.nextLine().trim())
        maxStep = int(scanner.nextLine().trim())
        useDistanceColorCoding = bool(scanner.nextLine().trim())
        fileName = scanner.nextLine().trim()
        image = getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useDistanceColorCoding)
        ImageIO.write(image, "png", File(fileName))
        print("Main set image saved to " + fileName)
    except ValueError as e:
        print("Error: Please enter valid numeric values. " + e.getMessage())
    except IOException as e:
        print("Error saving the image: " + e.getMessage())
    except ValueError as e:
        print("Error: " + e.getMessage())
    finally:
        scanner.close()
if __name__ == "__main__":
    main()
