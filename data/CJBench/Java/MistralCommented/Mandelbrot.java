
import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.imageio.ImageIO;

public final class Main {
    private Main() {
    }

    // Main method to start the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            // Read input parameters from the user
            int imageWidth = Integer.parseInt(scanner.nextLine().trim());
            int imageHeight = Integer.parseInt(scanner.nextLine().trim());
            double figureCenterX = Double.parseDouble(scanner.nextLine().trim());
            double figureCenterY = Double.parseDouble(scanner.nextLine().trim());
            double figureWidth = Double.parseDouble(scanner.nextLine().trim());
            int maxStep = Integer.parseInt(scanner.nextLine().trim());
            boolean useColorCoding = Boolean.parseBoolean(scanner.nextLine().trim());
            String fileName = scanner.nextLine().trim();

            // Create an image with the given dimensions
            BufferedImage image = getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding);

            // Save the image to a file
            ImageIO.write(image, "png", new File(fileName));
            System.out.println("Main: Image saved to " + fileName);
        } catch (NumberFormatException e) {
            System.err.println("Error: Please enter valid numeric values. " + e.getMessage());
        } catch (IOException e) {
            System.err.println("Error saving the image: " + e.getMessage());
        } catch (IllegalArgumentException e) {
            System.err.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }

    // Method to create the image based on the input parameters
    public static BufferedImage getImage(int imageWidth, int imageHeight, double figureCenterX, double figureCenterY, double figureWidth, int maxStep, boolean useDistanceColorCoding) {
        if (imageWidth <= 0) {
            throw new IllegalArgumentException("imageWidth should be greater than zero");
        }

        if (imageHeight <= 0) {
            throw new IllegalArgumentException("imageHeight should be greater than zero");
        }

        if (maxStep <= 0) {
            throw new IllegalArgumentException("maxStep should be greater than zero");
        }

        // Initialize the image with the given dimensions and color type
        BufferedImage image = new BufferedImage(imageWidth, imageHeight, BufferedImage.TYPE_INT_RGB);

        double figureHeight = figureWidth / imageWidth * imageHeight;

        // Iterate through each pixel in the image and calculate its color based on the figure's position and distance
        for (int imageX = 0; imageX < imageWidth; imageX++) {
            for (int imageY = 0; imageY < imageHeight; imageY++) {
                double figureX = figureCenterX + ((double) imageX / imageWidth - 0.5) * figureWidth;
                double figureY = figureCenterY + ((double) imageY / imageHeight - 0.5) * figureHeight;
                double distance = getDistance(figureX, figureY, maxStep);

                // Set the pixel's color based on the useDistanceColorCoding flag
                if (useDistanceColorCoding) {
                    image.setRGB(imageX, imageY, colorCodedColorMap(distance).getRGB());
                } else {
                    image.setRGB(imageX, imageY, blackAndWhiteColorMap(distance).getRGB());
                }
            }
        }

        return image;
    }

    // Method to calculate the color based on the distance for color-coded images
    private static Color colorCodedColorMap(double distance) {
        if (distance >= 1) {
            return new Color(0, 0, 0);
        } else {
            double hue = 360 * distance;
            double saturation = 1;
            double val = 255;
            int hi = (int) (Math.floor(hue / 60)) % 6;
            double f = hue / 60 - Math.floor(hue / 60);
            int v = (int) val;
            int p = 0;
            int q = (int) (val * (1 - f * saturation));
            int t = (int) (val * (1 - (1 - f) * saturation));

            // Determine the RGB values based on the HSL color space
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

    // Method to calculate the distance between the figure and the pixel
    private static double getDistance(double figureX, double figureY, int maxStep) {
        double a = figureX;
        double b = figureY;
        int currentStep = 0;

        // Iterate through each step in the Mandelbrot set calculation
        for (int step = 0; step < maxStep; step++) {
            currentStep = step;
            double aNew = a * a - b * b + figureX;
            b = 2 * a * b + figureY;
            a = aNew;

            // If the distance exceeds a certain threshold, break the loop
            if (a * a + b * b > 4) {
                break;
            }
        }

        // Return the number of iterations as the distance
        return (double) currentStep / (maxStep - 1);
    }

    // Method to calculate the black-and-white color based on the distance
    private static Color blackAndWhiteColorMap(double distance) {
        return distance >= 1 ? new Color(0, 0, 0) : new Color(255, 255, 255);
    }
}