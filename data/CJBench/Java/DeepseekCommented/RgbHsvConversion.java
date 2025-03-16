
import java.util.Scanner;
public final class Main {
    private Main() {
    }
    public static void main(String[] args) {
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);
        // Read the user's choice
        int choice = scanner.nextInt();
        // Use a switch statement to handle the user's choice
        switch (choice) {
            case 1:
                // If the user chooses 1, read hue, saturation, and value
                double hue = scanner.nextDouble();
                double saturation = scanner.nextDouble();
                double value = scanner.nextDouble();
                // Convert HSV to RGB
                int[] rgb = hsvToRgb(hue, saturation, value);
                // Print the RGB values
                System.out.printf("RGB: [%d, %d, %d]%n", rgb[0], rgb[1], rgb[2]);
                break;
            case 2:
                // If the user chooses 2, read red, green, and blue values
                int red = scanner.nextInt();
                int green = scanner.nextInt();
                int blue = scanner.nextInt();
                // Convert RGB to HSV
                double[] hsv = rgbToHsv(red, green, blue);
                // Print the HSV values
                System.out.printf("HSV: [%.2f, %.2f, %.2f]%n", hsv[0], hsv[1], hsv[2]);
                break;
            default:
                // If the user chooses an invalid option, print an error message
                System.out.println("Invalid choice. Please choose 1 or 2.");
        }
        // Close the scanner to free up resources
        scanner.close();
    }
    // Function to convert HSV to RGB
    public static int[] hsvToRgb(double hue, double saturation, double value) {
        // Check if hue is within the valid range (0 to 360)
        if (hue < 0 || hue > 360) {
            throw new IllegalArgumentException("Hue should be between 0 and 360");
        }
        // Check if saturation is within the valid range (0 to 1)
        if (saturation < 0 || saturation > 1) {
            throw new IllegalArgumentException("Saturation should be between 0 and 1");
        }
        // Check if value is within the valid range (0 to 1)
        if (value < 0 || value > 1) {
            throw new IllegalArgumentException("Value should be between 0 and 1");
        }
        // Calculate the chroma
        double chroma = value * saturation;
        // Calculate the hue section
        double hueSection = hue / 60;
        // Calculate the second largest component
        double secondLargestComponent = chroma * (1 - Math.abs(hueSection % 2 - 1));
        // Calculate the match value
        double matchValue = value - chroma;
        // Return the RGB values by section
        return getRgbBySection(hueSection, chroma, matchValue, secondLargestComponent);
    }
    // Function to convert RGB to HSV
    public static double[] rgbToHsv(int red, int green, int blue) {
        // Check if RGB values are within the valid range (0 to 255)
        if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
            throw new IllegalArgumentException("RGB values should be between 0 and 255");
        }
        // Normalize RGB values to the range [0, 1]
        double dRed = red / 255.0;
        double dGreen = green / 255.0;
        double dBlue = blue / 255.0;
        // Find the maximum and minimum values among the normalized RGB values
        double max = Math.max(dRed, Math.max(dGreen, dBlue));
        double min = Math.min(dRed, Math.min(dGreen, dBlue));
        // Calculate the difference between the maximum and minimum values
        double delta = max - min;
        double hue;
        // Calculate the hue
        if (delta == 0) {
            hue = 0; 
        } else if (max == dRed) {
            hue = 60 * (((dGreen - dBlue) / delta) % 6);
        } else if (max == dGreen) {
            hue = 60 * (((dBlue - dRed) / delta) + 2);
        } else {
            hue = 60 * (((dRed - dGreen) / delta) + 4);
        }
        // Adjust the hue to be within the range [0, 360]
        hue = (hue + 360) % 360;
        // Calculate the saturation
        double saturation = max == 0 ? 0 : delta / max;
        // Return the HSV values
        return new double[]{hue, saturation, max};
    }
    // Helper function to get RGB values by section
    private static int[] getRgbBySection(double hueSection, double chroma, double matchValue, double secondLargestComponent) {
        int red, green, blue;
        // Determine the RGB values based on the hue section
        if (hueSection >= 0 && hueSection <= 1) {
            red = convertToInt(chroma + matchValue);
            green = convertToInt(secondLargestComponent + matchValue);
            blue = convertToInt(matchValue);
        } else if (hueSection > 1 && hueSection <= 2) {
            red = convertToInt(secondLargestComponent + matchValue);
            green = convertToInt(chroma + matchValue);
            blue = convertToInt(matchValue);
        } else if (hueSection > 2 && hueSection <= 3) {
            red = convertToInt(matchValue);
            green = convertToInt(chroma + matchValue);
            blue = convertToInt(secondLargestComponent + matchValue);
        } else if (hueSection > 3 && hueSection <= 4) {
            red = convertToInt(matchValue);
            green = convertToInt(secondLargestComponent + matchValue);
            blue = convertToInt(chroma + matchValue);
        } else if (hueSection > 4 && hueSection <= 5) {
            red = convertToInt(secondLargestComponent + matchValue);
            green = convertToInt(matchValue);
            blue = convertToInt(chroma + matchValue);
        } else {
            red = convertToInt(chroma + matchValue);
            green = convertToInt(matchValue);
            blue = convertToInt(secondLargestComponent + matchValue);
        }
        // Return the RGB values
        return new int[]{red, green, blue};
    }
    // Helper function to convert a double to an int, rounding appropriately
    private static int convertToInt(double input) {
        return (int) Math.round(input * 255);
    }
}