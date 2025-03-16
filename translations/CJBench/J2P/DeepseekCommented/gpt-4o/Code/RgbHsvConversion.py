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
    
    max_val = max(d_red, d_green, d_blue)
    min_val = min(d_red, d_green, d_blue)
    delta = max_val - min_val
    
    hue = 0
    if delta == 0:
        hue = 0
    elif max_val == d_red:
        hue = 60 * ((d_green - d_blue) / delta % 6)
    elif max_val == d_green:
        hue = 60 * ((d_blue - d_red) / delta + 2)
    else:
        hue = 60 * ((d_red - d_green) / delta + 4)
    
    hue = (hue + 360) % 360
    saturation = max_val == 0 ? 0 : delta / max_val
    
    return [hue, saturation, max_val]

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
    
    return [red, green, blue]

def convert_to_int(input_val):
    return round(input_val * 255)

# Main program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    
    choice = int(data[0])
    
    if choice == 1:
        hue = float(data[1])
        saturation = float(data[2])
        value = float(data[3])
        rgb = hsv_to_rgb(hue, saturation, value)
        print(f"RGB: [{rgb[0]}, {rgb[1]}, {rgb[2]}]")
    elif choice == 2:
        red = int(data[1])
        green = int(data[2])
        blue = int(data[3])
        hsv = rgb_to_hsv(red, green, blue)
        print(f"HSV: [{hsv[0]:.2f}, {hsv[1]:.2f}, {hsv[2]:.2f}]")
    else:
        print("Invalid choice. Please choose 1 or 2.")
