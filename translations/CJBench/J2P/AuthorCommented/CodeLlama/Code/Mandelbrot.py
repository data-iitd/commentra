
import math
import sys

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

            image.putpixel((image_x, image_y), (0, 0, 0) if use_distance_color_coding else (255, 255, 255))

    return image

def main():
    image_width = int(sys.stdin.readline().strip())
    image_height = int(sys.stdin.readline().strip())
    figure_center_x = float(sys.stdin.readline().strip())
    figure_center_y = float(sys.stdin.readline().strip())
    figure_width = float(sys.stdin.readline().strip())
    max_step = int(sys.stdin.readline().strip())
    use_distance_color_coding = bool(sys.stdin.readline().strip())
    filename = sys.stdin.readline().strip()

    image = get_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_distance_color_coding)
    image.save(filename)
    print("Main set image saved to " + filename)

if __name__ == "__main__":
    main()

