import java
from java.awt import Color
from java.awt.image import BufferedImage
import java.io
import java.util.Scanner

class Main:
    def __init__(self):
        pass  # Private constructor to prevent instantiation of the utility class

    def main(self, args):
        scanner = Scanner(System.in)
        try:
            imageWidth = int(scanner.nextLine().trim())  # Read image width
            imageHeight = int(scanner.nextLine().trim())  # Read image height
            figureCenterX = float(scanner.nextLine().trim())  # Read figure center X
            figureCenterY = float(scanner.nextLine().trim())  # Read figure center Y
            figureWidth = float(scanner.nextLine().trim())  # Read figure width
            maxStep = int(scanner.nextLine().trim())  # Read maximum steps
            useColorCoding = bool(scanner.nextLine().trim())  # Read color coding flag
            fileName = scanner.nextLine().trim()  # Read file name
            image = self.getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding)  # Generate image
            java.io.ImageIO.write(image, "png", java.io.File(fileName))  # Save image to file
            print("Main set image saved to " + fileName)  # Confirmation message
        except ValueError as e:
            print("Error: Please enter valid numeric values. " + str(e))  # Handle invalid numeric input
        except java.io.IOException as e:
            print("Error saving the image: " + str(e))  # Handle I/O errors
        except Exception as e:
            print("Error: " + str(e))  # Handle other exceptions
        finally:
            scanner.close()  # Close the scanner

    def getImage(self, imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useDistanceColorCoding):
        if imageWidth <= 0:
            raise ValueError("imageWidth should be greater than zero")  # Validate image width
        if imageHeight <= 0:
            raise ValueError("imageHeight should be greater than zero")  # Validate image height
        if maxStep <= 0:
            raise ValueError("maxStep should be greater than zero")  # Validate maximum steps
        image = BufferedImage(imageWidth, imageHeight, BufferedImage.TYPE_INT_RGB)  # Create image
        figureHeight = figureWidth / imageWidth * imageHeight  # Calculate figure height
        for imageX in range(imageWidth):
            for imageY in range(imageHeight):
                figureX = figureCenterX + ((imageX / imageWidth - 0.5) * figureWidth)  # Calculate figure X
                figureY = figureCenterY + ((imageY / imageHeight - 0.5) * figureHeight)  # Calculate figure Y
                distance = self.getDistance(figureX, figureY, maxStep)  # Get distance
                if useDistanceColorCoding:
                    image.setRGB(imageX, imageY, self.colorCodedColorMap(distance).getRGB())  # Set pixel color
                else:
                    image.setRGB(imageX, imageY, self.blackAndWhiteColorMap(distance).getRGB())  # Set pixel color
        return image  # Return generated image

    def blackAndWhiteColorMap(self, distance):
        return Color(0, 0, 0) if distance >= 1 else Color(255, 255, 255)  # Return black or white based on distance

    def colorCodedColorMap(self, distance):
        if distance >= 1:
            return Color(0, 0, 0)  # Return black for distance >= 1
        else:
            hue = 360 * distance  # Calculate hue based on distance
            hi = int(math.floor(hue / 60)) % 6
            f = hue / 60 - math.floor(hue / 60)
            v = 255
            p = 0
            q = int(v * (1 - f * saturation))
            t = int(v * (1 - (1 - f) * saturation))
            switch hi:
                case 0:
                    return Color(v, t, p)  # Return color based on hue
                case 1:
                    return Color(q, v, p)
                case 2:
                    return Color(p, v, t)
                case 3:
                    return Color(p, q, v)
                case 4:
                    return Color(t, p, v)
                default:
                    return Color(v, p, q)

    def getDistance(self, figureX, figureY, maxStep):
        a = figureX
        b = figureY
        currentStep = 0
        for step in range(maxStep):
            currentStep = step
            aNew = a * a - b * b + figureX  # Update a
            b = 2 * a * b + figureY  # Update b
            a = aNew
            if a * a + b * b > 4:
                break  # Break if magnitude exceeds 2
        return currentStep / (maxStep - 1)  # Return current step as fraction of maxStep

# Create an instance of the Main class and call the main method
Main().main([])
