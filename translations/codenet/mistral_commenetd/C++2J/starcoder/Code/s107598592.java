
import java.util.*;

public class Main{
  public static void main(String[] args){
    int N; // Number of elements in the vector

    // Taking input of N from the user
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();

    // Declaring two vectors X and Y of size N
    int[] X = new int[N];
    int[] Y = new int[N];

    // Filling the vectors X and Y with user input
    for(int i = 0; i < N; i++){
      X[i] = sc.nextInt(); // Taking input of X[i] from the user
      Y[i] = X[i]; // Assigning X[i] to Y[i]
    }

    // Sorting the vector Y in ascending order
    Arrays.sort(Y);

    // Finding the middle element of sorted vector Y
    int y = Y[N/2];

    // Iterating through the vector X and printing the middle element of Y based on the condition
    for(int i = 0; i < N; i++){
      if( X[i] < Y[N/2]){ // Checking if X[i] is less than the middle element of Y
        System.out.println(Y[N/2]); // If true, print the middle element of Y
      }
      else{ // If X[i] is greater than or equal to the middle element of Y
        System.out.println(Y[N/2 - 1]); // Print the middle element of Y - 1
        break; // Exit the loop as we have found the required element
      }
      System.out.println(); // Print a newline after each element
    }

    // End of main function
  }
}

