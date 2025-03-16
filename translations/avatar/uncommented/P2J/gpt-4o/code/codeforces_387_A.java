import java.util.Scanner;

public class TimeDifference {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read first time input
        String[] time1 = scanner.nextLine().split(":");
        int h1 = Integer.parseInt(time1[0]);
        int m1 = Integer.parseInt(time1[1]);
        m1 += h1 * 60;

        // Read second time input
        String[] time2 = scanner.nextLine().split(":");
        int h2 = Integer.parseInt(time2[0]);
        int m2 = Integer.parseInt(time2[1]);
        m2 += h2 * 60;

        // Calculate the difference
        m2 = m1 - m2;
        m2 %= 1440;

        // Print the result in HH:MM format
        System.out.printf("%02d:%02d\n", m2 / 60, m2 % 60);
        
        scanner.close();
    }
}

// <END-OF-CODE>
