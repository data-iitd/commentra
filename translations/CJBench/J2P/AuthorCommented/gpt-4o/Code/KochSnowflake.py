import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"[{self.x:.6f}, {self.y:.6f}]"

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
        x = ca * self.x - sa * self.y
        y = sa * self.x + ca * self.y
        return Vector2(x, y)

def iterate(initial_vectors, steps):
    vectors = initial_vectors
    for _ in range(steps):
        vectors = iteration_step(vectors)
    return vectors

def get_main(image_width, steps):
    if image_width <= 0:
        raise ValueError("imageWidth should be greater than zero")

    offset_x = image_width / 10.0
    offset_y = image_width / 3.7
    vector1 = Vector2(offset_x, offset_y)
    vector2 = Vector2(image_width / 2.0, np.sin(np.pi / 3.0) * image_width * 0.8 + offset_y)
    vector3 = Vector2(image_width - offset_x, offset_y)
    initial_vectors = [vector1, vector2, vector3, vector1]
    vectors = iterate(initial_vectors, steps)
    return get_image(vectors, image_width, image_width)

def iteration_step(vectors):
    new_vectors = []
    for i in range(len(vectors) - 1):
        start_vector = vectors[i]
        end_vector = vectors[i + 1]
        new_vectors.append(start_vector)
        difference_vector = end_vector.subtract(start_vector).multiply(1.0 / 3)
        new_vectors.append(start_vector.add(difference_vector))
        new_vectors.append(start_vector.add(difference_vector).add(difference_vector.rotate(60)))
        new_vectors.append(start_vector.add(difference_vector.multiply(2)))
    new_vectors.append(vectors[-1])
    return new_vectors

def get_image(vectors, image_width, image_height):
    image = Image.new("RGB", (image_width, image_height), "white")
    pixels = image.load()

    for i in range(len(vectors) - 1):
        x1, y1 = int(vectors[i].x), int(vectors[i].y)
        x2, y2 = int(vectors[i + 1].x), int(vectors[i + 1].y)
        draw_line(pixels, x1, y1, x2, y2)

    return image

def draw_line(pixels, x1, y1, x2, y2):
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    sx = 1 if x1 < x2 else -1
    sy = 1 if y1 < y2 else -1
    err = dx - dy

    while True:
        pixels[x1, y1] = (0, 0, 0)  # Draw black pixel
        if x1 == x2 and y1 == y2:
            break
        err2 = err * 2
        if err2 > -dy:
            err -= dy
            x1 += sx
        if err2 < dx:
            err += dx
            y1 += sy

if __name__ == "__main__":
    image_width = int(input("Enter image width: "))
    steps = int(input("Enter number of steps: "))
    file_path = input("Enter file path to save the image: ")

    image = get_main(image_width, steps)
    image.save(file_path)
    print(f"Koch snowflake saved to {file_path}")

# <END-OF-CODE>
