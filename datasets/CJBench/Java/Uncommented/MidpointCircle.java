
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public final class MidpointCircle {
    private MidpointCircle() {
    }
    public static List<int[]> generateCirclePoints(int centerX, int centerY, int radius) {
        List<int[]> points = new ArrayList<>();
        if (radius == 0) {
            points.add(new int[] {centerX, centerY});
            return points;
        }
        int x = radius;
        int y = 0;
        int p = 1 - radius;
        addSymmetricPoints(points, centerX, centerY, x, y);
        while (x > y) {
            y++;
            if (p <= 0) {
                p = p + 2 * y + 1;
            } else {
                x--;
                p = p + 2 * y - 2 * x + 1;
            }
            addSymmetricPoints(points, centerX, centerY, x, y);
        }
        return points;
    }
    private static void addSymmetricPoints(List<int[]> points, int centerX, int centerY, int x, int y) {
        points.add(new int[] {centerX + x, centerY + y});
        points.add(new int[] {centerX - x, centerY + y});
        points.add(new int[] {centerX + x, centerY - y});
        points.add(new int[] {centerX - x, centerY - y});
        points.add(new int[] {centerX + y, centerY + x});
        points.add(new int[] {centerX - y, centerY + x});
        points.add(new int[] {centerX + y, centerY - x});
        points.add(new int[] {centerX - y, centerY - x});
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            int centerX = scanner.nextInt();
            int centerY = scanner.nextInt();
            int radius = scanner.nextInt();
            List<int[]> circlePoints = generateCirclePoints(centerX, centerY, radius);
            System.out.println("The points on the circumference of the circle are:");
            for (int[] point : circlePoints) {
                System.out.printf("(%d, %d)%n", point[0], point[1]);
            }
        } catch (Exception e) {
            System.out.println("Invalid input! Please enter integers.");
        } finally {
            scanner.close();
        }
    }
}
