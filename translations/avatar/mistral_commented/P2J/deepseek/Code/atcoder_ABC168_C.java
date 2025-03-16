import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int h = Integer.parseInt(input[2]);
        int m = Integer.parseInt(input[3]);

        // Calculate the angle C between hour hand and minute hand
        double C = Math.abs(360.0 / 60.0 * m - 360.0 / 12.0 * h - 360.0 / 12.0 / 60.0 * m);
        if (C > 180) {
            // If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
            C = 360 - C;
        }

        // Calculate the cosine of angle C
        double cosC = Math.cos(Math.toRadians(C));

        // Calculate and print the length of the side of the right triangle formed by the hour and minute hands
        double length = Math.sqrt(a * a + b * b - 2 * a * b * cosC);
        System.out.println(length);
    }
}
