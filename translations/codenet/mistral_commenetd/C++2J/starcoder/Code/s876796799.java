import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Read the number of elements N from the standard input
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();

    // Read N elements from the standard input and store them in the array 'a'
    long[] a = new long[N];
    for(int i = 0; i < N; i++){
      a[i] = sc.nextLong();
    }

    // Initialize an empty set 'used_inds' to keep track of indices already used
    TreeSet<Integer> used_inds = new TreeSet<Integer>();

    long ans = 0; // Initialize an answer variable 'ans' to 0

    // Iterate through each index i from 0 to N-1
    for(int i = 0; i < N; i++){
      long left_border; // Initialize variables 'left_border' and 'right_border' to store the indices of the left and right neighbors of the current index i, respectively
      long right_border;

      long cur_ind = ind_a[i]; // Get the index of the current element a[i] in the array 'ind_a'

      // Find the index of the left neighbor of the current index i in the set 'used_inds'
      Integer left_it = used_inds.lower(cur_ind);

      // If the left neighbor does not exist, set 'left_border' to -1
      if(left_it == null){
        left_border = -1;
      } else {
        // If the left neighbor exists and its index is greater than the current index i, move the iterator left to find the index of the actual left neighbor
        if(left_it > cur_ind){
          left_it--;
        }
        left_border = left_it;
      }

      // Find the index of the right neighbor of the current index i in the set 'used_inds'
      Integer right_it = used_inds.higher(cur_ind);

      // If the right neighbor does not exist, set 'right_border' to N (the total number of elements)
      if(right_it == null){
        right_border = N;
      } else {
        right_border = right_it;
      }

      // Calculate the contribution of the current index i to the answer 'ans'
      ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

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

