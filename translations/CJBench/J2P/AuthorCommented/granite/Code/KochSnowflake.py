

import math
import numpy as np
from PIL import Image, ImageDraw

def iterate(vectors, steps):
    for _ in range(steps):
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
        new_vectors.append(start_vector + difference_vector + rotate_vector(difference_vector, 60))
        new_vectors.append(start_vector + difference_vector * 2)
    new_vectors.append(vectors[-1])
    return new_vectors

def rotate_vector(vector, angle_in_degrees):
    radians = math.radians(angle_in_degrees)
    rotation_matrix = np.array([[math.cos(radians), -math.sin(radians)],
                                   [math.sin(radians), math.cos(radians)]])
    rotated_vector = np.dot(rotation_matrix, vector)
    return rotated_vector

def get_main(image_width, steps):
    offset_x = image_width / 10
    offset_y = image_width / 3.7
    vector1 = np.array([offset_x, offset_y])
    vector2 = np.array([image_width / 2, math.sin(math.pi / 3) * image_width * 0.8 + offset_y])
    vector3 = np.array([image_width - offset_x, offset_y])
    initial_vectors = [vector1, vector2, vector3, vector1]
    vectors = iterate(initial_vectors, steps)
    return get_image(vectors, image_width, image_width)

def get_image(vectors, image_width, image_height):
    image = Image.new("RGB", (image_width, image_height), color="white")
    draw = ImageDraw.Draw(image)
    for i in range(len(vectors) - 1):
        start_point = tuple(vectors[i])
        end_point = tuple(vectors[i + 1])
        draw.line([start_point, end_point], fill="black", width=1)
    return image

if __name__ == "__main__":
    import sys
    image_width = int(sys.argv[1])
    steps = int(sys.argv[2])
    image = get_main(image_width, steps)
    image.save("koch_snowflake.png")

