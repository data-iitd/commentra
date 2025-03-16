import math
import sys
from PIL import Image


def get_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_distance_color_coding):
    if image_width <= 0:
        raise ValueError("image_width should be greater than zero")
    if image_height <= 0:
        raise ValueError("image_height should be greater than zero")
    if max_step <= 0:
        raise ValueError("max_step should be greater than zero")
    image = Image.new("RGB", (image_width, image_height))
    figure_height = figure_width / image_width * image_height
    for image_x in range(image_width):
        for image_y in range(image_height):
            figure_x = figure_center_x + ((image_x / image_width - 0.5) * figure_width)
            figure_y = figure_center_y + ((image_y / image_height - 0.5) * figure_height)
            distance = get_distance(figure_x, figure_y, max_step)
            image.putpixel((image_x, image_y), use_distance_color_coding and color_coded_color_map(distance) or black_and_white_color_map(distance))
    return image


def black_and_white_color_map(distance):
    return (0, 0, 0) if distance >= 1 else (255, 255, 255)


def color_coded_color_map(distance):
    if distance >= 1:
        return (0, 0, 0)
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
        return (v, t, p)
    elif hi == 1:
        return (q, v, p)
    elif hi == 2:
        return (p, v, t)
    elif hi == 3:
        return (p, q, v)
    elif hi == 4:
        return (t, p, v)
    else:
        return (v, p, q)


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
    scanner = sys.stdin
    try:
        image_width = int(scanner.readline().strip())
        image_height = int(scanner.readline().strip())
        figure_center_x = float(scanner.readline().strip())
        figure_center_y = float(scanner.readline().strip())
        figure_width = float(scanner.readline().strip())
        max_step = int(scanner.readline().strip())
        use_distance_color_coding = bool(scanner.readline().strip())
        file_name = scanner.readline().strip()
        image = get_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_distance_color_coding)
        image.save(file_name)
        print("Main set image saved to " + file_name)
    except ValueError as e:
        print("Error: Please enter valid numeric values. " + str(e))
    except IOError as e:
        print("Error saving the image: " + str(e))
    except IllegalArgumentException as e:
        print("Error: " + str(e))
    finally:
        scanner.close()


