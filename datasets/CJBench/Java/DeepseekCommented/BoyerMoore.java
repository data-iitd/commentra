
import java.util.Optional;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // This method finds the majority element in the array, if it exists.
    public static Optional<Integer> findMajorityElement(int[] array) {
        // Check if the array is null or empty.
        if (array == null || array.length == 0) {
            return Optional.empty();
        }

        // Find a candidate for the majority element using the Boyer-Moore Voting Algorithm.
        int candidate = findCandidate(array);

        // Count the occurrences of the candidate in the array.
        int count = countOccurrences(candidate, array);

        // Check if the candidate is the majority element.
        if (isMajority(count, array.length)) {
            return Optional.of(candidate);
        }

        // Return Optional.empty() if no majority element is found.
        return Optional.empty();
    }

    // Helper method to find a candidate for the majority element using the Boyer-Moore Voting Algorithm.
    private static int findCandidate(final int[] array) {
        int count = 0;
        int candidate = -1;
        for (int value : array) {
            if (count == 0) {
                candidate = value;
            }
            count += (value == candidate) ? 1 : -1;
        }
        return candidate;
    }

    // Helper method to count the occurrences of the candidate in the array.
    private static int countOccurrences(final int candidate, final int[] array) {
        int count = 0;
        for (int value : array) {
            if (value == candidate) {
                count++;
            }
        }
        return count;
    }

    // Helper method to check if the candidate is the majority element.
    private static boolean isMajority(int count, int totalCount) {
        return 2 * count > totalCount;
    }

    // The entry point of the program.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        // Find the majority element in the array.
        Optional<Integer> majorityElement = findMajorityElement(array);

        // Print the result.
        if (majorityElement.isPresent()) {
            System.out.println(majorityElement.get());
        } else {
            System.out.println("No majority element");
        }

        // Close the scanner.
        scanner.close();
    }
}