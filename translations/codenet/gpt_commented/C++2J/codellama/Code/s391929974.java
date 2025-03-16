import java.util.Scanner;
import java.util.Vector;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n; // Variable to store the input number
    int[] sq = new int[10000]; // Array to store squares
    int[] fr = new int[5000]; // Array to store frequency counts
    Vector<Integer> com = new Vector<Integer>(); // Vector to store unique square values
    int tmp; // Temporary variable for calculations

    // Infinite loop to continuously read input until a zero is entered
    while(true){
      n = sc.nextInt(); // Read an integer from input
      if(n == 0) break; // Exit the loop if the input is zero

      // Calculate the squares of numbers from 1 to n-1 modulo n
      for(int i=1; i<n; i++) sq[i] = (i*i) % n;
      com.clear(); // Clear the vector for storing unique squares

      // Collect unique square values into the vector 'com'
      for(int i=1; i<n; i++){
        boolean f = true; // Flag to check if the square is unique
        for(int j=0; j<com.size(); j++){
          if(com.get(j) == sq[i]){ // Check if the square is already in 'com'
            f = false; // Not unique
            break;
          }
        }
        if(f) com.add(sq[i]); // Add to 'com' if unique
      }
 
      // Initialize frequency array to count occurrences of differences
      for(int i=0; i<=(n-1)/2; i++) fr[i] = 0;

      // Calculate the frequency of differences between unique squares
      for(int i=0; i<com.size(); i++){
        for(int j=0; j<com.size(); j++){
          if(i != j){ // Ensure we are not comparing the same element
            tmp = com.get(i) - com.get(j); // Calculate the difference
            if(tmp < 0) tmp += n; // Adjust if negative
            if(tmp > (n-1)/2) tmp = n - tmp; // Adjust to be within the range
            fr[tmp]++; // Increment the frequency count for this difference
          }
        }
      }

      // Output the frequency counts for differences from 1 to (n-1)/2
      for(int i=1; i<=(n-1)/2; i++) System.out.println(fr[i]);
    }
  }
}

