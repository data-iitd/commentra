
import sys
import math

def hsvToRgb(hue, saturation, value):
    if hue < 0 or hue > 360:
        raise ValueError("Hue should be between 0 and 360")
    if saturation < 0 or saturation > 1:
        raise ValueError("Saturation should be between 0 and 1")
    if value < 0 or value > 1:
        raise ValueError("Value should be between 0 and 1")
    chroma = value * saturation
    hueSection = hue / 60
    secondLargestComponent = chroma * (1 - abs(hueSection % 2 - 1))
    matchValue = value - chroma
    return getRgbBySection(hueSection, chroma, matchValue, secondLargestComponent)

def rgbToHsv(red, green, blue):
    if red < 0 or red > 255 or green < 0 or green > 255 or blue < 0 or blue > 255:
        raise ValueError("RGB values should be between 0 and 255")
    dRed = red / 255.0
    dGreen = green / 255.0
    dBlue = blue / 255.0
    max = max(dRed, max(dGreen, dBlue))
    min = min(dRed, min(dGreen, dBlue))
    delta = max - min
    hue = 0
    if delta == 0:
        hue = 0
    elif max == dRed:
        hue = 60 * (((dGreen - dBlue) / delta) % 6)
    elif max == dGreen:
        hue = 60 * (((dBlue - dRed) / delta) + 2)
    else:
        hue = 60 * (((dRed - dGreen) / delta) + 4)
    hue = (hue + 360) % 360
    saturation = max == 0? 0 : delta / max
    return (hue, saturation, max)

def getRgbBySection(hueSection, chroma, matchValue, secondLargestComponent):
    red, green, blue = 0, 0, 0
    if hueSection >= 0 and hueSection <= 1:
        red = convertToInt(chroma + matchValue)
        green = convertToInt(secondLargestComponent + matchValue)
        blue = convertToInt(matchValue)
    elif hueSection > 1 and hueSection <= 2:
        red = convertToInt(secondLargestComponent + matchValue)
        green = convertToInt(chroma + matchValue)
        blue = convertToInt(matchValue)
    elif hueSection > 2 and hueSection <= 3:
        red = convertToInt(matchValue)
        green = convertToInt(chroma + matchValue)
        blue = convertToInt(secondLargestComponent + matchValue)
    elif hueSection > 3 and hueSection <= 4:
        red = convertToInt(matchValue)
        green = convertToInt(secondLargestComponent + matchValue)
        blue = convertToInt(chroma + matchValue)
    elif hueSection > 4 and hueSection <= 5:
        red = convertToInt(secondLargestComponent + matchValue)
        green = convertToInt(matchValue)
        blue = convertToInt(chroma + matchValue)
    else:
        red = convertToInt(chroma + matchValue)
        green = convertToInt(matchValue)
        blue = convertToInt(secondLargestComponent + matchValue)
    return (red, green, blue)

def convertToInt(input):
    return int(round(input * 255))

def main():
    choice = int(raw_input())
    if choice == 1:
        hue = float(raw_input())
        saturation = float(raw_input())
        value = float(raw_input())
        rgb = hsvToRgb(hue, saturation, value)
        print "RGB: [%d, %d, %d]" % (rgb[0], rgb[1], rgb[2])
    elif choice == 2:
        red = int(raw_input())
        green = int(raw_input())
        blue = int(raw_input())
        hsv = rgbToHsv(red, green, blue)
        print "HSV: [%.2f, %.2f, %.2f]" % (hsv[0], hsv[1], hsv[2])
    else:
        print "Invalid choice. Please choose 1 or 2."

if __name__ == "__main__":
    main()

