

import math

def hsv_to_rgb(hue, saturation, value):
    # Check if hue is within the valid range (0 to 360)
    if hue < 0 or hue > 360:
        raise ValueError("Hue should be between 0 and 360")
    # Check if saturation is within the valid range (0 to 1)
    if saturation < 0 or saturation > 1:
        raise ValueError("Saturation should be between 0 and 1")
    # Check if value is within the valid range (0 to 1)
    if value < 0 or value > 1:
        raise ValueError("Value should be between 0 and 1")
    # Calculate the chroma
    chroma = value * saturation
    # Calculate the hue section
    hue_section = hue / 60
    # Calculate the second largest component
    second_largest_component = chroma * (1 - abs(hue_section % 2 - 1))
    # Calculate the match value
    match_value = value - chroma
    # Return the RGB values by section
    return get_rgb_by_section(hue_section, chroma, match_value, second_largest_component)

def rgb_to_hsv(red, green, blue):
    # Check if RGB values are within the valid range (0 to 255)
    if red < 0 or red > 255 or green < 0 or green > 255 or blue < 0 or blue > 255:
        raise ValueError("RGB values should be between 0 and 255")
    # Normalize RGB values to the range [0, 1]
    d_red = red / 255.0
    d_green = green / 255.0
    d_blue = blue / 255.0
    # Find the maximum and minimum values among the normalized RGB values
    max_value = max(d_red, max(d_green, d_blue))
    min_value = min(d_red, min(d_green, d_blue))
    # Calculate the difference between the maximum and minimum values
    delta = max_value - min_value
    hue = 0
    # Calculate the hue
    if delta == 0:
        hue = 0
    elif max_value == d_red:
        hue = 60 * (((d_green - d_blue) / delta) % 6)
    elif max_value == d_green:
        hue = 60 * (((d_blue - d_red) / delta) + 2)
    else:
        hue = 60 * (((d_red - d_green) / delta) + 4)
    # Adjust the hue to be within the range [0, 360]
    hue = (hue + 360) % 360
    # Calculate the saturation
    saturation = max_value == 0? 0 : delta / max_value
    # Return the HSV values
    return [hue, saturation, max_value]

def get_rgb_by_section(hue_section, chroma, match_value, second_largest_component):
    red, green, blue = 0, 0, 0
    # Determine the RGB values based on the hue section
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
    # Return the RGB values
    return [red, green, blue]

def convert_to_int(input):
    return int(round(input * 255))

