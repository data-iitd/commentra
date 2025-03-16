
import java.util.*; // Import the Scanner class from the java.util package for reading input.

public class s107598592{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input.
    int N = sc.nextInt(); // Read the number of elements N from the standard input.
    int[] X = new int[N]; int[] Y = new int[N]; // Declare two arrays X and Y of size N to store the elements.
    
    // Read N elements into array X and simultaneously copy them to array Y.
    for(int i = 0; i < N; i++){ 
      X[i] = sc.nextInt(); 
      Y[i] = X[i]; 
    }
    
    // Sort the array Y in ascending order.
    Arrays.sort(Y);
    
    // Calculate the median of the sorted array Y. The median is the middle element for odd N, and the average of the two middle elements for even N.
    int y = Y[N/2];
    
    // Iterate through each element in array X and output the appropriate median value based on the comparison with y.
    for(int i = 0; i < N; i++){
      if(X[i] < y){
        System.out.println(y); // If the element in X is less than the median, output the median.
      } else {
        System.out.println(y - 1); // Otherwise, output the median minus one.
      }
    }
    
    sc.close(); // Close the Scanner object to release system resources.
  }
}
