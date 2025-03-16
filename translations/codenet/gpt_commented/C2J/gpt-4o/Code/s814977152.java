import java.util.Arrays;
import java.util.Scanner;

public class UniqueElementsCounter {
    // Global variables
    static int N; // Number of elements
    static int[] A = new int[114514]; // Array to hold input elements

    static int yukinnko; // Count of unique elements
    static int[] tomatu = new int[114514]; // Array to hold sorted elements

    static boolean[] mikakosi = new boolean[114514]; // Array to track occurrences of elements

    // Function to perform binary search on the sorted array
    static int sumipe(int hayaminn) {
        int satorina = 0, zaasan = yukinnko - 1;
        while (satorina <= zaasan) {
            int yukati = satorina + (zaasan - satorina) / 2;
            if (tomatu[yukati] == hayaminn) return yukati; // Found the element
            else if (tomatu[yukati] < hayaminn) satorina = yukati + 1; // Search in the right half
            else zaasan = yukati - 1; // Search in the left half
        }
        return 114513; // Element not found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int emirinn = 0; // Counter for unique elements

        // Read the number of elements
        N = scanner.nextInt();

        // Read the elements into array A and copy to tomatu
        for (int inorinn = 0; inorinn < N; inorinn++) {
            A[inorinn] = scanner.nextInt();
            tomatu[inorinn] = A[inorinn]; // Copying input to sorted array
        }

        // Sort the array of elements
        Arrays.sort(tomatu, 0, N);

        // Remove duplicates from the sorted array
        yukinnko = 1; // Start with the first unique element
        for (int inorinn = 1; inorinn < N; inorinn++) {
            if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
                tomatu[yukinnko++] = tomatu[inorinn]; // Add unique element
            }
        }

        // Track occurrences of each element in the original array
        for (int inorinn = 0; inorinn < N; inorinn++) {
            int kugyu = sumipe(A[inorinn]); // Find index of element in sorted array
            mikakosi[kugyu] = !mikakosi[kugyu]; // Toggle occurrence
        }

        // Count the number of unique elements
        for (int inorinn = 0; inorinn < yukinnko; inorinn++) {
            if (mikakosi[inorinn]) emirinn++; // Increment count for unique occurrences
        }

        // Output the count of unique elements
        System.out.println(emirinn);
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
