
import math
from PIL import Image

def main():
    # Create a scanner to read user input
    scanner = open("input.txt", "r")

    # Read image dimensions and figure parameters from user input
    image_width = int(scanner.readline().strip())
    image_height = int(scanner.readline().strip())
    figure_center_x = float(scanner.readline().strip())
    figure_center_y = float(scanner.readline().strip())
    figure_width = float(scanner.readline().strip())
    max_step = int(scanner.readline().strip())
    use_color_coding = bool(int(scanner.readline().strip()))
    file_name = scanner.readline().strip()

    # Generate the image based on the provided parameters
    image = generate_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_color_coding)

    # Save the generated image to the specified file
    image.save(file_name)
    print("Main set image saved to", file_name)

    # Close the scanner to free resources
    scanner.close()

def generate_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_color_coding):
    # Validate input parameters for image dimensions and max steps
    if image_width <= 0:
        raise ValueError("imageWidth should be greater than zero")
    if image_height <= 0:
        raise ValueError("imageHeight should be greater than zero")
    if max_step <= 0:
        raise ValueError("maxStep should be greater than zero")

    # Create a new PIL image to hold the generated image
    image = Image.new("RGB", (image_width, image_height))

    # Loop through each pixel in the image
    for image_x in range(image_width):
        for image_y in range(image_height):
            # Calculate the corresponding figure coordinates for the current pixel
            figure_x = figure_center_x + ((image_x / image_width) - 0.5) * figure_width
            figure_y = figure_center_y + ((image_y / image_height) - 0.5) * figure_height

            # Calculate the distance for color mapping
            distance = get_distance(figure_x, figure_y, max_step)

            # Set the pixel color based on the distance and color coding preference
            if use_color_coding:
                color = color_coded_color_map(distance)
            else:
                color = black_and_white_color_map(distance)
            image.putpixel((image_x, image_y), color)

    return image # Return the generated image

# Method to generate a black and white color map based on distance
def black_and_white_color_map(distance):
    return (0, 0, 0) if distance >= 1 else (255, 255, 255)

# Method to generate a color-coded color map based on distance
def color_coded_color_map(distance):
    if distance >= 1:
        return (0, 0, 0) # Black for distances >= 1
    else:
        # Calculate hue, saturation, and value for color coding
        hue = 360 * distance
        saturation = 1
        val = 255
        hi = int(math.floor(hue / 60)) % 6
        f = hue / 60 - math.floor(hue / 60)
        p = int(val * (1 - f * saturation))
        q = int(val * (1 - (1 - f) * saturation))
        t = int(val * (1 - (1 - f) * saturation))

        # Determine the RGB color based on the hue
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

# Method to calculate the distance for the given figure coordinates
def get_distance(figure_x, figure_y, max_step):
    a = figure_x
    b = figure_y
    current_step = 0

    # Iterate to determine the escape time for the point
    for step in range(max_step):
        current_step = step
        a_new = a * a - b * b + figure_x # Update a based on the Main formula
        b = 2 * a * b + figure_y # Update b based on the Main formula
        a = a_new

        # Check if the point escapes the boundary
        if a * a + b * b > 4:
            break # Exit if the point escapes

    return current_step / (max_step - 1) # Return normalized distance

if __name__ == "__main__":
    main()

