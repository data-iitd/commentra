

import math
from PIL import Image

def main():
    image_width = int(input("Enter the image width: "))
    image_height = int(input("Enter the image height: "))
    figure_center_x = float(input("Enter the figure center x: "))
    figure_center_y = float(input("Enter the figure center y: "))
    figure_width = float(input("Enter the figure width: "))
    max_step = int(input("Enter the maximum step: "))
    use_color_coding = bool(input("Use color coding? (True/False): "))
    file_name = input("Enter the file name: ")

    image = create_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_color_coding)
    image.save(file_name + ".png")
    print("Image saved to", file_name + ".png")

def create_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_color_coding):
    if image_width <= 0 or image_height <= 0 or max_step <= 0:
        raise ValueError("Image width, image height, and max step must be greater than zero.")

    image = Image.new("RGB", (image_width, image_height), color="white")
    figure_height = figure_width / image_width * image_height

    for image_x in range(image_width):
        for image_y in range(image_height):
            figure_x = figure_center_x + ((image_x / image_width) - 0.5) * figure_width
            figure_y = figure_center_y + ((image_y / image_height) - 0.5) * figure_height
            distance = get_distance(figure_x, figure_y, max_step)

            if use_color_coding:
                image.putpixel((image_x, image_y), color_coded_color_map(distance))
            else:
                image.putpixel((image_x, image_y), black_and_white_color_map(distance))

    return image

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

        # Determine the RGB values based on the HSL color space
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

def black_and_white_color_map(distance):
    return (0, 0, 0) if distance >= 1 else (255, 255, 255)

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "