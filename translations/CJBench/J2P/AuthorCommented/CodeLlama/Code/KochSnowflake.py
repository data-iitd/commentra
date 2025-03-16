
import math
import sys


def get_main(image_width, steps):
    offset_x = image_width / 10.0
    offset_y = image_width / 3.7
    vector1 = Vector2(offset_x, offset_y)
    vector2 = Vector2(image_width / 2.0, math.sin(math.pi / 3.0) * image_width * 0.8 + offset_y)
    vector3 = Vector2(image_width - offset_x, offset_y)
    initial_vectors = [vector1, vector2, vector3, vector1]
    vectors = iterate(initial_vectors, steps)
    return get_image(vectors, image_width, image_width)


def iterate(initial_vectors, steps):
    vectors = initial_vectors
    for i in range(steps):
        vectors = iteration_step(vectors)
    return vectors


def iteration_step(vectors):
    new_vectors = []
    for i in range(len(vectors) - 1):
        start_vector = vectors[i]
        end_vector = vectors[i + 1]
        new_vectors.append(start_vector)
        difference_vector = (end_vector - start_vector) / 3
        new_vectors.append(start_vector + difference_vector)
        new_vectors.append(start_vector + difference_vector + difference_vector.rotate(60))
        new_vectors.append(start_vector + difference_vector * 2)
    new_vectors.append(vectors[-1])
    return new_vectors


def get_image(vectors, image_width, image_height):
    image = Image.new("RGB", (image_width, image_height), (255, 255, 255))
    draw = ImageDraw.Draw(image)

    for i in range(len(vectors) - 1):
        x1 = int(vectors[i].x)
        y1 = int(vectors[i].y)
        x2 = int(vectors[i + 1].x)
        y2 = int(vectors[i + 1].y)

        draw.line((x1, y1, x2, y2), fill=(0, 0, 0), width=1)

    return image


class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"[{self.x}, {self.y}]"

    def __add__(self, vector):
        x = self.x + vector.x
        y = self.y + vector.y
        return Vector2(x, y)

    def __sub__(self, vector):
        x = self.x - vector.x
        y = self.y - vector.y
        return Vector2(x, y)

    def __mul__(self, scalar):
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
    image_width = int(sys.argv[1])
    steps = int(sys.argv[2])
    image = get_main(image_width, steps)
    file_path = sys.argv[3]
    image.save(file_path)


