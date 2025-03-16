import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of elements N from the standard input

        long[] a = new long[N]; // Initialize an array 'a' of size N
        int[] ind_a = new int[N]; // Initialize an array 'ind_a' of size N

        // Read N elements from the standard input and store them in the array 'a'
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextLong();
        }

        // Initialize an empty set 'used_inds' to keep track of indices already used
        TreeSet<Integer> used_inds = new TreeSet<>();

        long ans = 0; // Initialize an answer variable 'ans' to 0

        // Iterate through each index i from 0 to N-1
        for (int i = 0; i < N; i++) {
            int cur_ind = ind_a[i]; // Get the index of the current element a[i] in the array 'ind_a'

            // Find the index of the left neighbor of the current index i in the set 'used_inds'
            Integer left_border = used_inds.lower(cur_ind);

            // If the left neighbor does not exist, set 'left_border' to -1
            if (left_border == null) {
                left_border = -1;
            }

            // Find the index of the right neighbor of the current index i in the set 'used_inds'
            Integer right_border = used_inds.higher(cur_ind);

            // If the right neighbor does not exist, set 'right_border' to N (the total number of elements)
            if (right_border == null) {
                right_border = N;
            }

            // Calculate the contribution of the current index i to the answer 'ans'
            ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long) i + 1);

            // Insert the index of the current element a[i] into the set 'used_inds'
            used_inds.add(cur_ind);

            // Uncomment the following lines to print the values of i, left_border, right_border, and ans for debugging purposes
            // System.out.println(i + " " + left_border + " " + right_border);
            // System.out.println(ans);
        }

        // Print the final answer 'ans' to the standard output
        System.out.println(ans);
    }
}

