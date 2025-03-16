import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of elements
        long[] a = new long[200000]; // Array to store the elements
        int[] ind_a = new int[200000]; // Array to store the indices of elements in array a

        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextLong(); // Read the elements into array a
        }
        for (int i = 0; i < N; i++) {
            ind_a[(int) a[i] - 1] = i; // Initialize ind_a with the indices of elements in array a
        }

        TreeSet<Integer> used_inds = new TreeSet<>(); // Set to keep track of used indices
        long ans = 0; // Variable to store the final answer
        for (int i = 0; i < N; i++) {
            long left_border; // Variable to store the left boundary
            long right_border; // Variable to store the right boundary
            long cur_ind = ind_a[i]; // Current index of the element being processed
            Integer left_it = used_inds.lower(cur_ind); // Get the largest element less than cur_ind
            Integer right_it = used_inds.higher(cur_ind); // Get the smallest element greater than cur_ind

            if (left_it == null) {
                left_border = -1; // If left_it is null, set left_border to -1
            } else {
                left_border = left_it; // Set left_border to the value pointed by left_it
            }
            if (right_it == null) {
                right_border = N; // If right_it is null, set right_border to N
            } else {
                right_border = right_it; // Set right_border to the value pointed by right_it
            }
            ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long) i + 1); // Calculate the contribution of the current element to the answer

            // Debugging output (commented out)
            // System.out.println(i + " " + left_border + " " + right_border);
            // System.out.println(ans);

            used_inds.add((int) cur_ind); // Insert the current index into the set used_inds
        }

        System.out.println(ans); // Output the final answer
        scanner.close();
    }
}
// <END-OF-CODE>
