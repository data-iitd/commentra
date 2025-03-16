import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Comparison function for Arrays.sort to sort integers
    public static int compare(Integer a, Integer b) {
        return a.compareTo(b);
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Number of elements
        Integer[] A = new Integer[N]; // Array to hold input elements
        Integer[] tomatu = new Integer[N]; // Array to hold sorted elements
        boolean[] mikakosi = new boolean[N]; // Array to track occurrences of elements

        // Read the elements into array A and copy to tomatu
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
            tomatu[i] = A[i]; // Copying input to sorted array
        }

        // Sort the array of elements
        Arrays.sort(tomatu, Main::compare);

        // Remove duplicates from the sorted array
        int yukinnko = 1; // Start with the first unique element
        for (int i = 1; i < N; i++) {
            if (!tomatu[i].equals(tomatu[yukinnko - 1])) {
                tomatu[yukinnko++] = tomatu[i]; // Add unique element
            }
        }

        // Track occurrences of each element in the original array
        for (int i = 0; i < N; i++) {
            int kugyu = Arrays.binarySearch(tomatu, 0, yukinnko, A[i]); // Find index of element in sorted array
            mikakosi[kugyu] = !mikakosi[kugyu]; // Toggle occurrence
        }

        // Count the number of unique elements
        int emirinn = 0; // Counter for unique elements
        for (int i = 0; i < yukinnko; i++) {
            if (mikakosi[i]) emirinn++; // Increment count for unique occurrences
        }

        // Output the count of unique elements
        System.out.println(emirinn);
    }
}
