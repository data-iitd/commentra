import java.util.Scanner;

public class TimeDifference {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking input in the format of 'HH:MM' and splitting it into hours and minutes
        String[] time1 = scanner.nextLine().split(":");
        int h1 = Integer.parseInt(time1[0]);
        int m1 = Integer.parseInt(time1[1]);

        // Converting hours to minutes and adding it to the minutes part
        m1 += h1 * 60;

        // Taking another input in the same format and converting it into total minutes since midnight
        String[] time2 = scanner.nextLine().split(":");
        int h2 = Integer.parseInt(time2[0]);
        int m2 = Integer.parseInt(time2[1]);

        // Converting the second time into total minutes
        m2 += h2 * 60;

        // Calculating the difference in total minutes between the two times
        m2 = m1 - m2;

        // Ensuring the result is within a 24-hour period by using modulo operation
        m2 = (m2 + 1440) % 1440; // Adding 1440 to handle negative values

        // Printing the result in 'HH:MM' format
        System.out.printf("%02d:%02d\n", m2 / 60, m2 % 60);
        
        scanner.close();
    }
}

// <END-OF-CODE>
