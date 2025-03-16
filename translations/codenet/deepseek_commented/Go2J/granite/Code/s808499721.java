

import java.util.Scanner;

public class s808499721{
    public static void main(String[] args) {
        // Read an integer input from the user
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();

        // Initialize the answer variable to 0
        int ans = 0;

        // Check the range of x and assign the corresponding value to ans
        if (x >= 400 && x <= 599) {
            ans = 8;
        }
        if (x >= 600 && x <= 799) {
            ans = 7;
        }
        if (x >= 800 && x <= 999) {
            ans = 6;
        }
        if (x >= 1000 && x <= 1199) {
            ans = 5;
        }
        if (x >= 1200 && x <= 1399) {
            ans = 4;
        }
        if (x >= 1400 && x <= 1599) {
            ans = 3;
        }
        if (x >= 1600 && x <= 1799) {
            ans = 2;
        }
        if (x >= 1800 && x <= 9999) {
            ans = 1;
        }

        // Print the value of ans
        System.out.println(ans);
    }
}
