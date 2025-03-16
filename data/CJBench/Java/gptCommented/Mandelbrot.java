import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.imageio.ImageIO;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a scanner to read user input
        Scanner scanner = new Scanner(System.in);
        try {
            // Read image dimensions and figure parameters from user input
            int imageWidth = Integer.parseInt(scanner.nextLine().trim());
            int imageHeight = Integer.parseInt(scanner.nextLine().trim());
            double figureCenterX = Double.parseDouble(scanner.nextLine().trim());
            double figureCenterY = Double.parseDouble(scanner.nextLine().trim());
            double figureWidth = Double.parseDouble(scanner.nextLine().trim());
            int maxStep = Integer.parseInt(scanner.nextLine().trim());
            boolean useColorCoding = Boolean.parseBoolean(scanner.nextLine().trim());
            String fileName = scanner.nextLine().trim();

            // Generate the image based on the provided parameters
            BufferedImage image = getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding);

            // Save the generated image to the specified file
            ImageIO.write(image, "png", new File(fileName));
            System.out.println("Main set image saved to " + fileName);
        } catch (NumberFormatException e) {
            // Handle invalid numeric input
            System.err.println("Error: Please enter valid numeric values. " + e.getMessage());
        } catch (IOException e) {
            // Handle errors during image saving
            System.err.println("Error saving the image: " + e.getMessage());
        } catch (IllegalArgumentException e) {
            // Handle illegal argument exceptions
            System.err.println("Error: " + e.getMessage());
        } finally {
            // Close the scanner to free resources
            scanner.close();
        }
    }

    public static BufferedImage getImage(int imageWidth, int imageHeight, double figureCenterX, double figureCenterY, double figureWidth, int maxStep, boolean useDistanceColorCoding) {
        // Validate input parameters for image dimensions and max steps
        if (imageWidth <= 0) {
            throw new IllegalArgumentException("imageWidth should be greater than zero");
        }
        if (imageHeight <= 0) {
            throw new IllegalArgumentException("imageHeight should be greater than zero");
        }
        if (maxStep <= 0) {
            throw new IllegalArgumentException("maxStep should be greater than zero");
        }

        // Create a new BufferedImage to hold the generated image
        BufferedImage image = new BufferedImage(imageWidth, imageHeight, BufferedImage.TYPE_INT_RGB);
        double figureHeight = figureWidth / imageWidth * imageHeight; // Calculate figure height based on aspect ratio

        // Loop through each pixel in the image
        for (int imageX = 0; imageX < imageWidth; imageX++) {
            for (int imageY = 0; imageY < imageHeight; imageY++) {
                // Calculate the corresponding figure coordinates for the current pixel
                double figureX = figureCenterX + ((double) imageX / imageWidth - 0.5) * figureWidth;
                double figureY = figureCenterY + ((double) imageY / imageHeight - 0.5) * figureHeight;

                // Calculate the distance for color mapping
                double distance = getDistance(figureX, figureY, maxStep);

                // Set the pixel color based on the distance and color coding preference
                image.setRGB(imageX, imageY, useDistanceColorCoding ? colorCodedColorMap(distance).getRGB() : blackAndWhiteColorMap(distance).getRGB());
            }
        }
        return image; // Return the generated image
    }

    // Method to generate a black and white color map based on distance
    private static Color blackAndWhiteColorMap(double distance) {
        return distance >= 1 ? new Color(0, 0, 0) : new Color(255, 255, 255);
    }

    // Method to generate a color-coded color map based on distance
    private static Color colorCodedColorMap(double distance) {
        if (distance >= 1) {
            return new Color(0, 0, 0); // Black for distances >= 1
        } else {
            // Calculate hue, saturation, and value for color coding
            double hue = 360 * distance;
            double saturation = 1;
            double val = 255;
            int hi = (int) (Math.floor(hue / 60)) % 6;
            double f = hue / 60 - Math.floor(hue / 60);
            int v = (int) val;
            int p = 0;
            int q = (int) (val * (1 - f * saturation));
            int t = (int) (val * (1 - (1 - f) * saturation));

            // Determine the RGB color based on the hue
            switch (hi) {
                case 0:
                    return new Color(v, t, p);
                case 1:
                    return new Color(q, v, p);
                case 2:
                    return new Color(p, v, t);
                case 3:
                    return new Color(p, q, v);
                case 4:
                    return new Color(t, p, v);
                default:
                    return new Color(v, p, q);
            }
        }
    }

    // Method to calculate the distance for the given figure coordinates
    private static double getDistance(double figureX, double figureY, int maxStep) {
        double a = figureX;
        double b = figureY;
        int currentStep = 0;

        // Iterate to determine the escape time for the point
        for (int step = 0; step < maxStep; step++) {
            currentStep = step;
            double aNew = a * a - b * b + figureX; // Update a based on the Mandelbrot formula
            b = 2 * a * b + figureY; // Update b based on the Mandelbrot formula
            a = aNew;

            // Check if the point escapes the boundary
            if (a * a + b * b > 4) {
                break; // Exit if the point escapes
            }
        }
        return (double) currentStep / (maxStep - 1); // Return normalized distance
    }
}
