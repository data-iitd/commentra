
import java.util.Optional;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }

    public static Optional<Integer> findMajorityElement(int[] array) {
        // Check if the array is empty or null, return empty optional if so
        if (array == null || array.length == 0) {
            return Optional.empty();
        }

        int candidate = findCandidate(array);
        // Determine the candidate element

        int count = countOccurrences(candidate, array);
        // Count the occurrences of the candidate element in the array

        if (isMajority(count, array.length)) {
            // If the candidate element has more than half the total count in the array, it's the majority element
            return Optional.of(candidate);
        }

        return Optional.empty();
        // Return empty optional if the candidate element is not the majority element
    }

    private static int findCandidate(final int[] array) {
        int count = 0;
        int candidate = -1;
        // Initialize the count and candidate variables

        for (int value : array) {
            if (count == 0) {
                // If there's no current candidate, set the first encountered value as the candidate
                candidate = value;
            }
            count += (value == candidate) ? 1 : -1;
            // Increment the count if the current value is the same as the candidate, otherwise decrement it
        }
        return candidate;
        // Return the candidate element after the loop
    }

    private static int countOccurrences(final int candidate, final int[] array) {
        int count = 0;
        // Initialize the count variable

        for (int value : array) {
            if (value == candidate) {
                count++;
                // Increment the count if the current value is the same as the candidate
            }
        }
        return count;
        // Return the count of occurrences of the candidate element after the loop
    }

    private static boolean isMajority(int count, int totalCount) {
        // Check if the count of the candidate element is more than half the total count in the array
        return 2 * count > totalCount;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        // Read the number of elements in the array from the user input

        int[] array = new int[n];
        // Allocate an array of size n to store the elements

        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
            // Read each element in the array from the user input
        }

        Optional<Integer> majorityElement = findMajorityElement(array);
        // Find the majority element in the array using the findMajorityElement method

        if (majorityElement.isPresent()) {
            System.out.println(majorityElement.get());
            // Print the majority element if it exists
        } else {
            System.out.println("No majority element");
            // Print "No majority element" if there's no majority element in the array
        }

        scanner.close();
        // Close the scanner after the program execution
    }
}