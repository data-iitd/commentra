import java.util.Scanner;  // Import the Scanner class

public class Main {  // Define the main class

  public static void main(String[] args) {  // Define the main function, which returns nothing

    Scanner input = new Scanner(System.in);  // Create a Scanner object to read input from the user
    int S = input.nextInt();  // Read an integer input from the user and store it in S

    // Check if S is less than 60
    if (S < 60)
      {
        System.out.printf("0:0:%d\n", S);  // Print "0:0:S" if S is less than 60
      }
    
    // Check if S is less than 3600
    else if (S < 3600)
      {
        System.out.printf("0:%d:%d\n", S / 60, S % 60);  // Print "0:S/60:S%60" if S is less than 3600
      }
    
    // If S is not less than 3600
    else
      {
        System.out.printf("%d:%d:%d\n", S / 3600, S % 3600 / 60, S % 60 % 60);  // Print "S/3600:S%3600/60:S%60" if S is not less than 3600
      }
  }
}
