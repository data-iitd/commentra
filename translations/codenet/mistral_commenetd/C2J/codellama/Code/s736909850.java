
import java.util.Scanner;

public class SheepAndWolves {
   public static void main(String[] args) {
      // Create a Scanner object to read input from the command window
      Scanner input = new Scanner(System.in);

      // Read two integers from the standard input and store them in the sheep and wolf variables
      int sheep = input.nextInt();
      int wolf = input.nextInt();

      // Check if the number of wolves is greater than or equal to the number of sheep
      if(wolf >= sheep){
         // If the condition is true, print the message "unsafe" to the standard output
         System.out.println("unsafe");
      } else {
         // If the condition is false, print the message "safe" to the standard output
         System.out.println("safe");
      }

      // End the main function by returning 0 to indicate successful execution
      return 0;
   }
}

