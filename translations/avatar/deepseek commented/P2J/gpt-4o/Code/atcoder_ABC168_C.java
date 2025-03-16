import java.util.Scanner;

public class ClockHandsDistance {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input values for the lengths of the sides of the triangle and the time
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int h = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Calculating the angle C between the hour and minute hands of a clock
        double C = Math.abs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);
        
        // Adjusting the angle C if it is greater than 180 degrees
        if (C > 180) {
            C = 360 - C;
        }
        
        // Calculating the cosine of angle C in radians
        double cosC = Math.cos(Math.toRadians(C));
        
        // Printing the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines
        double distance = Math.sqrt(a * a + b * b - 2 * a * b * cosC);
        System.out.println(distance);
        
        scanner.close();
    }
}

// <END-OF-CODE>
