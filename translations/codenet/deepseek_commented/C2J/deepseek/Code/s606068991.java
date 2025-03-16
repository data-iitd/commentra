public class InsertionSort {
    // Function to print the array elements
    public static void white(int n, int[] A) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(A[i] + " ");
        }
        System.out.println(A[n - 1]);
    }

    // Function to perform insertion sort on the array
    public static void insertionsort(int n, int[] A) {
        int a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] < A[j]) {
                    // Swap A[i] and A[j]
                    a = A[i];
                    A[i] = A[j];
                    A[j] = a;
                }
            }
            // Print the array after each insertion
            white(n, A);
        }
    }

    // Main function to handle input and call the sorting function
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] A = new int[100];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        insertionsort(n, A);
    }
}
