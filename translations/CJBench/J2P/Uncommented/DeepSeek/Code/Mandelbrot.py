import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.imageio.ImageIO;

public final class Main:
    def __init__(self):
        pass

    def main(self, args):
        scanner = Scanner(System.in)
        try:
            imageWidth = int(scanner.nextLine().strip())
            imageHeight = int(scanner.nextLine().strip())
            figureCenterX = float(scanner.nextLine().strip())
            figureCenterY = float(scanner.nextLine().strip())
            figureWidth = float(scanner.nextLine().strip())
            maxStep = int(scanner.nextLine().strip())
            useColorCoding = bool(scanner.nextLine().strip())
            fileName = scanner.nextLine().strip()
            image = self.getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding)
            ImageIO.write(image, "png", File(fileName))
            print("Main set image saved to " + fileName)
        except ValueError as e:
            print("Error: Please enter valid numeric values. " + str(e))
        except IOException as e:
            print("Error saving the image: " + str(e))
        except Exception as e:
            print("Error: " + str(e))
        finally:
            scanner.close()

    def getImage(self, imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useDistanceColorCoding):
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
                distance = self.getDistance(figureX, figureY, maxStep)
                image.setRGB(imageX, imageY, self.colorCodedColorMap(distance).getRGB() if useDistanceColorCoding else self.blackAndWhiteColorMap(distance).getRGB())
        return image

    def blackAndWhiteColorMap(self, distance):
        return Color(0, 0, 0) if distance >= 1 else Color(255, 255, 255)

    def colorCodedColorMap(self, distance):
        if distance >= 1:
            return Color(0, 0, 0)
        else:
            hue = 360 * distance
            saturation = 1
            val = 255
            hi = (int(math.floor(hue / 60)) % 6)
            f = hue / 60 - math.floor(hue / 60)
            v = int(val)
            p = 0
            q = int(val * (1 - f * saturation))
            t = int(val * (1 - (1 - f) * saturation))
            switch hi:
                case 0:
                    return Color(v, t, p)
                case 1:
                    return Color(q, v, p)
                case 2:
                    return Color(p, v, t)
                case 3:
                    return Color(p, q, v)
                case 4:
                    return Color(t, p, v)
                case 5:
                    return Color(v, p, q)

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

