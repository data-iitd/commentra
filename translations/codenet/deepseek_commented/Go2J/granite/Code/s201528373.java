

import java.util.Scanner;
 
public class s201528373{
  public static void main(String[] args) {
    // Declare variables to hold the number of elements, the target sum, and the list of integers
    int n, x;
    int[] l;
    
    // Create a Scanner object to read input from the standard input
    Scanner scanner = new Scanner(System.in);
    
    // Read the number of elements and the target sum from the standard input
    n = scanner.nextInt();
    x = scanner.nextInt();
    
    // Create an array of size n to store the list of integers
    l = new int[n];
    
    // Read n integers from the standard input and store them in the array l
    for (int i = 0; i < n; i++) {
      l[i] = scanner.nextInt();
    }
    
    // Initialize variables to keep track of the sum and the result
    int tmpSum = 0;
    int rs = 0;
    
    // Iterate over the array l, updating the sum and checking the condition
    for (int i = 0; i < n; i++) {
      tmpSum += l[i];
      // If the sum is less than or equal to x, update the result
      if (tmpSum <= x) {
        rs = i + 2;
      } else if (tmpSum > x) {
        break;
      }
    }
    
    // Print the result
    System.out.println(rs);
  }
}
