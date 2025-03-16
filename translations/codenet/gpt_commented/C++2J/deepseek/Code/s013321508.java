public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of elements (N) and the number of operations (M)
        int N, M;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();

        // Initialize a vector to hold the elements, with a size of 100000
        int[] L = new int[100000];
        int l;

        // Read N integers from input and store them in the array L
        for (int i = 0; i < N; i++) {
            l = scanner.nextInt();
            L[i] = l;
        }

        // Sort the array L in ascending order
        java.util.Arrays.sort(L);

        // Perform M operations to modify the array L
        for (int i = 0; i < M; i++) {
            // Get the maximum element from the end of the sorted array
            int max_L = L[N - 1];
            
            // If the maximum element is 0, break the loop as no further operations are needed
            if (max_L == 0) {
                break;
            }

            // Halve the maximum element
            max_L /= 2;

            // Find the position to insert the halved value in the sorted array
            int position = java.util.Arrays.binarySearch(L, 0, N, max_L);
            
            // If the position is negative, adjust it to the correct insertion point
            if (position < 0) {
                position = -(position + 1);
            }
            
            // Shift elements to the right to make space for the new element
            System.arraycopy(L, position, L, position + 1, N - position);
            
            // Insert the halved value into the array at the found position
            L[position] = max_L;
            
            // Remove the last element (the original maximum) from the array
            L[N - 1] = 0;
        }

        // Calculate the sum of all elements in the array L
        long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += L[i];
        }

        // Output the final sum
        System.out.println(sum);
    }
}
