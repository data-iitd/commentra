
import sys

# Initializing the scanner to read user input
scanner = sys.stdin
choice = int(scanner.readline()) # Reading user choice

# Switch statement to handle user choice
if choice == 1:
    hue = float(scanner.readline()) # Reading hue value
    saturation = float(scanner.readline()) # Reading saturation value
    value = float(scanner.readline()) # Reading value

    rgb = hsvToRgb(hue, saturation, value) # Converting HSV to RGB
    print("RGB: [" + str(rgb[0]) + ", " + str(rgb[1]) + ", " + str(rgb[2]) + "]") # Printing RGB values
elif choice == 2:
    red = int(scanner.readline()) # Reading red value
    green = int(scanner.readline()) # Reading green value
    blue = int(scanner.readline()) # Reading blue value

    hsv = rgbToHsv(red, green, blue) # Converting RGB to HSV
    print("HSV: [" + str(hsv[0]) + ", " + str(hsv[1]) + ", " + str(hsv[2]) + "]") # Printing HSV values
else:
    print("Invalid choice. Please choose 1 or 2.") # Handling invalid user choice

scanner.close() # Closing the scanner

# HSV to RGB conversion method
def hsvToRgb(hue, saturation, value):
    if hue < 0 or hue > 360: # Checking hue validity
        raise Exception("Hue should be between 0 and 360")
    if saturation < 0 or saturation > 1: # Checking saturation validity
        raise Exception("Saturation should be between 0 and 1")
    if value < 0 or value > 1: # Checking value validity
        raise Exception("Value should be between 0 and 1")

    chroma = value * saturation # Calculating chroma
    hueSection = hue / 60 # Calculating hue section
    secondLargestComponent = chroma * (1 - abs(hueSection % 2 - 1)) # Calculating second largest component
    matchValue = value - chroma # Calculating match value

    rgb = getRgbBySection(hueSection, chroma, matchValue, secondLargestComponent) # Getting RGB values based on hue section

    return rgb # Returning RGB values

# RGB to HSV conversion method
def rgbToHsv(red, green, blue):
    if red < 0 or red > 255 or green < 0 or green > 255 or blue < 0 or blue > 255: # Checking RGB validity
        raise Exception("RGB values should be between 0 and 255")

    dRed = red / 255.0 # Converting RGB values to decimal
    dGreen = green / 255.0
    dBlue = blue / 255.0

    max = max(dRed, max(dGreen, dBlue)) # Finding maximum value
    min = min(dRed, min(dGreen, dBlue)) # Finding minimum value
    delta = max - min # Calculating delta

    hue = 0
    if delta == 0: # Handling case when all RGB values are the same
        hue = 0
    else:
        hueSection = 0
        if max == dRed:
            hueSection = ((dGreen - dBlue) / delta) % 6
            hue = 60 * hueSection
        elif max == dGreen:
            hueSection = ((dBlue - dRed) / delta) + 2
            hue = 60 * hueSection
        else:
            hueSection = ((dRed - dGreen) / delta) + 4
            hue = 60 * hueSection
        hue += 360 # Adjusting hue value to be between 0 and 360

    saturation = max == 0? 0 : delta / max # Calculating saturation

    return [hue, saturation, max] # Returning HSV values

# Getting RGB values based on hue section
def getRgbBySection(hueSection, chroma, matchValue, secondLargestComponent):
    red, green, blue = 0, 0, 0

    if hueSection >= 0 and hueSection <= 1: # Handling hue section 0 to 1
        red = convertToInt(chroma + matchValue)
        green = convertToInt(secondLargestComponent + matchValue)
        blue = convertToInt(matchValue)
    elif hueSection > 1 and hueSection <= 2: # Handling hue section 1 to 2
        red = convertToInt(secondLargestComponent + matchValue)
        green = convertToInt(chroma + matchValue)
        blue = convertToInt(matchValue)
    elif hueSection > 2 and hueSection <= 3: # Handling hue section 2 to 3
        red = convertToInt(matchValue)
        green = convertToInt(chroma + matchValue)
        blue = convertToInt(secondLargestComponent + matchValue)
    elif hueSection > 3 and hueSection <= 4: # Handling hue section 3 to 4
        red = convertToInt(secondLargestComponent + matchValue)
        green = convertToInt(matchValue)
        blue = convertToInt(chroma + matchValue)
    elif hueSection > 4 and hueSection <= 5: # Handling hue section 4 to 5
        red = convertToInt(chroma + matchValue)
        green = convertToInt(matchValue)
        blue = convertToInt(secondLargestComponent + matchValue)
    else: # Handling hue section 5 to 6
        red = convertToInt(chroma + matchValue)
        green = convertToInt(matchValue)
        blue = convertToInt(secondLargestComponent + matchValue)

    return [red, green, blue] # Returning RGB values

# Converting decimal value to integer
def convertToInt(input):
    return int(round(input * 255))

