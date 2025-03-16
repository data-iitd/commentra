

import math
import numpy as np
from PIL import Image
def main():
    image_width = int(input().strip())
    image_height = int(input().strip())
    figure_center_x = float(input().strip())
    figure_center_y = float(input().strip())
    figure_width = float(input().strip())
    max_step = int(input().strip())
    use_color_coding = bool(int(input().strip()))
    file_name = input().strip()
    image = get_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_color_coding)
    image.save(file_name)
    print("Main set image saved to " + file_name)
def get_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_color_coding):
    if image_width <= 0:
        raise ValueError("imageWidth should be greater than zero")
    if image_height <= 0:
        raise ValueError("imageHeight should be greater than zero")
    if max_step <= 0:
        raise ValueError("maxStep should be greater than zero")
    image = np.zeros((image_height, image_width, 3), dtype=np.uint8)
    figure_height = figure_width / image_width * image_height
    for image_x in range(image_width):
        for image_y in range(image_height):
            figure_x = figure_center_x + ((image_x / image_width) - 0.5) * figure_width
            figure_y = figure_center_y + ((image_y / image_height) - 0.5) * figure_height
            distance = get_distance(figure_x, figure_y, max_step)
            if use_color_coding:
                color = color_coded_color_map(distance)
            else:
                color = black_and_white_color_map(distance)
            image[image_y, image_x] = color
    return Image.fromarray(image)
def black_and_white_color_map(distance):
    return (0, 0, 0) if distance >= 1 else (255, 255, 255)
def color_coded_color_map(distance):
    if distance >= 1:
        return (0, 0, 0)
    else:
        hue = 360 * distance
        saturation = 1
        val = 255
        hi = int(math.floor(hue / 60)) % 6
        f = hue / 60 - math.floor(hue / 60)
        p = int(val * (1 - f * saturation))
        q = int(val * (1 - (1 - f) * saturation))
        t = int(val * (1 - (1 - f) * saturation))
        if hi == 0:
            return (val, t, p)
        elif hi == 1:
            return (q, val, p)
        elif hi == 2:
            return (p, val, t)
        elif hi == 3:
            return (p, q, val)
        elif hi == 4:
            return (t, p, val)
        else:
            return (val, p, q)
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
