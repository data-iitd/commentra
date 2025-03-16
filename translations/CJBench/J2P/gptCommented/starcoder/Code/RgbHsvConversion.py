import sys

# Private constructor to prevent instantiation
class Main:
    def __init__(self):
        pass

    def main(self):
        # Create a Scanner object to read input from the user
        scanner = sys.stdin

        # Read the user's choice for conversion type
        choice = int(scanner.readline())

        # Switch statement to handle different conversion options
        if choice == 1:
            # Case 1: Convert HSV to RGB
            hue = float(scanner.readline()) # Read hue value
            saturation = float(scanner.readline()) # Read saturation value
            value = float(scanner.readline()) # Read value (brightness)

            # Convert HSV to RGB
            rgb = self.hsvToRgb(hue, saturation, value)

            # Output the RGB values
            print("RGB: [" + str(rgb[0]) + ", " + str(rgb[1]) + ", " + str(rgb[2]) + "]", end="")
        elif choice == 2:
            # Case 2: Convert RGB to HSV
            red = int(scanner.readline()) # Read red value
            green = int(scanner.readline()) # Read green value
            blue = int(scanner.readline()) # Read blue value

            # Convert RGB to HSV
            hsv = self.rgbToHsv(red, green, blue)

            # Output the HSV values
            print("HSV: [" + str(hsv[0]) + ", " + str(hsv[1]) + ", " + str(hsv[2]) + "]", end="")
        else:
            # Handle invalid choice
            print("Invalid choice. Please choose 1 or 2.", end="")

        # Close the scanner to free resources
        scanner.close()

    # Method to convert HSV to RGB
    def hsvToRgb(self, hue, saturation, value):
        # Validate hue, saturation, and value ranges
        if hue < 0 or hue > 360:
            raise Exception("Hue should be between 0 and 360")
        if saturation < 0 or saturation > 1:
            raise Exception("Saturation should be between 0 and 1")
        if value < 0 or value > 1:
            raise Exception("Value should be between 0 and 1")

        # Calculate chroma and other components for RGB conversion
        chroma = value * saturation
        hueSection = hue / 60
        secondLargestComponent = chroma * (1 - abs(hueSection % 2 - 1))
        matchValue = value - chroma

        # Get RGB values based on hue section
        return self.getRgbBySection(hueSection, chroma, matchValue, secondLargestComponent)

    # Method to convert RGB to HSV
    def rgbToHsv(self, red, green, blue):
        # Validate RGB value ranges
        if red < 0 or red > 255 or green < 0 or green > 255 or blue < 0 or blue > 255:
            raise Exception("RGB values should be between 0 and 255")

        # Normalize RGB values to [0, 1]
        dRed = red / 255.0
        dGreen = green / 255.0
        dBlue = blue / 255.0

        # Calculate max and min values for HSV conversion
        max = max(dRed, max(dGreen, dBlue))
        min = min(dRed, min(dGreen, dBlue))
        delta = max - min
        hue

        # Calculate hue based on the maximum RGB component
        if delta == 0:
            hue = 0
        elif max == dRed:
            hue = 60 * (((dGreen - dBlue) / delta) % 6)
        elif max == dGreen:
            hue = 60 * (((dBlue - dRed) / delta) + 2)
        else:
            hue = 60 * (((dRed - dGreen) / delta) + 4)

        # Normalize hue to [0, 360]
        hue = (hue + 360) % 360

        # Calculate saturation
        saturation = max == 0? 0 : delta / max

        # Return HSV values
        return [hue, saturation, max]

    # Helper method to determine RGB values based on hue section
    def getRgbBySection(self, hueSection, chroma, matchValue, secondLargestComponent):
        red, green, blue

        # Determine RGB values based on the hue section
        if hueSection >= 0 and hueSection <= 1:
            red = self.convertToInt(chroma + matchValue)
            green = self.convertToInt(secondLargestComponent + matchValue)
            blue = self.convertToInt(matchValue)
        elif hueSection > 1 and hueSection <= 2:
            red = self.convertToInt(secondLargestComponent + matchValue)
            green = self.convertToInt(chroma + matchValue)
            blue = self.convertToInt(matchValue)
        elif hueSection > 2 and hueSection <= 3:
            red = self.convertToInt(matchValue)
            green = self.convertToInt(chroma + matchValue)
            blue = self.convertToInt(secondLargestComponent + matchValue)
        elif hueSection > 3 and hueSection <= 4:
            red = self.convertToInt(matchValue)
            green = self.convertToInt(secondLargestComponent + matchValue)
            blue = self.convertToInt(chroma + matchValue)
        elif hueSection > 4 and hueSection <= 5:
            red = self.convertToInt(secondLargestComponent + matchValue)
            green = self.convertToInt(matchValue)
            blue = self.convertToInt(chroma + matchValue)
        else:
            red = self.convertToInt(chroma + matchValue)
            green = self.convertToInt(matchValue)
            blue = self.convertToInt(secondLargestComponent + matchValue)

        # Return the RGB values as an array
        return [red, green, blue]

    # Helper method to convert a normalized value to an integer RGB value
    def convertToInt(self, input):
        return int(round(input * 255))

# Main method
if __name__ == "__main__":
    Main().main()

