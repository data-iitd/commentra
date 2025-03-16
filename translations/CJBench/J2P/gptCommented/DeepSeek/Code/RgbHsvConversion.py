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
    rgb = get_rgb_by_section(hue_section, chroma, match_value, second_largest_component)
    
    # Convert to integer RGB values
    return [int(round(c * 255)) for c in rgb]

def rgb_to_hsv(red, green, blue):
    # Validate RGB value ranges
    if red < 0 or red > 255 or green < 0 or green > 255 or blue < 0 or blue > 255:
        raise ValueError("RGB values should be between 0 and 255")
    
    # Normalize RGB values to [0, 1]
    d_red = red / 255.0
    d_green = green / 255.0
    d_blue = blue / 255.0
    
    # Calculate max and min values for HSV conversion
    max_val = max(d_red, d_green, d_blue)
    min_val = min(d_red, d_green, d_blue)
    delta = max_val - min_val
    hue = 0
    
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

def get_rgb_by_section(hue_section, chroma, match_value, second_largest_component):
    rgb = []
    
    # Determine RGB values based on the hue section
    if hue_section >= 0 and hue_section <= 1:
        rgb.append(convert_to_int(chroma + match_value))
        rgb.append(convert_to_int(second_largest_component + match_value))
        rgb.append(convert_to_int(match_value))
    elif hue_section > 1 and hue_section <= 2:
        rgb.append(convert_to_int(second_largest_component + match_value))
        rgb.append(convert_to_int(chroma + match_value))
        rgb.append(convert_to_int(match_value))
    elif hue_section > 2 and hue_section <= 3:
        rgb.append(convert_to_int(match_value))
        rgb.append(convert_to_int(chroma + match_value))
        rgb.append(convert_to_int(second_largest_component + match_value))
    elif hue_section > 3 and hue_section <= 4:
        rgb.append(convert_to_int(match_value))
        rgb.append(convert_to_int(second_largest_component + match_value))
        rgb.append(convert_to_int(chroma + match_value))
    elif hue_section > 4 and hue_section <= 5:
        rgb.append(convert_to_int(second_largest_component + match_value))
        rgb.append(convert_to_int(match_value))
        rgb.append(convert_to_int(chroma + match_value))
    else:
        rgb.append(convert_to_int(chroma + match_value))
        rgb.append(convert_to_int(match_value))
        rgb.append(convert_to_int(second_largest_component + match_value))
    
    # Return the RGB values
    return rgb

def convert_to_int(input_value):
    return round(input_value * 255)

# Main program
if __name__ == "__main__":
    choice = int(input())  # Read user's choice for conversion type
    
    if choice == 1:
        # Case 1: Convert HSV to RGB
        hue = float(input())  # Read hue value
        saturation = float(input())  # Read saturation value
        value = float(input())  # Read value (brightness)
        
        # Convert HSV to RGB
        rgb = hsv_to_rgb(hue, saturation, value)
        
        # Output the RGB values
        print(f"RGB: [{rgb[0]}, {rgb[1]}, {rgb[2]}]")
    elif choice == 2:
        # Case 2: Convert RGB to HSV
        red = int(input())  # Read red value
        green = int(input())  # Read green value
        blue = int(input())  # Read blue value
        
        # Convert RGB to HSV
        hsv = rgb_to_hsv(red, green, blue)
        
        # Output the HSV values
        print(f"HSV: [{hsv[0]:.2f}, {hsv[1]:.2f}, {hsv[2]:.2f}]")
    else:
        # Handle invalid choice
        print("Invalid choice. Please choose 1 or 2.")
