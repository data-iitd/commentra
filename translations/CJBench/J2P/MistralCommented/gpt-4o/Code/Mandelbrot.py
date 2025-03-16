import numpy as np
from PIL import Image
import sys

def main():
    try:
        # Read input parameters from the user
        image_width = int(input().strip())
        image_height = int(input().strip())
        figure_center_x = float(input().strip())
        figure_center_y = float(input().strip())
        figure_width = float(input().strip())
        max_step = int(input().strip())
        use_color_coding = input().strip().lower() == 'true'
        file_name = input().strip()

        # Create an image with the given dimensions
        image = get_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_color_coding)

        # Save the image to a file
        image.save(file_name)
        print(f"Main: Image saved to {file_name}")
    except ValueError as e:
        print(f"Error: Please enter valid numeric values. {e}", file=sys.stderr)
    except IOError as e:
        print(f"Error saving the image: {e}", file=sys.stderr)
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)

def get_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_distance_color_coding):
    if image_width <= 0:
        raise ValueError("imageWidth should be greater than zero")
    if image_height <= 0:
        raise ValueError("imageHeight should be greater than zero")
    if max_step <= 0:
        raise ValueError("maxStep should be greater than zero")

    # Initialize the image with the given dimensions
    image = Image.new("RGB", (image_width, image_height))

    figure_height = figure_width / image_width * image_height

    # Iterate through each pixel in the image and calculate its color based on the figure's position and distance
    for image_x in range(image_width):
        for image_y in range(image_height):
            figure_x = figure_center_x + ((image_x / image_width) - 0.5) * figure_width
            figure_y = figure_center_y + ((image_y / image_height) - 0.5) * figure_height
            distance = get_distance(figure_x, figure_y, max_step)

            # Set the pixel's color based on the useDistanceColorCoding flag
            if use_distance_color_coding:
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
        hi = int(np.floor(hue / 60)) % 6
        f = hue / 60 - np.floor(hue / 60)
        v = int(val)
        p = 0
        q = int(val * (1 - f * saturation))
        t = int(val * (1 - (1 - f) * saturation))

        # Determine the RGB values based on the HSL color space
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

    # Iterate through each step in the Main set calculation
    for step in range(max_step):
        current_step = step
        a_new = a * a - b * b + figure_x
        b = 2 * a * b + figure_y
        a = a_new

        # If the distance exceeds a certain threshold, break the loop
        if a * a + b * b > 4:
            break

    # Return the number of iterations as the distance
    return current_step / (max_step - 1)

def black_and_white_color_map(distance):
    return (0, 0, 0) if distance >= 1 else (255, 255, 255)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
