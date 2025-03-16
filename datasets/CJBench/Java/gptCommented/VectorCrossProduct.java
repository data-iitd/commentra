import java.util.Scanner;

public class Main {
    // Instance variables to hold the components of the vector
    int x;
    int y;
    int z;

    // Default constructor initializing vector components to zero
    Main() {
        x = 0;
        y = 0;
        z = 0;
    }

    // Parameterized constructor to initialize vector components with given values
    Main(int vectorX, int vectorY, int vectorZ) {
        x = vectorX;
        y = vectorY;
        z = vectorZ;
    }

    // Method to calculate and return the magnitude of the vector
    double magnitude() {
        return Math.sqrt(x * x + y * y + z * z);
    }

    // Method to calculate and return the dot product of this vector with another vector
    int dotProduct(Main b) {
        return x * b.x + y * b.y + z * b.z;
    }

    // Method to calculate and return the cross product of this vector with another vector
    Main crossProduct(Main b) {
        Main product = new Main();
        // Calculate the components of the cross product
        product.x = (y * b.z) - (z * b.y);
        product.y = -((x * b.z) - (z * b.x));
        product.z = (x * b.y) - (y * b.x);
        return product;
    }

    // Method to display the vector components
    void displayVector() {
        System.out.println("x : " + x + "\ty : " + y + "\tz : " + z);
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Prompt user to enter the components of the first vector
        System.out.println("Enter the components of the first vector (x y z): ");
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        int z1 = scanner.nextInt();
        
        // Create the first vector using user input
        Main a = new Main(x1, y1, z1);
        
        // Prompt user to enter the components of the second vector
        System.out.println("Enter the components of the second vector (x y z): ");
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();
        int z2 = scanner.nextInt();
        
        // Create the second vector using user input
        Main b = new Main(x2, y2, z2);
        
        // Calculate and display the cross product of the two vectors
        Main crossProd = a.crossProduct(b);
        System.out.println("Cross Product of the two vectors:");
        crossProd.displayVector();
        
        // Calculate and display the dot product of the two vectors
        int dotProd = a.dotProduct(b);
        System.out.println("Dot Product of the two vectors: " + dotProd);
        
        // Calculate and display the magnitude of the first vector
        System.out.printf("Magnitude of the first vector: %.2f%n", a.magnitude());
        
        // Calculate and display the magnitude of the second vector
        System.out.printf("Magnitude of the second vector: %.2f%n", b.magnitude());
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
