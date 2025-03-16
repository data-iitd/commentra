import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int N = scanner.nextInt();

        // Declare an array to hold the input values and an array to store their indices
        long[] a = new long[N];
        int[] ind_a = new int[N];

        // Input the elements into array 'a'
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextLong();
        }

        // Populate 'ind_a' with the indices of the elements in 'a'
        for (int i = 0; i < N; i++) {
            ind_a[(int) a[i] - 1] = i; // Store the index of each element based on its value
        }

        // Set to keep track of used indices
        TreeSet<Integer> used_inds = new TreeSet<>();
        long ans = 0; // Variable to accumulate the final answer

        // Iterate through each element's index
        for (int i = 0; i < N; i++) {
            long left_border; // Variable to store the left border index
            long right_border; // Variable to store the right border index
            long cur_ind = ind_a[i]; // Current index of the element being processed

            // Find the first used index that is not less than cur_ind
            Integer left_it = used_inds.floor((int) cur_ind);
            // Find the first used index that is greater than cur_ind
            Integer right_it = used_inds.higher((int) cur_ind);

            // Determine the left border
            if (left_it == null) {
                left_border = -1; // No used index to the left
            } else {
                left_border = left_it; // Set the left border to the found index
            }

            // Determine the right border
            if (right_it == null) {
                right_border = N; // No used index to the right
            } else {
                right_border = right_it; // Set the right border to the found index
            }

            // Calculate the contribution of the current index to the answer
            ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long) i + 1);

            // Uncomment the lines below for debugging purposes
            // System.out.println(i + " " + left_border + " " + right_border);
            // System.out.println(ans);

            // Insert the current index into the set of used indices
            used_inds.add((int) cur_ind);
        }

        // Output the final answer
        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
