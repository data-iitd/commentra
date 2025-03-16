import java.util.Arrays;
import java.util.Scanner;

public class UniqueElementsCounter {
    // Function to compare two integers for sorting
    static int compareIntegers(Integer a, Integer b) {
        return a.compareTo(b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements N from the standard input
        int N = scanner.nextInt();
        int[] A = new int[N]; // Input array

        // Read the elements of the array A from the standard input
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Create a sorted array of unique elements from A
        Integer[] tomatu = Arrays.stream(A).boxed().distinct().toArray(Integer[]::new);
        Arrays.sort(tomatu, UniqueElementsCounter::compareIntegers);

        // Count the number of unique elements
        int emirinn = tomatu.length;

        // Print the number of unique elements to the standard output
        System.out.println(emirinn);

        // Close the scanner
        scanner.close();
    }
}
