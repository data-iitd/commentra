
import math

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
    return get_rgb_by_section(hue_section, chroma, match_value, second_largest_component)

def rgb_to_hsv(red, green, blue):
    if red < 0 or red > 255 or green < 0 or green > 255 or blue < 0 or blue > 255:
        raise ValueError("RGB values should be between 0 and 255")
    d_red = red / 255.0
    d_green = green / 255.0
    d_blue = blue / 255.0
    max = max(d_red, d_green, d_blue)
    min = min(d_red, d_green, d_blue)
    delta = max - min
    hue = 0
    if delta == 0:
        hue = 0
    elif max == d_red:
        hue = 60 * (((d_green - d_blue) / delta) % 6)
    elif max == d_green:
        hue = 60 * (((d_blue - d_red) / delta) + 2)
    else:
        hue = 60 * (((d_red - d_green) / delta) + 4)
    hue = (hue + 360) % 360
    saturation = max == 0 and 0 or delta / max
    return hue, saturation, max

def get_rgb_by_section(hue_section, chroma, match_value, second_largest_component):
    red, green, blue = 0, 0, 0
    if hue_section >= 0 and hue_section <= 1:
        red = int(round((chroma + match_value) * 255))
        green = int(round((second_largest_component + match_value) * 255))
        blue = int(round(match_value * 255))
    elif hue_section > 1 and hue_section <= 2:
        red = int(round((second_largest_component + match_value) * 255))
        green = int(round((chroma + match_value) * 255))
        blue = int(round(match_value * 255))
    elif hue_section > 2 and hue_section <= 3:
        red = int(round(match_value * 255))
        green = int(round((chroma + match_value) * 255))
        blue = int(round((second_largest_component + match_value) * 255))
    elif hue_section > 3 and hue_section <= 4:
        red = int(round(match_value * 255))
        green = int(round((second_largest_component + match_value) * 255))
        blue = int(round((chroma + match_value) * 255))
    elif hue_section > 4 and hue_section <= 5:
        red = int(round((second_largest_component + match_value) * 255))
        green = int(round(match_value * 255))
        blue = int(round((chroma + match_value) * 255))
    else:
        red = int(round((chroma + match_value) * 255))
        green = int(round(match_value * 255))
        blue = int(round((second_largest_component + match_value) * 255))
    return red, green, blue

# 