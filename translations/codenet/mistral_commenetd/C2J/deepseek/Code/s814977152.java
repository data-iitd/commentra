import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Number of elements in the array A
        int[] A = new int[N]; // Input array

        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Sort the array A
        Arrays.sort(A);

        // Find the number of unique elements in the array A
        int uniqueCount = 1;
        for (int i = 1; i < N; i++) {
            if (A[i] != A[uniqueCount - 1]) {
                A[uniqueCount++] = A[i];
            }
        }

        // Initialize the mikakosi array with all elements set to 0
        boolean[] mikakosi = new boolean[uniqueCount];
        Arrays.fill(mikakosi, false);

        // For each element in the array A, find its index in the sorted array A and mark it as present in the mikakosi array
        for (int i = 0; i < N; i++) {
            int index = Arrays.binarySearch(A, 0, uniqueCount, A[i]);
            if (index >= 0) {
                mikakosi[index] = true;
            }
        }

        // Count the number of unique elements in the array A by counting the number of elements with mikakosi[i] set to true
        int emirinn = 0;
        for (int i = 0; i < uniqueCount; i++) {
            if (mikakosi[i]) emirinn++;
        }

        // Print the number of unique elements to the standard output
        System.out.println(emirinn);
    }
}

