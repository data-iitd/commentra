
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n,r,p,c; // Declare variables n, r, p, c of type int
    int i,j,k,l; // Declare variables i, j, k, l of type int
    int a[] = new int[51]; // Declare arrays a and b of size 51
    int b[] = new int[51];

    // An infinite loop until the user inputs 0 for both n and r
    while( 1 ){
      n = sc.nextInt();
      r = sc.nextInt();
      if(!n &&!r ) // Check if both n and r are 0
        break; // If yes, break out of the loop

      // Initialize array a with values from 1 to n
      for( i=0;i<n;i++)
        a[i]=i+1;

      // Iterate r times
      for( i=0;i<r;i++){
        p = sc.nextInt();
        c = sc.nextInt();

        // Initialize array b with elements from array a
        for( j=0;j<c;j++)
          b[j] = a[n-p-c+1+j];

        // Shift elements of array a to the left by p-1 positions
        for( j=0;j<p-1;j++)
          a[n-p+j+1] = a[n-p+j];

        // Copy elements from array b to the end of array a
        for( j=n-p-c+1,k=0;k<c;j++,k++){
          a[j] = b[k];
        }

        // Print the last element of array a
        System.out.println(a[n-1]);
      }
    }
  }
}
