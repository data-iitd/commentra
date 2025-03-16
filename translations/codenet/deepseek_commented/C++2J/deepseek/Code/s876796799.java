import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of elements
        long[] a = new long[N]; // Array to store the elements
        int[] ind_a = new int[N]; // Array to store the indices of elements in array a

        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextLong(); // Read the elements into array a
        }
        for (int i = 0; i < N; i++) {
            ind_a[a[i] - 1] = i; // Initialize ind_a with the indices of elements in array a
        }

        Set<Integer> used_inds = new HashSet<>(); // Set to keep track of used indices
        long ans = 0; // Variable to store the final answer
        for (int i = 0; i < N; i++) {
            long left_border = -1; // Variable to store the left boundary
            long right_border = N; // Variable to store the right boundary
            int cur_ind = ind_a[i]; // Current index of the element being processed
            Integer left_it = null; // Iterator to the lower bound of cur_ind in used_inds
            Integer right_it = null; // Iterator to the lower bound of cur_ind + 1 in used_inds

            List<Integer> used_inds_list = new ArrayList<>(used_inds);
            Collections.sort(used_inds_list);

            left_it = findLowerBound(used_inds_list, cur_ind);
            right_it = findLowerBound(used_inds_list, cur_ind + 1);

            if (left_it == null || left_it == 0) {
                left_border = -1; // If left_it is the first element, set left_border to -1
            } else {
                left_border = used_inds_list.get(left_it - 1); // Set left_border to the value pointed by left_it
            }
            if (right_it == null || right_it == used_inds_list.size()) {
                right_border = N; // If right_it is the end, set right_border to N
            } else {
                right_border = used_inds_list.get(right_it); // Set right_border to the value pointed by right_it
            }
            ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long)i + 1); // Calculate the contribution of the current element to the answer

            // Debugging output (commented out)
            //System.out.println(i + " " + left_border + " " + right_border);
            //System.out.println(ans);

            used_inds.add(cur_ind); // Insert the current index into the set used_inds
        }

        System.out.println(ans); // Output the final answer
    }

    private static int findLowerBound(List<Integer> list, int target) {
        int left = 0;
        int right = list.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
