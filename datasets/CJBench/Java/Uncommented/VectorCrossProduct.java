
import java.util.Scanner;
public class VectorCrossProduct {
    int x;
    int y;
    int z;
    VectorCrossProduct() {
        x = 0;
        y = 0;
        z = 0;
    }
    VectorCrossProduct(int vectorX, int vectorY, int vectorZ) {
        x = vectorX;
        y = vectorY;
        z = vectorZ;
    }
    double magnitude() {
        return Math.sqrt(x * x + y * y + z * z);
    }
    int dotProduct(VectorCrossProduct b) {
        return x * b.x + y * b.y + z * b.z;
    }
    VectorCrossProduct crossProduct(VectorCrossProduct b) {
        VectorCrossProduct product = new VectorCrossProduct();
        product.x = (y * b.z) - (z * b.y);
        product.y = -((x * b.z) - (z * b.x));
        product.z = (x * b.y) - (y * b.x);
        return product;
    }
    void displayVector() {
        System.out.println("x : " + x + "\ty : " + y + "\tz : " + z);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the components of the first vector (x y z): ");
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        int z1 = scanner.nextInt();
        VectorCrossProduct a = new VectorCrossProduct(x1, y1, z1);
        System.out.println("Enter the components of the second vector (x y z): ");
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();
        int z2 = scanner.nextInt();
        VectorCrossProduct b = new VectorCrossProduct(x2, y2, z2);
        VectorCrossProduct crossProd = a.crossProduct(b);
        System.out.println("Cross Product of the two vectors:");
        crossProd.displayVector();
        int dotProd = a.dotProduct(b);
        System.out.println("Dot Product of the two vectors: " + dotProd);
        System.out.printf("Magnitude of the first vector: %.2f%n", a.magnitude());
        System.out.printf("Magnitude of the second vector: %.2f%n", b.magnitude());
        scanner.close();
    }
}
