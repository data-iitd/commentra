import java.awt.Color
import java.awt.image.BufferedImage
import java.io.File
import java.io.IOException
import java.util.Scanner
import javax.imageio.ImageIO

class Main:
    def __init__(self):
        pass

    # Main method to start the program
    def main(self, args):
        scanner = Scanner(System.in)

        try:
            # Read input parameters from the user
            imageWidth = int(scanner.nextLine().trim())
            imageHeight = int(scanner.nextLine().trim())
            figureCenterX = float(scanner.nextLine().trim())
            figureCenterY = float(scanner.nextLine().trim())
            figureWidth = float(scanner.nextLine().trim())
            maxStep = int(scanner.nextLine().trim())
            useColorCoding = bool(scanner.nextLine().trim())
            fileName = scanner.nextLine().trim()

            # Create an image with the given dimensions
            image = self.getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding)

            # Save the image to a file
            ImageIO.write(image, "png", File(fileName))
            print("Main: Image saved to " + fileName)
        except ValueError as e:
            print("Error: Please enter valid numeric values. " + str(e))
        except IOException as e:
            print("Error saving the image: " + str(e))
        except Exception as e:
            print("Error: " + str(e))
        finally:
            scanner.close()

    # Method to create the image based on the input parameters
    def getImage(self, imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useDistanceColorCoding):
        if imageWidth <= 0:
            raise ValueError("imageWidth should be greater than zero")

        if imageHeight <= 0:
            raise ValueError("imageHeight should be greater than zero")

        if maxStep <= 0:
            raise ValueError("maxStep should be greater than zero")

        # Initialize the image with the given dimensions and color type
        image = BufferedImage(imageWidth, imageHeight, BufferedImage.TYPE_INT_RGB)

        figureHeight = figureWidth / imageWidth * imageHeight

        # Iterate through each pixel in the image and calculate its color based on the figure's position and distance
        for imageX in range(imageWidth):
            for imageY in range(imageHeight):
                figureX = figureCenterX + ((imageX / imageWidth - 0.5) * figureWidth)
                figureY = figureCenterY + ((imageY / imageHeight - 0.5) * figureHeight)
                distance = self.getDistance(figureX, figureY, maxStep)

                # Set the pixel's color based on the useDistanceColorCoding flag
                if useDistanceColorCoding:
                    image.setRGB(imageX, imageY, self.colorCodedColorMap(distance).getRGB())
                else:
                    image.setRGB(imageX, imageY, self.blackAndWhiteColorMap(distance).getRGB())

        return image

    # Method to calculate the color based on the distance for color-coded images
    def colorCodedColorMap(self, distance):
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

            # Determine the RGB values based on the HSL color space
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
                default:
                    return Color(v, p, q)

    # Method to calculate the distance between the figure and the pixel
    def getDistance(self, figureX, figureY, maxStep):
        a = figureX
        b = figureY
        currentStep = 0

        # Iterate through each step in the Mandelbrot set calculation
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
    def blackAndWhiteColorMap(self, distance):
        return Color(0, 0, 0) if distance >= 1 else Color(255, 255, 255)

# Create an instance of the Main class and call the main method
main = Main()
main.main([])
