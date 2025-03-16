
import java.util.*;

public class s791749917{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long H = sc.nextLong(); // Input the height and width from the user
    long W = sc.nextLong();

    long ans; // Variable to store the final answer
    // Check if either height or width is 1
    if (H == 1 || W == 1) {
      ans = 1; // If either dimension is 1, the answer is 1
    } else {
      long m = H * W; // Calculate the total number of cells (H * W)
      // Check if the total number of cells is even or odd
      if (m % 2 == 0) 
        ans = m / 2; // If even, half of the cells can be filled
      else 
        ans = m / 2 + 1; // If odd, half plus one cell can be filled
    }
    
    System.out.println(ans); // Output the final answer
  }
}
