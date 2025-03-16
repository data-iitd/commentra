
import java.awt.BasicStoke;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import javax.imageio.ImageIO;

/**
 * This class generates a Koch snowflake image based on user input.
 */
public final class Main {

    private Main() {
    }

    /**
     * Entry point of the application. Reads user input and generates the Koch snowflake image.
     *
     * @param args command line arguments (ignored)
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // create a new Scanner object to read user input

        // read image width and steps from user input
        int imageWidth = scanner.nextInt();
        int steps = scanner.nextInt();

        // generate the Koch snowflake image
        BufferedImage image = getMain(imageWidth, steps);

        // read file path from user input and save the image
        String filePath = scanner.next();
        try {
            ImageIO.write(image, "png", new File(filePath));
            System.out.println("Koch snowflake saved to " + filePath);
        } catch (IOException e) {
            System.err.println("Failed to save the image: " + e.getMessage());
        }

        scanner.close(); // close the Scanner object
    }

    /**
     * Iterates the given initial vectors a specified number of times.
     *
     * @param initialVectors the initial vectors
     * @param steps the number of iteration steps
     * @return the resulting vectors after the specified number of iteration steps
     */
    public static ArrayList<Vector2> iterate(ArrayList<Vector2> initialVectors, int steps) {
        ArrayList<Vector2> vectors = initialVectors; // store the initial vectors in a local variable

        // iterate the given vectors a specified number of times
        for (int i = 0; i < steps; i++) {
            vectors = iterationStep(vectors);
        }

        // return the resulting vectors after the specified number of iteration steps
        return vectors;
    }

    /**
     * Performs one iteration step on the given vectors.
     *
     * @param vectors the vectors to be processed in this iteration step
     * @return the new vectors after this iteration step
     */
    public static ArrayList<Vector2> iterationStep(List<Vector2> vectors) {
        ArrayList<Vector2> newVectors = new ArrayList<>(); // create a new ArrayList to store the new vectors

        // iterate through each vector in the input list, except the last one
        for (int i = 0; i < vectors.size() - 1; i++) {
            // get the current vector
            Vector2 startVector = vectors.get(i);

            // get the next vector
            Vector2 endVector = vectors.get(i + 1);

            // add the current vector to the new ArrayList
            newVectors.add(startVector);

            // calculate the difference vector between the current and next vectors
            Vector2 differenceVector = endVector.subtract(startVector);

            // add the scaled difference vector to the current vector and add it to the new ArrayList
            newVectors.add(startVector.add(differenceVector.multiply(1.0 / 3)));

            // add the rotated difference vector to the current vector and add it to the new ArrayList
            newVectors.add(startVector.add(differenceVector.rotate(60)));

            // add the doubled difference vector to the current vector and add it to the new ArrayList
            newVectors.add(startVector.add(differenceVector.multiply(2)));
        }

        // add the last vector to the new ArrayList
        newVectors.add(vectors.get(vectors.size() - 1));

        // return the new vectors after this iteration step
        return newVectors;
    }

    /**
     * Generates a BufferedImage of the given Koch snowflake vectors.
     *
     * @param vectors the Koch snowflake vectors
     * @param imageWidth the width of the output image
     * @param imageHeight the height of the output image
     * @return the BufferedImage of the Koch snowflake
     */
    public static BufferedImage getMain(int imageWidth, int steps) {
        if (imageWidth <= 0) { // check if the image width is valid
            throw new IllegalArgumentException("imageWidth should be greater than zero");
        }

        // calculate offsetX and offsetY based on the image width
        double offsetX = imageWidth / 10.0;
        double offsetY = imageWidth / 3.7;

        // create the first three vectors
        Vector2 vector1 = new Vector2(offsetX, offsetY);
        Vector2 vector2 = new Vector2(imageWidth / 2.0, Math.sin(Math.PI / 3.0) * imageWidth * 0.8 + offsetY);
        Vector2 vector3 = new Vector2(imageWidth - offsetX, offsetY);

        // create an ArrayList to store the initial vectors
        ArrayList<Vector2> initialVectors = new ArrayList<>();
        initialVectors.add(vector1);
        initialVectors.add(vector2);
        initialVectors.add(vector3);
        initialVectors.add(vector1);

        // iterate the vectors to generate the Koch snowflake
        ArrayList<Vector2> vectors = iterate(initialVectors, steps);

        // generate the BufferedImage of the Koch snowflake
        return getImage(vectors, imageWidth, imageWidth);
    }

    /**
     * Generates a BufferedImage of the given Koch snowflake vectors.
     *
     * @param vectors the Koch snowflake vectors
     * @param imageWidth the width of the output image
     * @param imageHeight the height of the output image
     * @return the BufferedImage of the Koch snowflake
     */
    private static BufferedImage getImage(ArrayList<Vector2> vectors, int imageWidth, int imageHeight) {
        BufferedImage image = new BufferedImage(imageWidth, imageHeight, BufferedImage.TYPE_INT_RGB); // create a new BufferedImage

        Graphics2D g2d = image.createGraphics(); // create a Graphics2D object to draw on the BufferedImage

        g2d.setBackground(Color.WHITE); // set the background color to white
        g2d.fillRect(0, 0, imageWidth, imageHeight); // fill the entire image with the background color

        g2d.setColor(Color.BLACK); // set the drawing color to black
        BasicStroke bs = new BasicStroke(1); // create a BasicStroke object with a line width of 1
        g2d.setStroke(bs); // set the stroke for drawing lines

        // draw lines between consecutive vectors
        for (int i = 0; i < vectors.size() - 1; i++) {
            int x1 = (int) vectors.get(i).x; // get the x and y coordinates of the current and next vectors
            int y1 = (int) vectors.get(i).y;
            int x2 = (int) vectors.get(i + 1).x;
            int y2 = (int) vectors.get(i + 1).y;
            g2d.drawLine(x1, y1, x2, y2); // draw a line between the current and next vectors
        }

        return image; // return the BufferedImage of the Koch snowflake
    }

    /**
     * A simple 2D vector class with methods for addition, subtraction, multiplication, and rotation.
     */
    private static class Vector2 {
        double x;
        double y;

        /**
         * Constructs a new Vector2 object with the given x and y coordinates.
         *
         * @param x the x coordinate
         * @param y the y coordinate
         */
        Vector2(double x, double y) {
            this.x = x;
            this.y = y;
        }

        /**
         * Returns a string representation of this Vector2 object.
         *
         * @return a string representation of this Vector2 object
         */
        @Override
        public String toString() {
            return String.format("[%f, %f]", this.x, this.y);
        }

        /**
         * Adds two Vector2 objects.
         *
         * @param vector the Vector2 object to add
         * @return the sum of this Vector2 object and the given Vector2 object
         */
        public Vector2 add(Vector2 vector) {
            double x = this.x + vector.x;
            double y = this.y + vector.y;
            return new Vector2(x, y);
        }

        /**
         * Subtracts two Vector2 objects.
         *
         * @param vector the Vector2 object to subtract
         * @return the difference of this Vector2 object and the given Vector2 object
         */
        public Vector2 subtract(Vector2 vector) {
            double x = this.x - vector.x;
            double y = this.y - vector.y;
            return new Vector2(x, y);
        }

        /**
         * Multiplies a Vector2 object by a scalar value.
         *
         * @param scalar the scalar value
         * @return the product of this Vector2 object and the given scalar value
         */
        public Vector2 multiply(double scalar) {
            double x = this.x * scalar;
            double y = this.y * scalar;
            return new Vector2(x, y);
        }

        /**
         * Rotates a Vector2 object by the given angle in degrees.
         *
         * @param angleInDegrees the angle in degrees
         * @return the rotated Vector2 object
         */
        public Vector2 rotate(double angleInDegrees) {
            double radians = angleInDegrees * Math.PI / 180;
            double ca = Math.cos(radians);
            double sa = Math.sin(radians);
            double x = ca * this.x - sa * this.y;
            double y = sa * this.x + ca * this.y;
            return new Vector2(x, y);
        }
    }
}