
import java.util.Scanner;

public class s972081311{
    public static void main(String[] args) {
        // Declare variables to hold the input number and the sum
        int n, sum;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read an integer input from the user
        n = scanner.nextInt();

        // Calculate the sum of the first n natural numbers using the formula n*(n+1)/2
        sum = (n * (n + 1)) / 2;

        // Print the calculated sum to the console
        System.out.println(sum);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
// 