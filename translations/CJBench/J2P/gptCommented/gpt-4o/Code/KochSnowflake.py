import numpy as np
import matplotlib.pyplot as plt

class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"[{self.x}, {self.y}]"

    def add(self, vector):
        return Vector2(self.x + vector.x, self.y + vector.y)

    def subtract(self, vector):
        return Vector2(self.x - vector.x, self.y - vector.y)

    def multiply(self, scalar):
        return Vector2(self.x * scalar, self.y * scalar)

    def rotate(self, angle_in_degrees):
        radians = np.radians(angle_in_degrees)
        ca = np.cos(radians)
        sa = np.sin(radians)
        return Vector2(ca * self.x - sa * self.y, sa * self.x + ca * self.y)

def iterate(initial_vectors, steps):
    vectors = initial_vectors
    for _ in range(steps):
        vectors = iteration_step(vectors)
    return vectors

def iteration_step(vectors):
    new_vectors = []
    for i in range(len(vectors) - 1):
        start_vector = vectors[i]
        end_vector = vectors[i + 1]
        new_vectors.append(start_vector)

        difference_vector = end_vector.subtract(start_vector).multiply(1.0 / 3)
        new_vectors.append(start_vector.add(difference_vector))  # First point
        new_vectors.append(start_vector.add(difference_vector).add(difference_vector.rotate(60)))  # Peak of the triangle
        new_vectors.append(start_vector.add(difference_vector.multiply(2)))  # Second point

    new_vectors.append(vectors[-1])  # Add the last vector to close the shape
    return new_vectors

def get_main(image_width, steps):
    if image_width <= 0:
        raise ValueError("imageWidth should be greater than zero")

    offset_x = image_width / 10.0
    offset_y = image_width / 3.7

    vector1 = Vector2(offset_x, offset_y)
    vector2 = Vector2(image_width / 2.0, np.sin(np.pi / 3.0) * image_width * 0.8 + offset_y)
    vector3 = Vector2(image_width - offset_x, offset_y)

    initial_vectors = [vector1, vector2, vector3, vector1]  # Closing the shape
    vectors = iterate(initial_vectors, steps)

    return get_image(vectors, image_width, image_width)

def get_image(vectors, image_width, image_height):
    plt.figure(figsize=(image_width / 100, image_height / 100), dpi=100)
    plt.xlim(0, image_width)
    plt.ylim(0, image_height)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.axis('off')  # Turn off the axis

    for i in range(len(vectors) - 1):
        x1, y1 = vectors[i].x, vectors[i].y
        x2, y2 = vectors[i + 1].x, vectors[i + 1].y
        plt.plot([x1, x2], [y1, y2], color='black')

    plt.gca().set_facecolor('white')
    plt.show()

if __name__ == "__main__":
    image_width = int(input("Enter image width: "))
    steps = int(input("Enter number of iterations: "))
    file_path = input("Enter file path to save the image: ")

    image = get_main(image_width, steps)
    # Save the figure to a file
    plt.savefig(file_path, bbox_inches='tight', pad_inches=0)
    print(f"Koch snowflake saved to {file_path}")

# <END-OF-CODE>
