
import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the Main class
    int x; // Declaring instance variables x, y, and z with initial value 0
    int y;
    int z;

    Main() { // Default constructor with no arguments
        this.x = 0; // Initializing x, y, and z to 0
        this.y = 0;
        this.z = 0;
    }

    Main(int vectorX, int vectorY, int vectorZ) { // Constructor with three arguments
        this.x = vectorX; // Initializing x, y, and z with the given values
        this.y = vectorY;
        this.z = vectorZ;
    }

    double magnitude() { // Method to calculate the magnitude of the vector
        return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z); // Calculating the square of each component and then taking the square root
    }

    int dotProduct(Main b) { // Method to calculate the dot product of two vectors
        return this.x * b.x + this.y * b.y + this.z * b.z; // Multiplying corresponding components and summing them up
    }

    Main crossProduct(Main b) { // Method to calculate the cross product of two vectors
        Main product = new Main(); // Creating a new Main object to store the result
        product.x = (this.y * b.z) - (this.z * b.y); // Calculating the x component using the cross product formula
        product.y = -((this.x * b.z) - (this.z * b.x)); // Calculating the y component using the cross product formula
        product.z = (this.x * b.y) - (this.y * b.x); // Calculating the z component using the cross product formula
        return product; // Returning the result
    }

    void displayVector() { // Method to display the components of the vector
        System.out.println("x : " + this.x + "\ty : " + this.y + "\tz : " + this.z); // Printing the components of the vector
    }

    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for user input
        System.out.println("Enter the components of the first vector (x y z): "); // Asking the user to input the components of the first vector
        int x1 = scanner.nextInt(); // Reading the x component of the first vector from user input
        int y1 = scanner.nextInt(); // Reading the y component of the first vector from user input
        int z1 = scanner.nextInt(); // Reading the z component of the first vector from user input
        Main a = new Main(x1, y1, z1); // Creating a new Main object 'a' with the given components
        System.out.println("Enter the components of the second vector (x y z): "); // Asking the user to input the components of the second vector
        int x2 = scanner.nextInt(); // Reading the x component of the second vector from user input
        int y2 = scanner.nextInt(); // Reading the y component of the second vector from user input
        int z2 = scanner.nextInt(); // Reading the z component of the second vector from user input
        Main b = new Main(x2, y2, z2); // Creating a new Main object 'b' with the given components
        Main crossProd = a.crossProduct(b); // Calculating the cross product of vectors 'a' and 'b'
        System.out.println("Cross Product of the two vectors:"); // Printing the header for the cross product result
        crossProd.displayVector(); // Displaying the components of the cross product result
        int dotProd = a.dotProduct(b); // Calculating the dot product of vectors 'a' and 'b'
        System.out.println("Dot Product of the two vectors: " + dotProd); // Printing the dot product result
        System.out.printf("Magnitude of the first vector: %.2f%n", a.magnitude()); // Printing the magnitude of vector 'a' with two decimal places
        System.out.printf("Magnitude of the second vector: %.2f%n", b.magnitude()); // Printing the magnitude of vector 'b' with two decimal places
        scanner.close(); // Closing the Scanner object
    }
}