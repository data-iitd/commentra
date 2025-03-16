
import math
import sys
from PIL import Image, ImageDraw

class Main:
    def __init__(self):
        pass

    def main(self):
        image_width = int(sys.stdin.readline())
        steps = int(sys.stdin.readline())

        image = self.get_main(image_width, steps)

        file_path = sys.stdin.readline()

        image.save(file_path)
        print("Koch snowflake saved to " + file_path)

    def get_main(self, image_width, steps):
        if image_width <= 0:
            raise ValueError("image_width should be greater than zero")

        offset_x = image_width / 10.0
        offset_y = image_width / 3.7
        vector1 = Vector2(offset_x, offset_y)
        vector2 = Vector2(image_width / 2.0, math.sin(math.pi / 3.0) * image_width * 0.8 + offset_y)
        vector3 = Vector2(image_width - offset_x, offset_y)
        initial_vectors = [vector1, vector2, vector3, vector1]
        vectors = self.iterate(initial_vectors, steps)
        return self.get_image(vectors, image_width, image_width)

    def iterate(self, initial_vectors, steps):
        vectors = initial_vectors
        for i in range(steps):
            vectors = self.iteration_step(vectors)

        return vectors

    def iteration_step(self, vectors):
        new_vectors = []
        for i in range(len(vectors) - 1):
            start_vector = vectors[i]
            end_vector = vectors[i + 1]
            new_vectors.append(start_vector)
            difference_vector = end_vector.subtract(start_vector).multiply(1.0 / 3)
            new_vectors.append(start_vector.add(difference_vector))
            new_vectors.append(start_vector.add(difference_vector).add(difference_vector.rotate(60)))
            new_vectors.append(start_vector.add(difference_vector.multiply(2)))

        new_vectors.append(vectors[len(vectors) - 1])
        return new_vectors

    def get_image(self, vectors, image_width, image_height):
        image = Image.new("RGB", (image_width, image_height), "white")
        draw = ImageDraw.Draw(image)

        for i in range(len(vectors) - 1):
            x1 = int(vectors[i].x)
            y1 = int(vectors[i].y)
            x2 = int(vectors[i + 1].x)
            y2 = int(vectors[i + 1].y)

            draw.line((x1, y1, x2, y2), fill="black")

        return image

class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "[{}, {}]".format(self.x, self.y)

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

if __name__ == "__main__":
    main = Main()
    main.main()

