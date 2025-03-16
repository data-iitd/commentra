
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Initializing the scanner to read user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt(); // Reading user choice

        switch (choice) { // Switch statement to handle user choice
            case 1:
                double hue = scanner.nextDouble(); // Reading hue value
                double saturation = scanner.nextDouble(); // Reading saturation value
                double value = scanner.nextDouble(); // Reading value

                int[] rgb = hsvToRgb(hue, saturation, value); // Converting HSV to RGB
                System.out.printf("RGB: [%d, %d, %d]%n", rgb[0], rgb[1], rgb[2]); // Printing RGB values
                break;
            case 2:
                int red = scanner.nextInt(); // Reading red value
                int green = scanner.nextInt(); // Reading green value
                int blue = scanner.nextInt(); // Reading blue value

                double[] hsv = rgbToHsv(red, green, blue); // Converting RGB to HSV
                System.out.printf("HSV: [%.2f, %.2f, %.2f]%n", hsv[0], hsv[1], hsv[2]); // Printing HSV values
                break;
            default:
                System.out.println("Invalid choice. Please choose 1 or 2."); // Handling invalid user choice
        }

        scanner.close(); // Closing the scanner
    }

    // HSV to RGB conversion method
    public static int[] hsvToRgb(double hue, double saturation, double value) {
        if (hue < 0 || hue > 360) { // Checking hue validity
            throw new IllegalArgumentException("Hue should be between 0 and 360");
        }
        if (saturation < 0 || saturation > 1) { // Checking saturation validity
            throw new IllegalArgumentException("Saturation should be between 0 and 1");
        }
        if (value < 0 || value > 1) { // Checking value validity
            throw new IllegalArgumentException("Value should be between 0 and 1");
        }

        double chroma = value * saturation; // Calculating chroma
        double hueSection = hue / 60; // Calculating hue section
        double secondLargestComponent = chroma * (1 - Math.abs(hueSection % 2 - 1)); // Calculating second largest component
        double matchValue = value - chroma; // Calculating match value

        int[] rgb = getRgbBySection(hueSection, chroma, matchValue, secondLargestComponent); // Getting RGB values based on hue section

        return rgb; // Returning RGB values
    }

    // RGB to HSV conversion method
    public static double[] rgbToHsv(int red, int green, int blue) {
        if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) { // Checking RGB validity
            throw new IllegalArgumentException("RGB values should be between 0 and 255");
        }

        double dRed = red / 255.0; // Converting RGB values to decimal
        double dGreen = green / 255.0;
        double dBlue = blue / 255.0;

        double max = Math.max(dRed, Math.max(dGreen, dBlue)); // Finding maximum value
        double min = Math.min(dRed, Math.min(dGreen, dBlue)); // Finding minimum value
        double delta = max - min; // Calculating delta

        double hue;
        if (delta == 0) { // Handling case when all RGB values are the same
            hue = 0;
        } else {
            double hueSection;
            if (max == dRed) {
                hueSection = ((dGreen - dBlue) / delta) % 6;
                hue = 60 * hueSection;
            } else if (max == dGreen) {
                hueSection = ((dBlue - dRed) / delta) + 2;
                hue = 60 * hueSection;
            } else {
                hueSection = ((dRed - dGreen) / delta) + 4;
                hue = 60 * hueSection;
            }
            hue += 360; // Adjusting hue value to be between 0 and 360
        }

        double saturation = max == 0 ? 0 : delta / max; // Calculating saturation

        return new double[]{hue, saturation, max}; // Returning HSV values
    }

    // Getting RGB values based on hue section
    private static int[] getRgbBySection(double hueSection, double chroma, double matchValue, double secondLargestComponent) {
        int red, green, blue;

        if (hueSection >= 0 && hueSection <= 1) { // Handling hue section 0 to 1
            red = convertToInt(chroma + matchValue);
            green = convertToInt(secondLargestComponent + matchValue);
            blue = convertToInt(matchValue);
        } else if (hueSection > 1 && hueSection <= 2) { // Handling hue section 1 to 2
            red = convertToInt(secondLargestComponent + matchValue);
            green = convertToInt(chroma + matchValue);
            blue = convertToInt(matchValue);
        } else if (hueSection > 2 && hueSection <= 3) { // Handling hue section 2 to 3
            red = convertToInt(matchValue);
            green = convertToInt(chroma + matchValue);
            blue = convertToInt(secondLargestComponent + matchValue);
        } else if (hueSection > 3 && hueSection <= 4) { // Handling hue section 3 to 4
            red = convertToInt(secondLargestComponent + matchValue);
            green = convertToInt(matchValue);
            blue = convertToInt(chroma + matchValue);
        } else if (hueSection > 4 && hueSection <= 5) { // Handling hue section 4 to 5
            red = convertToInt(chroma + matchValue);
            green = convertToInt(matchValue);
            blue = convertToInt(secondLargestComponent + matchValue);
        } else { // Handling hue section 5 to 6
            red = convertToInt(chroma + matchValue);
            green = convertToInt(matchValue);
            blue = convertToInt(secondLargestComponent + matchValue);
        }

        return new int[]{red, green, blue}; // Returning RGB values
    }

    // Converting decimal value to integer
    private static int convertToInt(double input) {
        return (int) Math.round(input * 255);
    }
}