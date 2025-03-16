public class Main {
    public static void main(String[] args) {
        // Initialize minA to a value larger than any possible element in A
        int minA = (int) Math.pow(10, 9) + 1;
        int num = 0; // Counter for the number of valid pairs

        int n = 0, t = 0, f = 0; // Declare variables for input size, threshold, and frequency
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt(); // Read the size of the array
        t = scanner.nextInt(); // Read the threshold value
        int[] A = new int[n]; // Create an array to store the elements of the array

        // Input the elements of the array A
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        // Iterate through the array to find the minimum value and count valid pairs
        for (int i = 0; i < n; i++) {
            // Update minA if the current element is smaller
            if (minA > A[i]) {
                minA = A[i];
            } else {
                // Check the difference between the current element and minA
                if (f == A[i] - minA) {
                    num++; // Increment the count if the difference matches the previous one
                } else if (f < A[i] - minA) {
                    num = 1; // Reset count if a larger difference is found
                    f = A[i] - minA; // Update the frequency to the new difference
                }
            }
        }

        // Output the total count of valid pairs
        System.out.println(num);
    }
}
