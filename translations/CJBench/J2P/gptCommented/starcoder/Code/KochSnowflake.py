import math
import sys
from PIL import Image, ImageDraw

# Private constructor to prevent instantiation
class Main:
    def __init__(self):
        pass

    # Method to perform the iteration steps for generating the Koch snowflake
    def iterate(self, initialVectors, steps):
        vectors = initialVectors
        
        # Perform the specified number of iteration steps
        for i in range(steps):
            vectors = self.iterationStep(vectors)
        
        return vectors

    # Method to initialize the Koch snowflake and generate the image
    def getMain(self, imageWidth, steps):
        # Validate the image width
        if imageWidth <= 0:
            raise Exception("imageWidth should be greater than zero")
        
        # Calculate offsets for positioning the snowflake
        offsetX = imageWidth / 10.0
        offsetY = imageWidth / 3.7
        
        # Define the initial vertices of the Koch snowflake
        vector1 = Vector2(offsetX, offsetY)
        vector2 = Vector2(imageWidth / 2.0, math.sin(math.pi / 3.0) * imageWidth * 0.8 + offsetY)
        vector3 = Vector2(imageWidth - offsetX, offsetY)
        
        # Create a list to hold the initial vectors
        initialVectors = []
        initialVectors.append(vector1)
        initialVectors.append(vector2)
        initialVectors.append(vector3)
        initialVectors.append(vector1) # Closing the shape
        
        # Perform iterations to generate the Koch snowflake vectors
        vectors = self.iterate(initialVectors, steps)
        
        # Generate and return the image based on the calculated vectors
        return self.getImage(vectors, imageWidth, imageWidth)

    # Method to perform a single iteration step on the vectors
    def iterationStep(self, vectors):
        newVectors = []
        
        # Iterate through each pair of vectors to create new segments
        for i in range(len(vectors) - 1):
            startVector = vectors[i]
            endVector = vectors[i + 1]
            newVectors.append(startVector) # Add the starting vector
            
            # Calculate the difference vector and create new points for the Koch curve
            differenceVector = endVector.subtract(startVector).multiply(1.0 / 3)
            newVectors.append(startVector.add(differenceVector)) # First point
            newVectors.append(startVector.add(differenceVector).add(differenceVector.rotate(60))) # Peak of the triangle
            newVectors.append(startVector.add(differenceVector.multiply(2))) # Second point
        
        # Add the last vector to close the shape
        newVectors.append(vectors[len(vectors) - 1])
        return newVectors

    # Method to create a BufferedImage from the list of vectors
    def getImage(self, vectors, imageWidth, imageHeight):
        # Create a new BufferedImage
        image = Image.new("RGB", (imageWidth, imageHeight), (255, 255, 255))
        draw = ImageDraw.Draw(image)
        
        # Set the drawing color and stroke
        draw.line((0, 0) + (imageWidth, imageHeight), fill=(0, 0, 0), width=1)
        
        # Draw lines between the vectors to create the Koch snowflake
        for i in range(len(vectors) - 1):
            x1 = vectors[i].x
            y1 = vectors[i].y
            x2 = vectors[i + 1].x
            y2 = vectors[i + 1].y
            draw.line((x1, y1, x2, y2), fill=(0, 0, 0), width=1)
        
        return image # Return the generated image

    # Inner class to represent a 2D vector
    class Vector2:
        def __init__(self, x, y):
            self.x = x
            self.y = y

        # Override toString method for easy debugging
        def __str__(self):
            return "[%f, %f]" % (self.x, self.y)

        # Method to add another vector to this vector
        def add(self, vector):
            x = self.x + vector.x
            y = self.y + vector.y
            return Vector2(x, y)

        # Method to subtract another vector from this vector
        def subtract(self, vector):
            x = self.x - vector.x
            y = self.y - vector.y
            return Vector2(x, y)

        # Method to multiply this vector by a scalar
        def multiply(self, scalar):
            x = self.x * scalar
            y = self.y * scalar
            return Vector2(x, y)

        # Method to rotate this vector by a given angle in degrees
        def rotate(self, angleInDegrees):
            radians = angleInDegrees * math.pi / 180
            ca = math.cos(radians)
            sa = math.sin(radians)
            x = ca * self.x - sa * self.y
            y = sa * self.x + ca * self.y
            return Vector2(x, y)

# Main entry point
if __name__ == "__main__":
    # Create a scanner to read user input
    scanner = sys.stdin
    
    # Read the width of the image and the number of iterations for the Koch snowflake
    imageWidth = int(scanner.readline())
    steps = int(scanner.readline())
    
    # Generate the Koch snowflake image
    image = Main().getMain(imageWidth, steps)
    
    # Read the file path to save the image
    filePath = scanner.readline()
    
    # Attempt to save the generated image to the specified file path
    try:
        image.save(filePath)
        print("Koch snowflake saved to " + filePath)
    except Exception as e:
        # Handle any exceptions that occur during image saving
        print("Failed to save the image: " + str(e))
    
    # Close the scanner to free resources
    scanner.close()

