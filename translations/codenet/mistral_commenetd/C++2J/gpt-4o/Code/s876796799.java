import java.util.*;

public class Main {
    // Initialize an array 'a' of size N
    static long[] a = new long[200000];
    static int[] ind_a = new int[200000];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements N from the standard input
        int N = scanner.nextInt();

        // Read N elements from the standard input and store them in the array 'a'
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextLong();
        }

        // Initialize an empty set 'used_inds' to keep track of indices already used
        TreeSet<Integer> used_inds = new TreeSet<>();

        long ans = 0; // Initialize an answer variable 'ans' to 0

        // Iterate through each index i from 0 to N-1
        for (int i = 0; i < N; i++) {
            long left_border; // Initialize variables 'left_border' and 'right_border'
            long right_border;

            long cur_ind = ind_a[i]; // Get the index of the current element a[i] in the array 'ind_a'

            // Find the index of the left neighbor of the current index i in the set 'used_inds'
            Integer left_it = used_inds.lower((int) cur_ind);

            // If the left neighbor does not exist, set 'left_border' to -1
            if (left_it == null) {
                left_border = -1;
            } else {
                left_border = left_it;
            }

            // Find the index of the right neighbor of the current index i in the set 'used_inds'
            Integer right_it = used_inds.higher((int) cur_ind);

            // If the right neighbor does not exist, set 'right_border' to N (the total number of elements)
            if (right_it == null) {
                right_border = N;
            } else {
                right_border = right_it;
            }

            // Calculate the contribution of the current index i to the answer 'ans'
            ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long) i + 1);

            // Insert the index of the current element a[i] into the set 'used_inds'
            used_inds.add((int) cur_ind);
        }

        // Print the final answer 'ans' to the standard output
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
