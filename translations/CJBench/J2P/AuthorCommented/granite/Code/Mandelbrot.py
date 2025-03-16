

import math
import numpy as np
import matplotlib.pyplot as plt

def main():
    image_width = 1000
    image_height = 1000
    figure_center_x = 0
    figure_center_y = 0
    figure_width = 2
    max_step = 1000
    use_distance_color_coding = True
    file_name = "main_set.png"

    image = np.zeros((image_height, image_width, 3), dtype=np.uint8)
    figure_height = figure_width / image_width * image_height

    for image_x in range(image_width):
        for image_y in range(image_height):
            figure_x = figure_center_x + ((image_x / image_width) - 0.5) * figure_width
            figure_y = figure_center_y + ((image_y / image_height) - 0.5) * figure_height

            distance = get_distance(figure_x, figure_y, max_step)

            if use_distance_color_coding:
                color = color_coded_color_map(distance)
            else:
                color = black_and_white_color_map(distance)

            image[image_y, image_x] = color

    plt.imsave(file_name, image)
    print(f"Main set image saved to {file_name}")

def black_and_white_color_map(distance):
    if distance >= 1:
        return np.array([0, 0, 0])
    else:
        return np.array([255, 255, 255])

def color_coded_color_map(distance):
    if distance >= 1:
        return np.array([0, 0, 0])
    else:
        hue = 360 * distance
        saturation = 1
        val = 255
        hi = int(math.floor(hue / 60)) % 6
        f = hue / 60 - math.floor(hue / 60)

        v = int(val)
        p = 0
        q = int(val * (1 - f * saturation))
        t = int(val * (1 - (1 - f) * saturation))

        if hi == 0:
            return np.array([v, t, p])
        elif hi == 1:
            return np.array([q, v, p])
        elif hi == 2:
            return np.array([p, v, t])
        elif hi == 3:
            return np.array([p, q, v])
        elif hi == 4:
            return np.array([t, p, v])
        else:
            return np.array([v, p, q])

def get_distance(figure_x, figure_y, max_step):
    a = figure_x
    b = figure_y
    current_step = 0
    for step in range(max_step):
        current_step = step
        a_new = a * a - b * b + figure_x
        b = 2 * a * b + figure_y
        a = a_new

        if a * a + b * b > 4:
            break

    return current_step / (max_step - 1)

if __name__ == "__main__":
    main()

