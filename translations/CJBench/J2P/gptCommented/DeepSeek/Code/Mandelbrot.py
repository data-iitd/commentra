import java.awt.Color
import java.awt.image.BufferedImage
import java.io.File
import java.io.IOException
import java.util.Scanner
import javax.imageio.ImageIO

class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    @staticmethod
    def main(args):
        # Create a scanner to read user input
        scanner = Scanner(System.in)
        try:
            # Read image dimensions and figure parameters from user input
            image_width = int(scanner.nextLine().strip())
            image_height = int(scanner.nextLine().strip())
            figure_center_x = float(scanner.nextLine().strip())
            figure_center_y = float(scanner.nextLine().strip())
            figure_width = float(scanner.nextLine().strip())
            max_step = int(scanner.nextLine().strip())
            use_color_coding = bool(scanner.nextLine().strip())
            file_name = scanner.nextLine().strip()

            # Generate the image based on the provided parameters
            image = Main.get_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_color_coding)

            # Save the generated image to the specified file
            ImageIO.write(image, "png", File(file_name))
            print(f"Main set image saved to {file_name}")
        except ValueError as e:
            # Handle invalid numeric input
            print(f"Error: Please enter valid numeric values. {e}")
        except IOException as e:
            # Handle errors during image saving
            print(f"Error saving the image: {e}")
        except Exception as e:
            # Handle other exceptions
            print(f"Error: {e}")
        finally:
            # Close the scanner to free resources
            scanner.close()

    @staticmethod
    def get_image(image_width, image_height, figure_center_x, figure_center_y, figure_width, max_step, use_color_coding):
        # Validate input parameters for image dimensions and max steps
        if image_width <= 0:
            raise ValueError("imageWidth should be greater than zero")
        if image_height <= 0:
            raise ValueError("imageHeight should be greater than zero")
        if max_step <= 0:
            raise ValueError("maxStep should be greater than zero")

        # Create a new BufferedImage to hold the generated image
        image = BufferedImage(image_width, image_height, BufferedImage.TYPE_INT_RGB)
        figure_height = figure_width / image_width * image_height  # Calculate figure height based on aspect ratio

        # Loop through each pixel in the image
        for image_x in range(image_width):
            for image_y in range(image_height):
                # Calculate the corresponding figure coordinates for the current pixel
                figure_x = figure_center_x + ((image_x / image_width - 0.5) * figure_width)
                figure_y = figure_center_y + ((image_y / image_height - 0.5) * figure_height)

                # Calculate the distance for color mapping
                distance = Main.get_distance(figure_x, figure_y, max_step)

                # Set the pixel color based on the distance and color coding preference
                image.setRGB(image_x, image_y, Main.color_coded_color_map(distance).getRGB() if use_color_coding else Main.black_and_white_color_map(distance).getRGB())
        return image  # Return the generated image

    # Method to generate a black and white color map based on distance
    @staticmethod
    def black_and_white_color_map(distance):
        return Color(0, 0, 0) if distance >= 1 else Color(255, 255, 255)

    # Method to generate a color-coded color map based on distance
    @staticmethod
    def color_coded_color_map(distance):
        if distance >= 1:
            return Color(0, 0, 0)  # Black for distances >= 1
        else:
            # Calculate hue, saturation, and value for color coding
            hue = 360 * distance
            saturation = 1
            val = 255
            hi = int(math.floor(hue / 60)) % 6
            f = hue / 60 - math.floor(hue / 60)
            v = int(val)
            p = 0
            q = int(val * (1 - f * saturation))
            t = int(val * (1 - (1 - f) * saturation))

            # Determine the RGB color based on the hue
            switch hi:
                case 0:
                    return Color(v, t, p)
                case 1:
                    return Color(q, v, p)
                case 2:
                    return Color(p, v, t)
                case 3:
                    return Color(p, q, v)
                case 4:
                    return Color(t, p, v)
                case 5:
                    return Color(v, p, q)

    # Method to calculate the distance for the given figure coordinates
    @staticmethod
    def get_distance(figure_x, figure_y, max_step):
        a = figure_x
        b = figure_y
        current_step = 0

        # Iterate to determine the escape time for the point
        for step in range(max_step):
            current_step = step
            a_new = a * a - b * b + figure_x  # Update a based on the Main formula
            b = 2 * a * b + figure_y  # Update b based on the Main formula
            a = a_new

            # Check if the point escapes the boundary
            if a * a + b * b > 4:
                break  # Exit if the point escapes

        return current_step / (max_step - 1)  # Return normalized distance

# Call the main method
Main.main([])
