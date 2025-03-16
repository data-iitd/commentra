import java.util.Scanner;

public class ClockHands {
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Assign values to variables a, b, h, and m using the input function
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int h = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Calculate the angle C between hour hand and minute hand
        double C = Math.abs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);
        if (C > 180) {
            // If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
            C = 360 - C;
        }
        
        // Calculate the cosine of angle C
        double cosC = Math.cos(Math.toRadians(C));
        
        // Calculate and print the length of the side of the right triangle formed by the hour and minute hands
        double length = Math.sqrt(a * a + b * b - 2 * a * b * cosC);
        System.out.println(length);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
