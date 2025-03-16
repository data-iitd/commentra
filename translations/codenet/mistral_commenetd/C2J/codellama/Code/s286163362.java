
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in); // Initialize a Scanner object 'sc' to read from the standard input.

    while(true){ // Start an infinite loop.

      int n = sc.nextInt(); // Read the number of elements 'n' from the standard input.
      int k = sc.nextInt(); // Read the size of the sequence 'k' from the standard input.
      if(n == 0 && k == 0)break; // If both 'n' and 'k' are zero, break the loop.

      int[] data = new int[111111]; // Initialize an array 'data' of size 111111 for storing the frequency of each number.
      int[] seq = new int[222222]; // Initialize an array 'seq' of size 222222 for storing the sequence numbers.

      for(int i = 0; i < k; i++){ // Loop through each number in the sequence.
        int t = sc.nextInt(); // Read a number 't' from the standard input.
        data[t]++; // Increment the frequency of the number 't' in the 'data' array.
      }

      int p = 0; // Initialize a pointer 'p' to the first element of the 'seq' array.
      for(int i = 1; i <= n; i++){ // Loop through each number from 1 to 'n'.
        if(data[i]){ // If the frequency of the number 'i' is not zero, increment the corresponding element in the 'seq' array.
          seq[p]++;
        } else { // If the frequency of the number 'i' is zero, move the pointer 'p' to the next even index.
          p+=2;
        }
      }
      p++; // Increment the pointer 'p' to the next index.

      if(data[0]){ // If the frequency of the number 0 is not zero, calculate the maximum sum of consecutive sequences in the 'seq' array.
        int ret = 0; // Initialize a variable 'ret' to store the maximum sum.
        for(int i=0;i<p;i++){
          ret = Math.max(ret,seq[i]+seq[i+2]+1); // Calculate the sum of the current and next sequence and update the maximum sum if necessary.
        }
      } else { // If the frequency of the number 0 is zero, calculate the maximum sum of sequences in the 'seq' array.
        int ret = 0; // Initialize a variable 'ret' to store the maximum sum.
        for(int i=0;i<p;i++){
          ret = Math.max(ret,seq[i]); // Calculate the sum of the current sequence and update the maximum sum if necessary.
        }
      }

      System.out.println(ret); // Print the maximum sum of sequences to the standard output.
    }

  }

}

