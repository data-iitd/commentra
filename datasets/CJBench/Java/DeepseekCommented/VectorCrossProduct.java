import java.util.Scanner;

public class Main {
    int x; // x-component of the vector
    int y; // y-component of the vector
    int z; // z-component of the vector

    // No-argument constructor initializes the vector components to 0
    Main() {
        x = 0;
        y = 0;
        z = 0;
    }

    // Parameterized constructor initializes the vector components to the provided values
    Main(int vectorX, int vectorY, int vectorZ) {
        x = vectorX;
        y = vectorY;
        z = vectorZ;
    }

    // Calculates the magnitude of the vector using the Euclidean norm formula
    double magnitude() {
        return Math.sqrt(x * x + y * y + z * z);
    }

    // Computes the dot product of the current vector with another vector b
    int dotProduct(Main b) {
        return x * b.x + y * b.y + z * b.z;
    }

    // Computes the cross product of the current vector with another vector b
    Main crossProduct(Main b) {
        Main product = new Main();
        product.x = (y * b.z) - (z * b.y);
        product.y = -((x * b.z) - (z * b.x));
        product.z = (x * b.y) - (y * b.x);
        return product;
    }

    // Prints the components of the vector
    void displayVector() {
        System.out.println("x : " + x + "\ty : " + y + "\tz : " + z);
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the components of the first vector (x y z): ");
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        int z1 = scanner.nextInt();
        Main a = new Main(x1, y1, z1); // Create first vector
        System.out.println("Enter the components of the second vector (x y z): ");
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();
        int z2 = scanner.nextInt();
        Main b = new Main(x2, y2, z2); // Create second vector
        Main crossProd = a.crossProduct(b); // Calculate cross product
        System.out.println("Cross Product of the two vectors:");
        crossProd.displayVector(); // Display cross product
        int dotProd = a.dotProduct(b); // Calculate dot product
        System.out.println("Dot Product of the two vectors: " + dotProd); // Display dot product
        System.out.printf("Magnitude of the first vector: %.2f%n", a.magnitude()); // Display magnitude of first vector
        System.out.printf("Magnitude of the second vector: %.2f%n", b.magnitude()); // Display magnitude of second vector
        scanner.close(); // Close the scanner
    }
}
