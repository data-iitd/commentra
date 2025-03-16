import java.util.Arrays; // Import the Arrays class for sorting

public class Main {
    // Function to compare two integers for sorting in descending order
    public static int compare(Integer a, Integer b) {
        return b - a; // Subtract b from a to sort in descending order
    }

    public static void main(String[] args) {
        int[] array = new int[10]; // Declare an array of 10 integers

        // Iterate through the array to read 10 integers
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt(); // Read an integer from the user and store it in the array
        }

        // Sort the array using the Arrays.sort method with a custom comparator
        Integer[] arrayInteger = Arrays.stream(array).boxed().toArray(Integer[]::new);
        Arrays.sort(arrayInteger, Main::compare);

        // Iterate through the first three elements of the sorted array
        for (int i = 0; i < 3; i++) {
            System.out.println(arrayInteger[i]); // Print the first three sorted integers
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
