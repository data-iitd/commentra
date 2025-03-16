import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements 'n' from the standard input

        int[] a = new int[100]; // Declare an integer array 'a' of size 100
        int[] b = new int[100]; // Declare an integer array 'b' of size 100
        int sum = 0; // Declare an integer variable 'sum' and initialize it to zero

        for (int i = 0; i < n; i++) { // Iterate through the array 'a' and read its elements from the standard input
            a[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) { // Iterate through the array 'b' and read its elements from the standard input
            b[i] = scanner.nextInt();

            if (a[i] - b[i] > 0) { // Check if the difference between 'a[i]' and 'b[i]' is positive
                sum += a[i] - b[i]; // If it is, add the difference to the variable 'sum'
            }
        }

        System.out.println(sum); // Output the value of the variable 'sum' to the standard output
    }
}

