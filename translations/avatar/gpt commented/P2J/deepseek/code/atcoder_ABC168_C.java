import java.util.Scanner;

public class ClockAngle {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for hours (h), minutes (m), and lengths (a, b)
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int h = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Calculate the angle C between the hour and minute hands of the clock
        double C = Math.abs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);
        
        // If the angle is greater than 180 degrees, find the smaller angle
        if (C > 180) {
            C = 360 - C;
        }
        
        // Calculate the cosine of angle C in radians
        double cosC = Math.cos(Math.toRadians(C));
        
        // Use the Law of Cosines to calculate the length of the third side of the triangle
        // formed by the lengths a, b, and the angle C
        double length = Math.sqrt(a * a + b * b - 2 * a * b * cosC);
        
        // Print the result
        System.out.println(length);
    }
}
