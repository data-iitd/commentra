// Include necessary header files
import java.util.Scanner;

// Declare and initialize variables
int n, i;
int h[] = new int[100001];
int max = -1;
int flag = 0;

public class Main {
  public static void main(String[] args) {
    // Read the number of test cases
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();

    // Read and process input
    for(i = 0;i < n;i++){
      // Read the next integer from standard input and store it in the array h
      h[i] = sc.nextInt();

      // Update the maximum height if the current height is greater
      if(max < h[i]) max = h[i];

      // Check if the difference between the current height and maximum height is greater than or equal to 2
      if(max - h[i] >= 2) flag = 1;
    }

    // Check the value of the flag and print the appropriate message to the standard output
    if(flag == 1) System.out.println("No");

    else System.out.println("Yes");

    // Return 0 to indicate successful execution
    return 0;
  }
}

