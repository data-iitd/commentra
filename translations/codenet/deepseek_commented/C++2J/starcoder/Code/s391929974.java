import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n;
    int sq[] = new int[10000]; // Declare arrays to store squares and frequencies
    Vector<Integer> com = new Vector<Integer>(); // Declare vector to store unique squares
    int tmp; // Temporary variable for calculations

    while(1){
      n = sc.nextInt(); // Read input integer n
      if(n == 0) break; // Break the loop if n is 0

      for(int i=1; i<n; i++) sq[i] = (i*i) % n; // Calculate squares modulo n
      com.clear(); // Clear the vector com to store new unique squares

      for(int i=1; i<n; i++){ // Find unique squares modulo n
	boolean f = true; // Flag to check if the square is unique
	for(int j=0; j<com.size(); j++){
	  if(com.get(j) == sq[i]){ // Check if the square is already in com
	    f = false; // Set flag to false if not unique
	    break; // Break the loop if not unique
	  }
	}
	if(f) com.add(sq[i]); // Add unique square to com if flag is true
      }

      int fr[] = new int[(n-1)/2+1]; // Initialize frequency array

      for(int i=0; i<com.size(); i++){ // Calculate differences between unique squares
	for(int j=0; j<com.size(); j++){
	  if(i!= j){ // Avoid comparing a square with itself
	    tmp = com.get(i) - com.get(j); // Calculate difference
	    if(tmp < 0) tmp += n; // Adjust if tmp is negative
	    if(tmp > (n-1)/2) tmp = n - tmp; // Adjust if tmp is greater than half of n
	    fr[tmp]++; // Increment the count for the difference
	  }
	}
      }

      for(int i=1; i<=(n-1)/2; i++) System.out.println(fr[i]); // Output the frequencies
    }
  }
}
