import java.util.Optional;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Method to find the majority element in the given array
    public static Optional<Integer> findMajorityElement(int[] array) {
        // Check if the array is null or empty; if so, return an empty Optional
        if (array == null || array.length == 0) {
            return Optional.empty();
        }
        // Find the candidate for the majority element
        int candidate = findCandidate(array);
        // Count the occurrences of the candidate in the array
        int count = countOccurrences(candidate, array);
        // Check if the candidate is indeed the majority element
        if (isMajority(count, array.length)) {
            return Optional.of(candidate); // Return the candidate as the majority element
        }
        return Optional.empty(); // Return empty if no majority element is found
    }

    // Method to find the candidate for the majority element using the Boyer-Moore Voting Algorithm
    private static int findCandidate(final int[] array) {
        int count = 0; // Initialize count
        int candidate = -1; // Initialize candidate
        // Iterate through the array to find the candidate
        for (int value : array) {
            if (count == 0) {
                candidate = value; // Set the current value as the candidate
            }
            // Increment or decrement the count based on whether the current value matches the candidate
            count += (value == candidate) ? 1 : -1;
        }
        return candidate; // Return the found candidate
    }

    // Method to count the occurrences of the candidate in the array
    private static int countOccurrences(final int candidate, final int[] array) {
        int count = 0; // Initialize count
        // Iterate through the array to count occurrences of the candidate
        for (int value : array) {
            if (value == candidate) {
                count++; // Increment count if the value matches the candidate
            }
        }
        return count; // Return the total count of occurrences
    }

    // Method to check if the count of the candidate is more than half of the total count
    private static boolean isMajority(int count, int totalCount) {
        return 2 * count > totalCount; // Return true if count is greater than half of totalCount
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the size of the array
        int[] array = new int[n]; // Initialize the array
        // Read the elements of the array from input
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        // Find the majority element in the array
        Optional<Integer> majorityElement = findMajorityElement(array);
        // Print the majority element if present, otherwise print a message
        if (majorityElement.isPresent()) {
            System.out.println(majorityElement.get()); // Print the majority element
        } else {
            System.out.println("No majority element"); // Print message if no majority element found
        }
        scanner.close(); // Close the scanner
    }
}
