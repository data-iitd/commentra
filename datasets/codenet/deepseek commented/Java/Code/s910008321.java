import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize Scanner object to read input
        int h = scanner.nextInt(); // Read the total number of hours
        int a = scanner.nextInt(); // Read the number of hours worked per day

        // Check if the total number of hours is divisible by the number of hours worked per day
        if (h % a == 0) {
            System.out.println(h / a); // If divisible, print the quotient (number of days)
        } else {
            System.out.println(h / a + 1); // If not divisible, print the quotient plus one (additional day needed)
        }
    }
}
