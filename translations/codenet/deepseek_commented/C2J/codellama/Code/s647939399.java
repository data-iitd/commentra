// Step 1: Include the standard input/output library.
import java.util.Scanner;

public class Main{  // Step 2: Define the main class.
  public static void main(String[] args){  // Step 3: Define the main function.
    Scanner sc = new Scanner(System.in);  // Step 4: Create a new Scanner object to read input from the standard input.
    int a,b,i,j;  // Declare two integers 'a' and 'b', and two integer variables 'i' and 'j'.
    char m;  // Declare a character variable 'm'.
    int[] c = new int[256];  // Declare an array 'c' of size 256.

    for(i=0;i>-1;i++){  // Step 5: Start an infinite loop using a 'for' loop with no condition.
      a = sc.nextInt();  // Step 6: Read an integer 'a' from the standard input.
      m = sc.next().charAt(0);  // Step 7: Read a character 'm' from the standard input.
      b = sc.nextInt();  // Step 8: Read an integer 'b' from the standard input.
      if(m=='?'){  // Step 9: Check if the character 'm' is '?'. If true, break the loop.
        break;
      }
      if(m=='+'){  // Step 10: Depending on the character 'm', perform the corresponding arithmetic operation and store the result in the array 'c' at index 'i'.
        c[i]=a+b;
      }
      if(m=='-'){
        c[i]=a-b;
      }
      if(m=='*'){
        c[i]=a*b;
      }
      if(m=='/'){
        c[i]=a/b;
      }
    }

    for(j=0;j<i;j++){  // Step 12: After the loop ends, start another loop to print the results stored in the array 'c' from index 0 to 'i-1'.
      System.out.println(c[j]);
    }
  }
}
