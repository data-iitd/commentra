import java.util.Scanner;

public class SumOfArray {
    public static void main(String[] args) {
        // Declare an integer array 'v' of size 10 and an integer variable 'sum' to store the sum of array elements.
        int[] v = new int[10];
        int sum = 0;

        // Create a Scanner object to read input from the user.
        Scanner scanner = new Scanner(System.in);

        // Read 10 integers from the user and store them in the array 'v'.
        for (int i = 0; i < 10; i++) {
            System.out.print("Enter the value for index " + i + ": ");
            v[i] = scanner.nextInt();
        }

        // Calculate the sum of all elements in the array 'v'.
        for (int i = 0; i < 10; i++) {
            sum += v[i];
        }

        // Print the sum of all elements in the array 'v'.
        System.out.println(sum);

        // Close the Scanner object to free up resources.
        scanner.close();
    }
}
