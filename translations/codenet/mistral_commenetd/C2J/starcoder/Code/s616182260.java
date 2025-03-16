
import java.util.*;
public class Main{
  public static void main(String[] args){
    // Declare the required arrays and their sizes
    int a[] = new int[3];
    int b[] = new int[3];
    int c[][] = new int[3][3];

    // Initialize the matrix 'c' with user input
    Scanner sc = new Scanner(System.in);
    for(int i=0;i<3;i++){
      System.out.print("Enter the elements of row "+(i+1)+": ");
      c[i][0] = sc.nextInt();
      c[i][1] = sc.nextInt();
      c[i][2] = sc.nextInt();
    }

    // Initialize array 'a' with the first row of matrix 'c'
    a[0] = 0;
    for(int i=0;i<3;i++){
      b[i] = c[0][i]; // Store the elements of the first row of matrix 'c' in array 'b'
    }

    // Initialize array 'a' with the difference between the corresponding elements of matrix 'c' and array 'b'
    for(int i=1;i<3;i++){
      a[i] = c[i][0] - b[0]; // Subtract the first element of each row of matrix 'c' from the corresponding element of array 'b' and store the result in array 'a'
    }

    // Compare each element of matrix 'c' with the corresponding elements of array 'a' and 'b'
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(c[i][j]!= a[i] + b[j]){ // Check if the element at position (i,j) in matrix 'c' is equal to the sum of the elements at position i in array 'a' and j in array 'b'
          System.out.println("No"); // If not, print "No" and exit the program
          return;
        }
      }
    }

    // If all the elements in matrix 'c' match the condition, print "Yes"
    System.out.println("Yes");
  }
}
