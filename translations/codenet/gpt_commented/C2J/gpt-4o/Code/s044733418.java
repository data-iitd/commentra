import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    // Function to compare two integers for sorting
    public static int compare(Integer a, Integer b) {
        // Return the difference for descending order
        return b - a;
    }

    public static void main(String[] args) {
        // Declare an array of integers
        Integer[] array = new Integer[10];
        Scanner scanner = new Scanner(System.in);

        // Read 10 integers from standard input into the array
        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt();
        }

        // Sort the array in descending order using Arrays.sort and the compare function
        Arrays.sort(array, Main::compare);

        // Print the first 3 elements of the sorted array
        for (int i = 0; i < 3; i++) {
            System.out.println(array[i]);
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
