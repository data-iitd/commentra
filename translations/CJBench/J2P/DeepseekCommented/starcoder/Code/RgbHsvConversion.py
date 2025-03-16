
import sys
import math

def hsv_to_rgb(h, s, v):
    if h < 0 or h > 360:
        raise ValueError("Hue should be between 0 and 360")
    if s < 0 or s > 1:
        raise ValueError("Saturation should be between 0 and 1")
    if v < 0 or v > 1:
        raise ValueError("Value should be between 0 and 1")
    chroma = v * s
    hue_section = h / 60
    second_largest_component = chroma * (1 - abs(hue_section % 2 - 1))
    match_value = v - chroma
    return get_rgb_by_section(hue_section, chroma, match_value, second_largest_component)

def rgb_to_hsv(r, g, b):
    if r < 0 or r > 255 or g < 0 or g > 255 or b < 0 or b > 255:
        raise ValueError("RGB values should be between 0 and 255")
    d_r = r / 255.0
    d_g = g / 255.0
    d_b = b / 255.0
    max = max(d_r, max(d_g, d_b))
    min = min(d_r, min(d_g, d_b))
    delta = max - min
    hue = 0
    if delta == 0:
        hue = 0
    elif max == d_r:
        hue = 60 * (((d_g - d_b) / delta) % 6)
    elif max == d_g:
        hue = 60 * (((d_b - d_r) / delta) + 2)
    else:
        hue = 60 * (((d_r - d_g) / delta) + 4)
    hue = (hue + 360) % 360
    saturation = max == 0? 0 : delta / max
    return (hue, saturation, max)

def get_rgb_by_section(hue_section, chroma, match_value, second_largest_component):
    red, green, blue = 0, 0, 0
    if hue_section >= 0 and hue_section <= 1:
        red = convert_to_int(chroma + match_value)
        green = convert_to_int(second_largest_component + match_value)
        blue = convert_to_int(match_value)
    elif hue_section > 1 and hue_section <= 2:
        red = convert_to_int(second_largest_component + match_value)
        green = convert_to_int(chroma + match_value)
        blue = convert_to_int(match_value)
    elif hue_section > 2 and hue_section <= 3:
        red = convert_to_int(match_value)
        green = convert_to_int(chroma + match_value)
        blue = convert_to_int(second_largest_component + match_value)
    elif hue_section > 3 and hue_section <= 4:
        red = convert_to_int(match_value)
        green = convert_to_int(second_largest_component + match_value)
        blue = convert_to_int(chroma + match_value)
    elif hue_section > 4 and hue_section <= 5:
        red = convert_to_int(second_largest_component + match_value)
        green = convert_to_int(match_value)
        blue = convert_to_int(chroma + match_value)
    else:
        red = convert_to_int(chroma + match_value)
        green = convert_to_int(match_value)
        blue = convert_to_int(second_largest_component + match_value)
    return (red, green, blue)

def convert_to_int(input):
    return int(round(input * 255))

def main():
    choice = int(input("Enter 1 to convert HSV to RGB, 2 to convert RGB to HSV: "))
    if choice == 1:
        h = float(input("Enter hue: "))
        s = float(input("Enter saturation: "))
        v = float(input("Enter value: "))
        rgb = hsv_to_rgb(h, s, v)
        print("RGB: [%d, %d, %d]" % (rgb[0], rgb[1], rgb[2]))
    elif choice == 2:
        r = int(input("Enter red: "))
        g = int(input("Enter green: "))
        b = int(input("Enter blue: "))
        hsv = rgb_to_hsv(r, g, b)
        print("HSV: [%.2f, %.2f, %.2f]" % (hsv[0], hsv[1], hsv[2]))
    else:
        print("Invalid choice. Please choose 1 or 2.")

if __name__ == "__main__":
    main()

