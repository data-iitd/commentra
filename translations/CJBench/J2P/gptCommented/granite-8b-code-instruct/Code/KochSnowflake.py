
import math
import numpy as np
from PIL import Image, ImageDraw

def iterate(vectors, steps):
    for _ in range(steps):
        vectors = iteration_step(vectors)
    return vectors

def get_main(image_width, steps):
    offset_x = image_width / 10
    offset_y = image_width / 3.7
    vector1 = np.array([offset_x, offset_y])
    vector2 = np.array([image_width / 2, math.sin(math.pi / 3) * image_width * 0.8 + offset_y])
    vector3 = np.array([image_width - offset_x, offset_y])
    initial_vectors = [vector1, vector2, vector3, vector1]
    vectors = iterate(initial_vectors, steps)
    return get_image(vectors, image_width, image_width)

def iteration_step(vectors):
    new_vectors = []
    for i in range(len(vectors) - 1):
        start_vector = vectors[i]
        end_vector = vectors[i + 1]
        new_vectors.append(start_vector)
        difference_vector = (end_vector - start_vector) / 3
        new_vectors.append(start_vector + difference_vector)
        new_vectors.append(start_vector + difference_vector + np.array([difference_vector[1], -difference_vector[0]]))
        new_vectors.append(start_vector + 2 * difference_vector)
    new_vectors.append(vectors[-1])
    return new_vectors

def get_image(vectors, image_width, image_height):
    image = Image.new("RGB", (image_width, image_height), color="white")
    draw = ImageDraw.Draw(image)
    draw.line([tuple(vector) for vector in vectors], fill="black", width=1)
    return image

if __name__ == "__main__":
    import sys
    image_width = int(sys.argv[1])
    steps = int(sys.argv[2])
    image = get_main(image_width, steps)
    image.save(sys.argv[3])

