
import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.imageio.ImageIO;

/**
 * The Mandelbrot set is the set of complex numbers "c" for which the series
 * "z_(n+1) = z_n * z_n + c" does not diverge, i.e. remains bounded. Thus, a
 * complex number "c" is a member of the Mandelbrot set if, when starting with
 * "z_0 = 0" and applying the iteration repeatedly, the absolute value of "z_n"
 * remains bounded for all "n > 0". Complex numbers can be written as "a + b*i":
 * "a" is the real component, usually drawn on the x-axis, and "b*i" is the
 * imaginary component, usually drawn on the y-axis. Most visualizations of the
 * Mandelbrot set use a color-coding to indicate after how many steps in the
 * series the numbers outside the set cross the divergence threshold. Images of
 * the Mandelbrot set exhibit an elaborate and infinitely complicated boundary
 * that reveals progressively ever-finer recursive detail at increasing
 * magnifications, making the boundary of the Mandelbrot set a fractal curve.
 * (description adapted from https://en.wikipedia.org/wiki/Mandelbrot_set ) (see
 * also https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set
 * )
 */
public final class Mandelbrot {
    private Mandelbrot() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            int imageWidth = Integer.parseInt(scanner.nextLine().trim());

            int imageHeight = Integer.parseInt(scanner.nextLine().trim());

            double figureCenterX = Double.parseDouble(scanner.nextLine().trim());

            double figureCenterY = Double.parseDouble(scanner.nextLine().trim());

            double figureWidth = Double.parseDouble(scanner.nextLine().trim());

            int maxStep = Integer.parseInt(scanner.nextLine().trim());

            boolean useColorCoding = Boolean.parseBoolean(scanner.nextLine().trim());

            String fileName = scanner.nextLine().trim();

            BufferedImage image = getImage(imageWidth, imageHeight, figureCenterX, figureCenterY, figureWidth, maxStep, useColorCoding);
            ImageIO.write(image, "png", new File(fileName));
            System.out.println("Mandelbrot set image saved to " + fileName);
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

    /**
     * Method to generate the image of the Mandelbrot set. Two types of
     * coordinates are used: image-coordinates that refer to the pixels and
     * figure-coordinates that refer to the complex numbers inside and outside
     * the Mandelbrot set. The figure-coordinates in the arguments of this
     * method determine which section of the Mandelbrot set is viewed. The main
     * area of the Mandelbrot set is roughly between "-1.5 < x < 0.5" and "-1 <
     * y < 1" in the figure-coordinates.
     *
     * @param imageWidth The width of the rendered image.
     * @param imageHeight The height of the rendered image.
     * @param figureCenterX The x-coordinate of the center of the figure.
     * @param figureCenterY The y-coordinate of the center of the figure.
     * @param figureWidth The width of the figure.
     * @param maxStep Maximum number of steps to check for divergent behavior.
     * @param useDistanceColorCoding Render in color or black and white.
     * @return The image of the rendered Mandelbrot set.
     */
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

        BufferedImage image = new BufferedImage(imageWidth, imageHeight, BufferedImage.TYPE_INT_RGB);
        double figureHeight = figureWidth / imageWidth * imageHeight;

        for (int imageX = 0; imageX < imageWidth; imageX++) {
            for (int imageY = 0; imageY < imageHeight; imageY++) {
                double figureX = figureCenterX + ((double) imageX / imageWidth - 0.5) * figureWidth;
                double figureY = figureCenterY + ((double) imageY / imageHeight - 0.5) * figureHeight;

                double distance = getDistance(figureX, figureY, maxStep);

                image.setRGB(imageX, imageY, useDistanceColorCoding ? colorCodedColorMap(distance).getRGB() : blackAndWhiteColorMap(distance).getRGB());
            }
        }

        return image;
    }

    /**
     * Black and white color-coding that ignores the relative distance. The
     * Mandelbrot set is black, everything else is white.
     *
     * @param distance Distance until divergence threshold
     * @return The color corresponding to the distance.
     */
    private static Color blackAndWhiteColorMap(double distance) {
        return distance >= 1 ? new Color(0, 0, 0) : new Color(255, 255, 255);
    }

    /**
     * Color-coding taking the relative distance into account. The Mandelbrot
     * set is black.
     *
     * @param distance Distance until divergence threshold.
     * @return The color corresponding to the distance.
     */
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

    /**
     * Return the relative distance (ratio of steps taken to maxStep) after
     * which the complex number constituted by this x-y-pair diverges. Members
     * of the Mandelbrot set do not diverge so their distance is 1.
     *
     * @param figureX The x-coordinate within the figure.
     * @param figureX The y-coordinate within the figure.
     * @param maxStep Maximum number of steps to check for divergent behavior.
     * @return The relative distance as the ratio of steps taken to maxStep.
     */
    private static double getDistance(double figureX, double figureY, int maxStep) {
        double a = figureX;
        double b = figureY;
        int currentStep = 0;
        for (int step = 0; step < maxStep; step++) {
            currentStep = step;
            double aNew = a * a - b * b + figureX;
            b = 2 * a * b + figureY;
            a = aNew;

            if (a * a + b * b > 4) {
                break;
            }
        }
        return (double) currentStep / (maxStep - 1);
    }
}
