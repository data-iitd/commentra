import java.util.Scanner;

/* Calculate the volume of various shapes.*/
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
                    return; // Exit on invalid choice
            }

            System.out.printf("%.2f%n", volume);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }

    /**
     * Calculate the volume of a cube.
     *
     * @param sideLength length of the given cube's sides
     * @return volume of the given cube
     */
    public static double volumeCube(double sideLength) {
        return sideLength * sideLength * sideLength;
    }

    /**
     * Calculate the volume of a cuboid.
     *
     * @param width  width of given cuboid
     * @param height height of given cuboid
     * @param length length of given cuboid
     * @return volume of given cuboid
     */
    public static double volumeCuboid(double width, double height, double length) {
        return width * height * length;
    }

    /**
     * Calculate the volume of a sphere.
     *
     * @param radius radius of given sphere
     * @return volume of given sphere
     */
    public static double volumeSphere(double radius) {
        return (4 * Math.PI * radius * radius * radius) / 3;
    }

    /**
     * Calculate volume of a cylinder
     *
     * @param radius radius of the given cylinder's floor
     * @param height height of the given cylinder
     * @return volume of given cylinder
     */
    public static double volumeCylinder(double radius, double height) {
        return Math.PI * radius * radius * height;
    }

    /**
     * Calculate the volume of a hemisphere.
     *
     * @param radius radius of given hemisphere
     * @return volume of given hemisphere
     */
    public static double volumeHemisphere(double radius) {
        return (2 * Math.PI * radius * radius * radius) / 3;
    }

    /**
     * Calculate the volume of a cone.
     *
     * @param radius radius of given cone
     * @param height of given cone
     * @return volume of given cone
     */
    public static double volumeCone(double radius, double height) {
        return (Math.PI * radius * radius * height) / 3;
    }

    public static double volumePrism(double baseArea, double height) {
        return baseArea * height;
    }

    /**
     * Calculate the volume of a pyramid.
     *
     * @param baseArea   of the given pyramid's base
     * @param height of given pyramid
     * @return volume of given pyramid
     */
    public static double volumePyramid(double baseArea, double height) {
        return (baseArea * height) / 3;
    }

    /**
     * Calculate the volume of a frustum of a cone.
     *
     * @param r1 radius of the top of the frustum
     * @param r2 radius of the bottom of the frustum
     * @param height height of the frustum
     * @return volume of the frustum
     */
    public static double volumeFrustumOfCone(double r1, double r2, double height) {
        return (Math.PI * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2);
    }
}
