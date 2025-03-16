import java.util.Arrays;  // Import the Arrays class for sorting

public class Main {  // Define the main class
    // Define a method to compare two integers
    public static int compare(Integer a, Integer b) {
        return b - a;  // Return the difference between the two integers
    }

    public static void main(String[] args) {  // Define the main method
        int[] array = new int[10];  // Declare an array of 10 integers
        java.util.Scanner scanner = new java.util.Scanner(System.in);  // Create a Scanner object for input

        // Read 10 integers from the input
        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt();
        }

        // Sort the array using Arrays.sort and a custom comparator
        Integer[] arrayInteger = Arrays.stream(array).boxed().toArray(Integer[]::new);
        Arrays.sort(arrayInteger, Main::compare);

        // Print the first three elements of the sorted array
        for (int i = 0; i < 3; i++) {
            System.out.println(arrayInteger[i]);
        }

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
