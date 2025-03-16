import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    // Read the number of elements
    int N;
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();

    // Input the elements into array 'a'
    long[] a = new long[N];
    for(int i = 0; i < N; i++){
      a[i] = sc.nextLong();
    }

    // Populate 'ind_a' with the indices of the elements in 'a'
    int[] ind_a = new int[N];
    for(int i = 0; i < N; i++){
      ind_a[a[i] - 1] = i; // Store the index of each element based on its value
    }

    // Set to keep track of used indices
    Set<Integer> used_inds = new HashSet<Integer>();
    long ans = 0; // Variable to accumulate the final answer

    // Iterate through each element's index
    for(int i = 0; i < N; i++){
      long left_border; // Variable to store the left border index
      long right_border; // Variable to store the right border index
      long cur_ind = ind_a[i]; // Current index of the element being processed

      // Find the first used index that is not less than cur_ind
      Iterator<Integer> left_it = used_inds.lower(cur_ind);
      // Find the first used index that is greater than cur_ind
      Iterator<Integer> right_it = used_inds.lower(cur_ind + 1);

      // Determine the left border
      if(left_it.hasNext() == false){
        left_border = -1; // No used index to the left
      } else {
        if(right_it.hasNext() == false || right_it.next() > cur_ind){
          left_it.previous(); // Move to the previous index
        }
        left_border = left_it.next(); // Set the left border to the found index
      }

      // Determine the right border
      if(right_it.hasNext() == false){
        right_border = N; // No used index to the right
      } else {
        right_border = right_it.next(); // Set the right border to the found index
      }

      // Calculate the contribution of the current index to the answer
      ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long)i + 1);

      // Uncomment the lines below for debugging purposes
      // System.out.println(i + " " + left_border + " " + right_border);
      // System.out.println(ans);

      // Insert the current index into the set of used indices
      used_inds.add(cur_ind);
    }

    // Output the final answer
    System.out.println(ans);
  }
}

