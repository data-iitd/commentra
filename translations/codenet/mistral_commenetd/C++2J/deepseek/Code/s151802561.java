public class SelectionSort {
    public static void main(String[] args) {
        int[] A = new int[100]; // An array of integers with a maximum size of 100
        int n; // The number of elements in the array
        int i, j, t, sw = 0, mini; // Variables used in the sorting algorithm

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        n = scanner.nextInt(); // Read the number of elements from the standard input

        System.out.printf("Enter %d integers:\n", n);
        for (i = 0; i < n; i++) { // Read %d integers from the standard input and store them in the array A
            A[i] = scanner.nextInt();
        }

        System.out.println("Sorting the array using Selection Sort algorithm:");
        for (i = 0; i < n; i++) { // The outer loop runs n times
            mini = i; // Initialize mini as i
            for (j = i; j < n; j++) { // The inner loop finds the minimum element in the unsorted part of the array
                if (A[j] < A[mini]) { // If A[j] is smaller than A[mini], update mini
                    mini = j;
                }
            }
            t = A[i]; // Swap A[i] with the minimum element
            A[i] = A[mini];
            A[mini] = t;

            if (i != mini) sw++; // Increment sw only if a swap is made
        }

        System.out.print("Sorted array: ");
        for (i = 0; i < n; i++) { // Print the sorted array to the standard output
            if (i > 0) System.out.print(" ");
            System.out.print(A[i]);
        }
        System.out.println();

        System.out.printf("Number of swaps: %d\n", sw);
    }
}
