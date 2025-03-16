
import java.util.Scanner;
// Import the Scanner class from the java.util package

public class Main {
    public static void main(String[] args) {
        int[] array = new int[10];
        // Declare an array of 10 integers

        Scanner sc = new Scanner(System.in);
        // Initialize a Scanner object to read input from the user

        for (int i = 0; i < 10; i++) {
            // Iterate through the array to read 10 integers
            array[i] = sc.nextInt();
            // Read an integer from the user and store it in the array
        }

        Arrays.sort(array);
        // Sort the array using the Arrays.sort method

        for (int i = 0; i < 3; i++) {
            // Iterate through the first three elements of the sorted array
            System.out.println(array[i]);
            // Print the first three sorted integers
        }
    }
}

