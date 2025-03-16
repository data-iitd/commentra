import java.util.Scanner;

public class TimeDifference {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first time input in 'hh:mm' format and split it into hours and minutes
        String[] time1 = scanner.nextLine().split(":");
        int h1 = Integer.parseInt(time1[0]);
        int m1 = Integer.parseInt(time1[1]);

        // Convert the first time into total minutes
        m1 += h1 * 60;

        // Read the second time input in 'hh:mm' format and split it into hours and minutes
        String[] time2 = scanner.nextLine().split(":");
        int h2 = Integer.parseInt(time2[0]);
        int m2 = Integer.parseInt(time2[1]);

        // Convert the second time into total minutes
        m2 += h2 * 60;

        // Calculate the difference in minutes between the first and second time
        m2 = m1 - m2;

        // Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
        m2 = (m2 + 1440) % 1440; // Adding 1440 to handle negative values

        // Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
        System.out.printf("%02d:%02d\n", m2 / 60, m2 % 60);
        
        scanner.close();
    }
}
// <END-OF-CODE>
