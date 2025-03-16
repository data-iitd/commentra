import math
import sys
from PIL import Image, ImageDraw

# Define the Vector2 class to represent a 2D vector
class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"[{self.x}, {self.y}]"

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

    def rotate(self, angle_in_degrees):
        radians = angle_in_degrees * math.pi / 180
        ca = math.cos(radians)
        sa = math.sin(radians)
        x = ca * self.x - sa * self.y
        y = sa * self.x + ca * self.y
        return Vector2(x, y)

# Define the iterate function to perform a single iteration step on the vectors
def iterate(vectors):
    new_vectors = []

    # Iterate through each pair of vectors to create new segments
    for i in range(len(vectors) - 1):
        start_vector = vectors[i]
        end_vector = vectors[i + 1]
        new_vectors.append(start_vector)  # Add the starting vector

        # Calculate the difference vector and create new points for the Koch curve
        difference_vector = end_vector.subtract(start_vector).multiply(1.0 / 3)
        new_vectors.append(start_vector.add(difference_vector))  # First point
        new_vectors.append(start_vector.add(difference_vector).add(difference_vector.rotate(60)))  # Peak of the triangle
        new_vectors.append(start_vector.add(difference_vector.multiply(2)))  # Second point

    # Add the last vector to close the shape
    new_vectors.append(vectors[len(vectors) - 1])
    return new_vectors

# Define the get_main function to generate the Koch snowflake image
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
    initial_vectors = [vector1, vector2, vector3, vector1]

    # Perform iterations to generate the Koch snowflake vectors
    vectors = iterate(initial_vectors, steps)

    # Generate and return the image based on the calculated vectors
    return get_image(vectors, image_width, image_width)

# Define the get_image function to create a BufferedImage from the list of vectors
def get_image(vectors, image_width, image_height):
    # Create a new BufferedImage
    image = Image.new("RGB", (image_width, image_height), (255, 255, 255))
    draw = ImageDraw.Draw(image)

    # Set the background color and fill the image
    draw.rectangle((0, 0, image_width, image_height), fill=(255, 255, 255))

    # Set the drawing color and stroke
    draw.line((0, 0) + (0, 0), fill=(0, 0, 0), width=1)

    # Draw lines between the vectors to create the Koch snowflake
    for i in range(len(vectors) - 1):
        x1 = int(vectors[i].x)
        y1 = int(vectors[i].y)
        x2 = int(vectors[i + 1].x)
        y2 = int(vectors[i + 1].y)
        draw.line((x1, y1, x2, y2), fill=(0, 0, 0), width=1)

    return image  # Return the generated image

# Main function to read user input and generate the Koch snowflake image
def main():
    # Read the width of the image and the number of iterations for the Koch snowflake
    image_width = int(sys.stdin.readline().strip())
    steps = int(sys.stdin.readline().strip())

    # Generate the Koch snowflake image
    image = get_main(image_width, steps)

    # Read the file path to save the image
    file_path = sys.stdin.readline().strip()

    # Attempt to save the generated image to the specified file path
    try:
        image.save(file_path)
        print(f"Koch snowflake saved to {file_path}")
    except Exception as e:
        # Handle any exceptions that occur during image saving
        print(f"Failed to save the image: {e}")

if __name__ == "__main__":
    main()
