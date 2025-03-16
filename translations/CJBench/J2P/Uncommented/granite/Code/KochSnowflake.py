

import math
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as mlines

def iterate(vectors, steps):
    for _ in range(steps):
        vectors = iteration_step(vectors)
    return vectors

def get_main(image_width, steps):
    if image_width <= 0:
        raise ValueError("image_width should be greater than zero")
    offset_x = image_width / 10.0
    offset_y = image_width / 3.7
    vector1 = np.array([offset_x, offset_y])
    vector2 = np.array([image_width / 2.0, math.sin(math.pi / 3.0) * image_width * 0.8 + offset_y])
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
        new_vectors.append(start_vector + difference_vector * 2)
    new_vectors.append(vectors[-1])
    return new_vectors

def get_image(vectors, image_width, image_height):
    image = np.zeros((image_height, image_width, 3), dtype=np.uint8)
    for i in range(len(vectors) - 1):
        start_vector = vectors[i]
        end_vector = vectors[i + 1]
        x1, y1 = start_vector
        x2, y2 = end_vector
        image = cv2.line(image, (int(x1), int(y1)), (int(x2), int(y2)), (0, 0, 0), 1)
    return image

if __name__ == "__main__":
    import cv2
    scanner = open("input.txt", "r")
    image_width, steps = map(int, scanner.readline().split())
    vectors = get_main(image_width, steps)
    image = get_image(vectors, image_width, image_width)
    cv2.imwrite("output.png", image)
    scanner.close()

