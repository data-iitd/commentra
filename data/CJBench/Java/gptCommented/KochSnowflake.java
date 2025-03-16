import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import javax.imageio.ImageIO;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a scanner to read user input
        Scanner scanner = new Scanner(System.in);
        
        // Read the width of the image and the number of iterations for the Koch snowflake
        int imageWidth = scanner.nextInt();
        int steps = scanner.nextInt();
        
        // Generate the Koch snowflake image
        BufferedImage image = getMain(imageWidth, steps);
        
        // Read the file path to save the image
        String filePath = scanner.next();
        
        // Attempt to save the generated image to the specified file path
        try {
            ImageIO.write(image, "png", new File(filePath));
            System.out.println("Koch snowflake saved to " + filePath);
        } catch (IOException e) {
            // Handle any exceptions that occur during image saving
            System.err.println("Failed to save the image: " + e.getMessage());
        }
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to perform the iteration steps for generating the Koch snowflake
    public static ArrayList<Vector2> iterate(ArrayList<Vector2> initialVectors, int steps) {
        ArrayList<Vector2> vectors = initialVectors;
        
        // Perform the specified number of iteration steps
        for (int i = 0; i < steps; i++) {
            vectors = iterationStep(vectors);
        }
        
        return vectors;
    }

    // Method to initialize the Koch snowflake and generate the image
    public static BufferedImage getMain(int imageWidth, int steps) {
        // Validate the image width
        if (imageWidth <= 0) {
            throw new IllegalArgumentException("imageWidth should be greater than zero");
        }
        
        // Calculate offsets for positioning the snowflake
        double offsetX = imageWidth / 10.0;
        double offsetY = imageWidth / 3.7;
        
        // Define the initial vertices of the Koch snowflake
        Vector2 vector1 = new Vector2(offsetX, offsetY);
        Vector2 vector2 = new Vector2(imageWidth / 2.0, Math.sin(Math.PI / 3.0) * imageWidth * 0.8 + offsetY);
        Vector2 vector3 = new Vector2(imageWidth - offsetX, offsetY);
        
        // Create a list to hold the initial vectors
        ArrayList<Vector2> initialVectors = new ArrayList<>();
        initialVectors.add(vector1);
        initialVectors.add(vector2);
        initialVectors.add(vector3);
        initialVectors.add(vector1); // Closing the shape
        
        // Perform iterations to generate the Koch snowflake vectors
        ArrayList<Vector2> vectors = iterate(initialVectors, steps);
        
        // Generate and return the image based on the calculated vectors
        return getImage(vectors, imageWidth, imageWidth);
    }

    // Method to perform a single iteration step on the vectors
    private static ArrayList<Vector2> iterationStep(List<Vector2> vectors) {
        ArrayList<Vector2> newVectors = new ArrayList<>();
        
        // Iterate through each pair of vectors to create new segments
        for (int i = 0; i < vectors.size() - 1; i++) {
            Vector2 startVector = vectors.get(i);
            Vector2 endVector = vectors.get(i + 1);
            newVectors.add(startVector); // Add the starting vector
            
            // Calculate the difference vector and create new points for the Koch curve
            Vector2 differenceVector = endVector.subtract(startVector).multiply(1.0 / 3);
            newVectors.add(startVector.add(differenceVector)); // First point
            newVectors.add(startVector.add(differenceVector).add(differenceVector.rotate(60))); // Peak of the triangle
            newVectors.add(startVector.add(differenceVector.multiply(2))); // Second point
        }
        
        // Add the last vector to close the shape
        newVectors.add(vectors.get(vectors.size() - 1));
        return newVectors;
    }

    // Method to create a BufferedImage from the list of vectors
    private static BufferedImage getImage(ArrayList<Vector2> vectors, int imageWidth, int imageHeight) {
        // Create a new BufferedImage
        BufferedImage image = new BufferedImage(imageWidth, imageHeight, BufferedImage.TYPE_INT_RGB);
        Graphics2D g2d = image.createGraphics();
        
        // Set the background color and fill the image
        g2d.setBackground(Color.WHITE);
        g2d.fillRect(0, 0, imageWidth, imageHeight);
        
        // Set the drawing color and stroke
        g2d.setColor(Color.BLACK);
        BasicStroke bs = new BasicStroke(1);
        g2d.setStroke(bs);
        
        // Draw lines between the vectors to create the Koch snowflake
        for (int i = 0; i < vectors.size() - 1; i++) {
            int x1 = (int) vectors.get(i).x;
            int y1 = (int) vectors.get(i).y;
            int x2 = (int) vectors.get(i + 1).x;
            int y2 = (int) vectors.get(i + 1).y;
            g2d.drawLine(x1, y1, x2, y2);
        }
        
        return image; // Return the generated image
    }

    // Inner class to represent a 2D vector
    private static class Vector2 {
        double x;
        double y;

        // Constructor to initialize the vector
        Vector2(double x, double y) {
            this.x = x;
            this.y = y;
        }

        // Override toString method for easy debugging
        @Override
        public String toString() {
            return String.format("[%f, %f]", this.x, this.y);
        }

        // Method to add another vector to this vector
        public Vector2 add(Vector2 vector) {
            double x = this.x + vector.x;
            double y = this.y + vector.y;
            return new Vector2(x, y);
        }

        // Method to subtract another vector from this vector
        public Vector2 subtract(Vector2 vector) {
            double x = this.x - vector.x;
            double y = this.y - vector.y;
            return new Vector2(x, y);
        }

        // Method to multiply this vector by a scalar
        public Vector2 multiply(double scalar) {
            double x = this.x * scalar;
            double y = this.y * scalar;
            return new Vector2(x, y);
        }

        // Method to rotate this vector by a given angle in degrees
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
