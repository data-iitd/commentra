import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the user's choice for conversion type
        int choice = scanner.nextInt();
        
        // Switch statement to handle different conversion options
        switch (choice) {
            case 1:
                // Case 1: Convert HSV to RGB
                double hue = scanner.nextDouble(); // Read hue value
                double saturation = scanner.nextDouble(); // Read saturation value
                double value = scanner.nextDouble(); // Read value (brightness)
                
                // Convert HSV to RGB
                int[] rgb = hsvToRgb(hue, saturation, value);
                
                // Output the RGB values
                System.out.printf("RGB: [%d, %d, %d]%n", rgb[0], rgb[1], rgb[2]);
                break;
            case 2:
                // Case 2: Convert RGB to HSV
                int red = scanner.nextInt(); // Read red value
                int green = scanner.nextInt(); // Read green value
                int blue = scanner.nextInt(); // Read blue value
                
                // Convert RGB to HSV
                double[] hsv = rgbToHsv(red, green, blue);
                
                // Output the HSV values
                System.out.printf("HSV: [%.2f, %.2f, %.2f]%n", hsv[0], hsv[1], hsv[2]);
                break;
            default:
                // Handle invalid choice
                System.out.println("Invalid choice. Please choose 1 or 2.");
        }
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to convert HSV to RGB
    public static int[] hsvToRgb(double hue, double saturation, double value) {
        // Validate hue, saturation, and value ranges
        if (hue < 0 || hue > 360) {
            throw new IllegalArgumentException("Hue should be between 0 and 360");
        }
        if (saturation < 0 || saturation > 1) {
            throw new IllegalArgumentException("Saturation should be between 0 and 1");
        }
        if (value < 0 || value > 1) {
            throw new IllegalArgumentException("Value should be between 0 and 1");
        }
        
        // Calculate chroma and other components for RGB conversion
        double chroma = value * saturation;
        double hueSection = hue / 60;
        double secondLargestComponent = chroma * (1 - Math.abs(hueSection % 2 - 1));
        double matchValue = value - chroma;
        
        // Get RGB values based on hue section
        return getRgbBySection(hueSection, chroma, matchValue, secondLargestComponent);
    }

    // Method to convert RGB to HSV
    public static double[] rgbToHsv(int red, int green, int blue) {
        // Validate RGB value ranges
        if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
            throw new IllegalArgumentException("RGB values should be between 0 and 255");
        }
        
        // Normalize RGB values to [0, 1]
        double dRed = red / 255.0;
        double dGreen = green / 255.0;
        double dBlue = blue / 255.0;
        
        // Calculate max and min values for HSV conversion
        double max = Math.max(dRed, Math.max(dGreen, dBlue));
        double min = Math.min(dRed, Math.min(dGreen, dBlue));
        double delta = max - min;
        double hue;
        
        // Calculate hue based on the maximum RGB component
        if (delta == 0) {
            hue = 0; 
        } else if (max == dRed) {
            hue = 60 * (((dGreen - dBlue) / delta) % 6);
        } else if (max == dGreen) {
            hue = 60 * (((dBlue - dRed) / delta) + 2);
        } else {
            hue = 60 * (((dRed - dGreen) / delta) + 4);
        }
        
        // Normalize hue to [0, 360]
        hue = (hue + 360) % 360;
        
        // Calculate saturation
        double saturation = max == 0 ? 0 : delta / max;
        
        // Return HSV values
        return new double[]{hue, saturation, max};
    }

    // Helper method to determine RGB values based on hue section
    private static int[] getRgbBySection(double hueSection, double chroma, double matchValue, double secondLargestComponent) {
        int red, green, blue;
        
        // Determine RGB values based on the hue section
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
        
        // Return the RGB values as an array
        return new int[]{red, green, blue};
    }

    // Helper method to convert a normalized value to an integer RGB value
    private static int convertToInt(double input) {
        return (int) Math.round(input * 255);
    }
}
