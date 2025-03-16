class ColorConverter:
    @staticmethod
    def hsv_to_rgb(hue, saturation, value):
        if hue < 0 or hue > 360:
            raise ValueError("Hue should be between 0 and 360")
        if saturation < 0 or saturation > 1:
            raise ValueError("Saturation should be between 0 and 1")
        if value < 0 or value > 1:
            raise ValueError("Value should be between 0 and 1")

        chroma = value * saturation
        hue_section = hue / 60
        second_largest_component = chroma * (1 - abs(hue_section % 2 - 1))
        match_value = value - chroma

        return ColorConverter.get_rgb_by_section(hue_section, chroma, match_value, second_largest_component)

    @staticmethod
    def rgb_to_hsv(red, green, blue):
        if not all(0 <= x <= 255 for x in (red, green, blue)):
            raise ValueError("RGB values should be between 0 and 255")

        d_red = red / 255.0
        d_green = green / 255.0
        d_blue = blue / 255.0

        max_val = max(d_red, d_green, d_blue)
        min_val = min(d_red, d_green, d_blue)
        delta = max_val - min_val

        if delta == 0:
            hue = 0
        else:
            if max_val == d_red:
                hue_section = ((d_green - d_blue) / delta) % 6
                hue = 60 * hue_section
            elif max_val == d_green:
                hue_section = ((d_blue - d_red) / delta) + 2
                hue = 60 * hue_section
            else:
                hue_section = ((d_red - d_green) / delta) + 4
                hue = 60 * hue_section
            hue += 360

        saturation = 0 if max_val == 0 else delta / max_val

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
            red = ColorConverter.convert_to_int(second_largest_component + match_value)
            green = ColorConverter.convert_to_int(match_value)
            blue = ColorConverter.convert_to_int(chroma + match_value)
        elif 4 < hue_section <= 5:
            red = ColorConverter.convert_to_int(chroma + match_value)
            green = ColorConverter.convert_to_int(match_value)
            blue = ColorConverter.convert_to_int(second_largest_component + match_value)
        else:
            red = ColorConverter.convert_to_int(chroma + match_value)
            green = ColorConverter.convert_to_int(match_value)
            blue = ColorConverter.convert_to_int(second_largest_component + match_value)

        return [red, green, blue]

    @staticmethod
    def convert_to_int(input_value):
        return int(round(input_value * 255))


def main():
    choice = int(input("Enter 1 for HSV to RGB or 2 for RGB to HSV: "))

    if choice == 1:
        hue = float(input("Enter hue: "))
        saturation = float(input("Enter saturation: "))
        value = float(input("Enter value: "))
        rgb = ColorConverter.hsv_to_rgb(hue, saturation, value)
        print(f"RGB: [{rgb[0]}, {rgb[1]}, {rgb[2]}]")
    elif choice == 2:
        red = int(input("Enter red: "))
        green = int(input("Enter green: "))
        blue = int(input("Enter blue: "))
        hsv = ColorConverter.rgb_to_hsv(red, green, blue)
        print(f"HSV: [{hsv[0]:.2f}, {hsv[1]:.2f}, {hsv[2]:.2f}]")
    else:
        print("Invalid choice. Please choose 1 or 2.")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
