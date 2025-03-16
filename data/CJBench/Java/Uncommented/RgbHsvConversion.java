
import java.util.Scanner;
public final class RgbHsvConversion {
    private RgbHsvConversion() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();
        switch (choice) {
            case 1:
                double hue = scanner.nextDouble();
                double saturation = scanner.nextDouble();
                double value = scanner.nextDouble();
                int[] rgb = hsvToRgb(hue, saturation, value);
                System.out.printf("RGB: [%d, %d, %d]%n", rgb[0], rgb[1], rgb[2]);
                break;
            case 2:
                int red = scanner.nextInt();
                int green = scanner.nextInt();
                int blue = scanner.nextInt();
                double[] hsv = rgbToHsv(red, green, blue);
                System.out.printf("HSV: [%.2f, %.2f, %.2f]%n", hsv[0], hsv[1], hsv[2]);
                break;
            default:
                System.out.println("Invalid choice. Please choose 1 or 2.");
        }
        scanner.close();
    }
    public static int[] hsvToRgb(double hue, double saturation, double value) {
        if (hue < 0 || hue > 360) {
            throw new IllegalArgumentException("Hue should be between 0 and 360");
        }
        if (saturation < 0 || saturation > 1) {
            throw new IllegalArgumentException("Saturation should be between 0 and 1");
        }
        if (value < 0 || value > 1) {
            throw new IllegalArgumentException("Value should be between 0 and 1");
        }
        double chroma = value * saturation;
        double hueSection = hue / 60;
        double secondLargestComponent = chroma * (1 - Math.abs(hueSection % 2 - 1));
        double matchValue = value - chroma;
        return getRgbBySection(hueSection, chroma, matchValue, secondLargestComponent);
    }
    public static double[] rgbToHsv(int red, int green, int blue) {
        if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
            throw new IllegalArgumentException("RGB values should be between 0 and 255");
        }
        double dRed = red / 255.0;
        double dGreen = green / 255.0;
        double dBlue = blue / 255.0;
        double max = Math.max(dRed, Math.max(dGreen, dBlue));
        double min = Math.min(dRed, Math.min(dGreen, dBlue));
        double delta = max - min;
        double hue;
        if (delta == 0) {
            hue = 0; 
        } else if (max == dRed) {
            hue = 60 * (((dGreen - dBlue) / delta) % 6);
        } else if (max == dGreen) {
            hue = 60 * (((dBlue - dRed) / delta) + 2);
        } else {
            hue = 60 * (((dRed - dGreen) / delta) + 4);
        }
        hue = (hue + 360) % 360;
        double saturation = max == 0 ? 0 : delta / max;
        return new double[]{hue, saturation, max};
    }
    private static int[] getRgbBySection(double hueSection, double chroma, double matchValue, double secondLargestComponent) {
        int red, green, blue;
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
        return new int[]{red, green, blue};
    }
    private static int convertToInt(double input) {
        return (int) Math.round(input * 255);
    }
}
