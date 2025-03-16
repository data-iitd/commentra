
import java.util.Scanner;

/**
 * This class calculates the cross product, dot product, and magnitude of two 3D vectors.
 */
public class VectorCrossProduct {

    int x;
    int y;
    int z;

    // Default constructor, initializes all three direction ratios to 0
    VectorCrossProduct() {
        x = 0;
        y = 0;
        z = 0;
    }

    /**
     * Constructor to initialize vector with given direction ratios
     *
     * @param vectorX set to x
     * @param vectorY set to y
     * @param vectorZ set to z
     */
    VectorCrossProduct(int vectorX, int vectorY, int vectorZ) {
        x = vectorX;
        y = vectorY;
        z = vectorZ;
    }

    /**
     * Returns the magnitude of the vector
     *
     * @return double
     */
    double magnitude() {
        return Math.sqrt(x * x + y * y + z * z);
    }

    /**
     * Returns the dot product of the current vector with a given vector
     *
     * @param b: the second vector
     * @return int: the dot product
     */
    int dotProduct(VectorCrossProduct b) {
        return x * b.x + y * b.y + z * b.z;
    }

    /**
     * Returns the cross product of the current vector with a given vector
     *
     * @param b: the second vector
     * @return VectorCrossProduct: the cross product
     */
    VectorCrossProduct crossProduct(VectorCrossProduct b) {
        VectorCrossProduct product = new VectorCrossProduct();
        product.x = (y * b.z) - (z * b.y);
        product.y = -((x * b.z) - (z * b.x));
        product.z = (x * b.y) - (y * b.x);
        return product;
    }

    /**
     * Display the vector
     */
    void displayVector() {
        System.out.println("x : " + x + "\ty : " + y + "\tz : " + z);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input first vector
        System.out.println("Enter the components of the first vector (x y z): ");
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        int z1 = scanner.nextInt();
        VectorCrossProduct a = new VectorCrossProduct(x1, y1, z1);

        // Input second vector
        System.out.println("Enter the components of the second vector (x y z): ");
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();
        int z2 = scanner.nextInt();
        VectorCrossProduct b = new VectorCrossProduct(x2, y2, z2);

        // Determine cross product
        VectorCrossProduct crossProd = a.crossProduct(b);
        System.out.println("Cross Product of the two vectors:");
        crossProd.displayVector();

        // Determine dot product
        int dotProd = a.dotProduct(b);
        System.out.println("Dot Product of the two vectors: " + dotProd);

        // Display magnitudes
        System.out.printf("Magnitude of the first vector: %.2f%n", a.magnitude());
        System.out.printf("Magnitude of the second vector: %.2f%n", b.magnitude());

        scanner.close();
    }
}
