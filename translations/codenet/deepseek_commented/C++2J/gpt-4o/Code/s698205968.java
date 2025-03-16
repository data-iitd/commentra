import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m, f, r;

        while (true) {
            m = scanner.nextInt();
            f = scanner.nextInt();
            r = scanner.nextInt();

            if (m == -1 && f == -1 && r == -1) {
                break; // Exit the loop if all three values are -1
            }

            if (m == -1 || f == -1) {
                System.out.println("F"); // Output "F" if any of m or f is -1
            } else if (m + f >= 80) {
                System.out.println("A"); // Output "A" if the sum of m and f is 80 or more
            } else if (m + f >= 65) {
                System.out.println("B"); // Output "B" if the sum of m and f is 65 or more
            } else if (m + f >= 50 || r >= 50) {
                System.out.println("C"); // Output "C" if the sum of m and f is 50 or more, or r is 50 or more
            } else if (m + f >= 30) {
                System.out.println("D"); // Output "D" if the sum of m and f is 30 or more
            } else {
                System.out.println("F"); // Output "F" if none of the above conditions are met
            }
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
