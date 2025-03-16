
import java.util.Arrays;
import java.util.Scanner;

public class s044733418{
    // Function to compare two integers for sorting
    public static int compare(int a, int b) {
        // Return the difference between b and a for descending order
        return b - a;
    }

    public static void main(String[] args) {
        // Declare an array of integers and a variable for iteration
        int[] array = new int[10];
        int i;

        // Read 10 integers from standard input into the array
        Scanner scanner = new Scanner(System.in);
        for (i = 0; i!= 10; i++) {
            array[i] = scanner.nextInt();
        }

        // Sort the array in descending order using Arrays.sort and the compare function
        Arrays.sort(array, (a, b) -> compare(a, b));

        // Print the first 3 elements of the sorted array
        for (i = 0; i!= 3; i++) {
            System.out.println(array[i]);
        }

        // Return 0 to indicate successful completion of the program
        System.out.println(0);
    }
}
