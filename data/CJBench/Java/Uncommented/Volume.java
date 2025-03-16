import java.util.Scanner;
public final class Volume {
    private Volume() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            int choice = scanner.nextInt();
            double volume = 0;
            switch (choice) {
                case 1:
                    double side = scanner.nextDouble();
                    volume = volumeCube(side);
                    break;
                case 2:
                    double width = scanner.nextDouble();
                    double height = scanner.nextDouble();
                    double length = scanner.nextDouble();
                    volume = volumeCuboid(width, height, length);
                    break;
                case 3:
                    double radius = scanner.nextDouble();
                    volume = volumeSphere(radius);
                    break;
                case 4:
                    double radiusCyl = scanner.nextDouble();
                    double heightCyl = scanner.nextDouble();
                    volume = volumeCylinder(radiusCyl, heightCyl);
                    break;
                case 5:
                    double radiusHem = scanner.nextDouble();
                    volume = volumeHemisphere(radiusHem);
                    break;
                case 6:
                    double radiusCone = scanner.nextDouble();
                    double heightCone = scanner.nextDouble();
                    volume = volumeCone(radiusCone, heightCone);
                    break;
                case 7:
                    double baseAreaPrism = scanner.nextDouble();
                    double heightPrism = scanner.nextDouble();
                    volume = volumePrism(baseAreaPrism, heightPrism);
                    break;
                case 8:
                    double baseAreaPyr = scanner.nextDouble();
                    double heightPyr = scanner.nextDouble();
                    volume = volumePyramid(baseAreaPyr, heightPyr);
                    break;
                case 9:
                    double r1 = scanner.nextDouble();
                    double r2 = scanner.nextDouble();
                    double heightFrustum = scanner.nextDouble();
                    volume = volumeFrustumOfCone(r1, r2, heightFrustum);
                    break;
                default:
                    return; 
            }
            System.out.printf("%.2f%n", volume);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
    public static double volumeCube(double sideLength) {
        return sideLength * sideLength * sideLength;
    }
    public static double volumeCuboid(double width, double height, double length) {
        return width * height * length;
    }
    public static double volumeSphere(double radius) {
        return (4 * Math.PI * radius * radius * radius) / 3;
    }
    public static double volumeCylinder(double radius, double height) {
        return Math.PI * radius * radius * height;
    }
    public static double volumeHemisphere(double radius) {
        return (2 * Math.PI * radius * radius * radius) / 3;
    }
    public static double volumeCone(double radius, double height) {
        return (Math.PI * radius * radius * height) / 3;
    }
    public static double volumePrism(double baseArea, double height) {
        return baseArea * height;
    }
    public static double volumePyramid(double baseArea, double height) {
        return (baseArea * height) / 3;
    }
    public static double volumeFrustumOfCone(double r1, double r2, double height) {
        return (Math.PI * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2);
    }
}
