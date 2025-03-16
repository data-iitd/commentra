import java.util.Scanner;

public class InsertionSort {

    // Function to print the first n-1 elements of an array
    static void white(int n, int[] A) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(A[i] + " ");
        }
        System.out.println(A[n - 1]);
    }

    // Function to implement insertion sort algorithm
    static void insertionsort(int n, int[] A) {
        int a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] < A[j]) {
                    a = A[i];
                    A[i] = A[j];
                    A[j] = a;
                }
            }
            white(n, A);
        }
    }

    // Main function to take input and call the insertion sort function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, A[];

        // Take the size of the array as input
        n = scanner.nextInt();
        A = new int[n];

        // Take the elements of the array as input
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Call the insertion sort function to sort the array
        insertionsort(n, A);

        // Close the scanner
        scanner.close();
    }
}
