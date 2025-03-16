class ColorConverter:
    @staticmethod
    def hsv_to_rgb(hue, saturation, value):
        # Validate hue, saturation, and value ranges
        if hue < 0 or hue > 360:
            raise ValueError("Hue should be between 0 and 360")
        if saturation < 0 or saturation > 1:
            raise ValueError("Saturation should be between 0 and 1")
        if value < 0 or value > 1:
            raise ValueError("Value should be between 0 and 1")

        # Calculate chroma and other components for RGB conversion
        chroma = value * saturation
        hue_section = hue / 60
        second_largest_component = chroma * (1 - abs(hue_section % 2 - 1))
        match_value = value - chroma

        # Get RGB values based on hue section
        return ColorConverter.get_rgb_by_section(hue_section, chroma, match_value, second_largest_component)

    @staticmethod
    def rgb_to_hsv(red, green, blue):
        # Validate RGB value ranges
        if not all(0 <= x <= 255 for x in (red, green, blue)):
            raise ValueError("RGB values should be between 0 and 255")

        # Normalize RGB values to [0, 1]
        d_red = red / 255.0
        d_green = green / 255.0
        d_blue = blue / 255.0

        # Calculate max and min values for HSV conversion
        max_val = max(d_red, d_green, d_blue)
        min_val = min(d_red, d_green, d_blue)
        delta = max_val - min_val

        # Calculate hue based on the maximum RGB component
        if delta == 0:
            hue = 0
        elif max_val == d_red:
            hue = 60 * (((d_green - d_blue) / delta) % 6)
        elif max_val == d_green:
            hue = 60 * (((d_blue - d_red) / delta) + 2)
        else:
            hue = 60 * (((d_red - d_green) / delta) + 4)

        # Normalize hue to [0, 360]
        hue = (hue + 360) % 360

        # Calculate saturation
        saturation = 0 if max_val == 0 else delta / max_val

        # Return HSV values
        return [hue, saturation, max_val]

    @staticmethod
    def get_rgb_by_section(hue_section, chroma, match_value, second_largest_component):
        if 0 <= hue_section <= 1:
            red = ColorConverter.convert_to_int(chroma + match_value)
            green = ColorConverter.convert_to_int(second_largest_component + match_value)
            blue = ColorConverter.convert_to_int(match_value)
        elif 1 < hue_section <= 2:
            red = ColorConverter.convert_to_int(second_largest_component + match_value)
            green = ColorConverter.convert_to_int(chroma + match_value)
            blue = ColorConverter.convert_to_int(match_value)
        elif 2 < hue_section <= 3:
            red = ColorConverter.convert_to_int(match_value)
            green = ColorConverter.convert_to_int(chroma + match_value)
            blue = ColorConverter.convert_to_int(second_largest_component + match_value)
        elif 3 < hue_section <= 4:
            red = ColorConverter.convert_to_int(match_value)
            green = ColorConverter.convert_to_int(second_largest_component + match_value)
            blue = ColorConverter.convert_to_int(chroma + match_value)
        elif 4 < hue_section <= 5:
            red = ColorConverter.convert_to_int(second_largest_component + match_value)
            green = ColorConverter.convert_to_int(match_value)
            blue = ColorConverter.convert_to_int(chroma + match_value)
        else:
            red = ColorConverter.convert_to_int(chroma + match_value)
            green = ColorConverter.convert_to_int(match_value)
            blue = ColorConverter.convert_to_int(second_largest_component + match_value)

        return [red, green, blue]

    @staticmethod
    def convert_to_int(input_value):
        return int(round(input_value * 255))


def main():
    # Create a simple user interface for conversion
    choice = int(input("Choose conversion type (1: HSV to RGB, 2: RGB to HSV): "))

    if choice == 1:
        # Case 1: Convert HSV to RGB
        hue = float(input("Enter hue (0-360): "))
        saturation = float(input("Enter saturation (0-1): "))
        value = float(input("Enter value (0-1): "))

        # Convert HSV to RGB
        rgb = ColorConverter.hsv_to_rgb(hue, saturation, value)

        # Output the RGB values
        print(f"RGB: [{rgb[0]}, {rgb[1]}, {rgb[2]}]")
    elif choice == 2:
        # Case 2: Convert RGB to HSV
        red = int(input("Enter red (0-255): "))
        green = int(input("Enter green (0-255): "))
        blue = int(input("Enter blue (0-255): "))

        # Convert RGB to HSV
        hsv = ColorConverter.rgb_to_hsv(red, green, blue)

        # Output the HSV values
        print(f"HSV: [{hsv[0]:.2f}, {hsv[1]:.2f}, {hsv[2]:.2f}]")
    else:
        # Handle invalid choice
        print("Invalid choice. Please choose 1 or 2.")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
