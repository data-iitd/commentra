
import java.util.Scanner;

public class codeforces_387_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first time input in 'hh:mm' format and split it into hours and minutes
        int h1 = scanner.nextInt();
        scanner.next();
        int m1 = scanner.nextInt();

        // Convert the first time into total minutes
        m1 += h1 * 60;

        // Read the second time input in 'hh:mm' format and split it into hours and minutes
        int h2 = scanner.nextInt();
        scanner.next();
        int m2 = scanner.nextInt();

        // Convert the second time into total minutes
        m2 += h2 * 60;

        // Calculate the difference in minutes between the first and second time
        m2 = m1 - m2;

        // Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
        m2 %= 1440;

        // Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
        System.out.printf("%02d:%02d", m2 / 60, m2 % 60);
    }
}
