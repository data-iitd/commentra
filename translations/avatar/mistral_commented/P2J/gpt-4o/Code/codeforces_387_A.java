import java.util.Scanner;

public class TimeDifference {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Define the first hour and minute variables from user input
        String[] firstTime = scanner.nextLine().split(":");
        int h1 = Integer.parseInt(firstTime[0]);
        int m1 = Integer.parseInt(firstTime[1]);

        // Add the hour to the minute value
        m1 += h1 * 60;

        // Define the second hour and minute variables from user input
        String[] secondTime = scanner.nextLine().split(":");
        int h2 = Integer.parseInt(secondTime[0]);
        int m2 = Integer.parseInt(secondTime[1]);

        // Add the hour to the minute value for the second set of variables
        m2 += h2 * 60;

        // Calculate the difference between the total minutes of the first and second sets of variables
        m2 = m1 - m2;

        // Calculate the remainder of the difference when divided by 1440 (24 hours * 60 minutes)
        m2 = (m2 + 1440) % 1440; // Adding 1440 to handle negative differences

        // Print the result in the format of hours and minutes
        System.out.printf("%02d:%02d%n", m2 / 60, m2 % 60);
        
        scanner.close();
    }
}
// <END-OF-CODE>
