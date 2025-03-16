
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int h1, h2, m1, m2, k; // Declare variables for hours and minutes of first and second time, and the difference

        // Input the values of hours and minutes for the first and second time
        h1 = sc.nextInt();
        m1 = sc.nextInt();
        System.out.println("Enter hours and minutes for the first time: ");
        h1 = sc.nextInt();
        m1 = sc.nextInt();

        h2 = sc.nextInt();
        m2 = sc.nextInt();
        System.out.println("Enter hours and minutes for the second time: ");
        h2 = sc.nextInt();
        m2 = sc.nextInt();

        int ans = h2 * 60 + m2; // Calculate the total minutes of the second time
        System.out.println("The total minutes of the second time are: " + ans);

        ans -= (h1 * 60 + m1); // Subtract the total minutes of the first time from the total minutes of the second time
        System.out.println("The difference in minutes is: " + ans);

        ans -= k; // Subtract the given difference 'k' from the difference in minutes
        System.out.println("The difference in minutes after subtracting " + k + " is: " + ans);

        // Convert the difference in minutes to hours and minutes
        int hours = ans / 60;
        int minutes = ans % 60;

        System.out.println(hours + " hours and " + minutes + " minutes"); // Output the result
    }
}

