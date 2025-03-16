import math

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
    return get_rgb_by_section(hue_section, chroma, match_value, second_largest_component)

def rgb_to_hsv(red, green, blue):
    # Validate RGB value ranges
    if red < 0 or red > 255 or green < 0 or green > 255 or blue < 0 or blue > 255:
        raise ValueError("RGB values should be between 0 and 255")
    
    # Normalize RGB values to [0, 1]
    d_red = red / 255.0
    d_green = green / 255.0
    d_blue = blue / 255.0
    
    # Calculate max and min values for HSV conversion
    max = max(d_red, max(d_green, d_blue))
    min = min(d_red, min(d_green, d_blue))
    delta = max - min
    hue
    
    # Calculate hue based on the maximum RGB component
    if delta == 0:
        hue = 0
    elif max == d_red:
        hue = 60 * (((d_green - d_blue) / delta) % 6)
    elif max == d_green:
        hue = 60 * (((d_blue - d_red) / delta) + 2)
    else:
        hue = 60 * (((d_red - d_green) / delta) + 4)
    
    # Normalize hue to [0, 360]
    hue = (hue + 360) % 360
    
    # Calculate saturation
    saturation = max == 0.0 ? 0 : delta / max
    
    # Return HSV values
    return [hue, saturation, max]

def get_rgb_by_section(hue_section, chroma, match_value, second_largest_component):
    red, green, blue
    
    # Determine RGB values based on the hue section
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
    
    # Return the RGB values as an array
    return [red, green, blue]

# Main function to handle user input and conversion
def main():
    # Create a Scanner object to read input from the user
    scanner = input("Enter your choice for conversion type (1 for HSV to RGB, 2 for RGB to HSV): ")
    
    # Switch statement to handle different conversion options
    if scanner == 1:
        # Case 1: Convert HSV to RGB
        hue = input("Enter hue value: ")
        saturation = input("Enter saturation value: ")
        value = input("Enter value (brightness) value: ")
        
        # Convert HSV to RGB
        rgb = hsv_to_rgb(hue, saturation, value)
        
        # Output the RGB values
        print("RGB:", rgb)
    elif scanner == 2:
        # Case 2: Convert RGB to HSV
        red = input("Enter red value: ")
        green = input("Enter green value: ")
        blue = input("Enter blue value: ")
        
        # Convert RGB to HSV
        hsv = rgb_to_hsv(red, green, blue)
        
        # Output the HSV values
        print("HSV:", hsv)
    else:
        # Handle invalid choice
        print("Invalid choice. Please choose 1 or 2.")

# Call the main function
main()

