import java
import java.awt.BasicStroke
import java.awt.Color
import java.awt.Graphics2D
import java.awt.image.BufferedImage
import java.io.File
import java.io.IOException
import java.util.ArrayList
import java.util.List
import java.util.Scanner
import javax.imageio.ImageIO

class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    @staticmethod
    def main(args):
        # Create a scanner to read user input
        scanner = Scanner(System.in)
        
        # Read the width of the image and the number of iterations for the Koch snowflake
        image_width = scanner.nextInt()
        steps = scanner.nextInt()
        
        # Generate the Koch snowflake image
        image = Main.get_main(image_width, steps)
        
        # Read the file path to save the image
        file_path = scanner.next()
        
        # Attempt to save the generated image to the specified file path
        try:
            ImageIO.write(image, "png", File(file_path))
            print("Koch snowflake saved to " + file_path)
        except IOException as e:
            # Handle any exceptions that occur during image saving
            print("Failed to save the image: " + str(e))
        
        # Close the scanner to free resources
        scanner.close()

    # Method to perform the iteration steps for generating the Koch snowflake
    @staticmethod
    def iterate(initial_vectors, steps):
        vectors = initial_vectors
        
        # Perform the specified number of iteration steps
        for i in range(steps):
            vectors = Main.iteration_step(vectors)
        
        return vectors

    # Method to initialize the Koch snowflake and generate the image
    @staticmethod
    def get_main(image_width, steps):
        # Validate the image width
        if image_width <= 0:
            raise ValueError("image_width should be greater than zero")
        
        # Calculate offsets for positioning the snowflake
        offset_x = image_width / 10.0
        offset_y = image_width / 3.7
        
        # Define the initial vertices of the Koch snowflake
        vector1 = Vector2(offset_x, offset_y)
        vector2 = Vector2(image_width / 2.0, math.sin(math.pi / 3.0) * image_width * 0.8 + offset_y)
        vector3 = Vector2(image_width - offset_x, offset_y)
        
        # Create a list to hold the initial vectors
        initial_vectors = [vector1, vector2, vector3, vector1] # Closing the shape
        
        # Perform iterations to generate the Koch snowflake vectors
        vectors = Main.iterate(initial_vectors, steps)
        
        # Generate and return the image based on the calculated vectors
        return Main.get_image(vectors, image_width, image_width)

    # Method to perform a single iteration step on the vectors
    @staticmethod
    def iteration_step(vectors):
        new_vectors = []
        
        # Iterate through each pair of vectors to create new segments
        for i in range(len(vectors) - 1):
            start_vector = vectors[i]
            end_vector = vectors[i + 1]
            new_vectors.append(start_vector) # Add the starting vector
            
            # Calculate the difference vector and create new points for the Koch curve
            difference_vector = end_vector.subtract(start_vector).multiply(1.0 / 3)
            new_vectors.append(start_vector.add(difference_vector)) # First point
            new_vectors.append(start_vector.add(difference_vector).add(difference_vector.rotate(60))) # Peak of the triangle
            new_vectors.append(start_vector.add(difference_vector.multiply(2))) # Second point
        
        # Add the last vector to close the shape
        new_vectors.append(vectors[-1])
        return new_vectors

    # Method to create a BufferedImage from the list of vectors
    @staticmethod
    def get_image(vectors, image_width, image_height):
        # Create a new BufferedImage
        image = BufferedImage(image_width, image_height, BufferedImage.TYPE_INT_RGB)
        g2d = image.createGraphics()
        
        # Set the background color and fill the image
        g2d.setBackground(Color.WHITE)
        g2d.fillRect(0, 0, image_width, image_height)
        
        # Set the drawing color and stroke
        g2d.setColor(Color.BLACK)
        bs = BasicStroke(1)
        g2d.setStroke(bs)
        
        # Draw lines between the vectors to create the Koch snowflake
        for i in range(len(vectors) - 1):
            x1 = int(vectors[i].x)
            y1 = int(vectors[i].y)
            x2 = int(vectors[i + 1].x)
            y2 = int(vectors[i + 1].y)
            g2d.drawLine(x1, y1, x2, y2)
        
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
    def rotate(self, angle_in_degrees):
        radians = angle_in_degrees * math.pi / 180
        ca = math.cos(radians)
        sa = math.sin(radians)
        x = ca * self.x - sa * self.y
        y = sa * self.x + ca * self.y
        return Vector2(x, y)

# Execute the main method if the script is run directly
if __name__ == "__main__":
    Main.main([])
