
import java.util.Scanner;

public class s844088973{
  public static void main(String[] args) {
    // Declare two integer variables K and X
    Scanner scanner = new Scanner(System.in);
    int K = scanner.nextInt();
    int X = scanner.nextInt();

    // Loop from (X - K + 1) to (X + K - 1)
    for(int i = X - K + 1; i <= X + K - 1; i++){
      // Print the current value of i
      System.out.print(i);
      
      // If i is not the last number, print a space after it
      if(i < X + K - 1) 
          System.out.print(" ");
    }

    // Print a newline character after the loop completes
    System.out.println();

    // Return 0 to indicate successful completion of the program
    System.exit(0);
  }
}
