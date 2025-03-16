import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a new scanner to read from standard input
        int[] arr = scanArrayInt(scanner); // Call the function to get the input array of integers
        int a = arr[0], b = arr[1]; // Extract the two integers from the input array
        int tap = 0; // Initialize the tap counter
        int consent = 1; // Initialize the consent level
        
        while (consent < b) { // Loop until consent reaches or exceeds b
            consent = consent + a - 1; // Increment consent by a - 1
            tap++; // Increment the tap counter
        }
        
        System.out.println(tap); // Print the number of taps needed
    }

    private static int[] scanArrayInt(Scanner scanner) {
        String line = scanner.nextLine(); // Read a line of input
        String[] parts = line.split(" "); // Split the input by spaces
        int[] ret = new int[parts.length]; // Initialize an array to store the integers
        
        for (int i = 0; i < parts.length; i++) {
            ret[i] = Integer.parseInt(parts[i]); // Convert each part to an integer
        }
        
        return ret; // Return the array of integers
    }
}

// <END-OF-CODE>
