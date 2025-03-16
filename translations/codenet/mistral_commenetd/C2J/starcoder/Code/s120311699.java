
import java.util.Scanner; // Importing the Scanner class from the java.util package

public class Main{ // Starting the Main class
  public static void main(String[] args){ // Starting the main function
    Scanner input = new Scanner(System.in); // Creating a Scanner object named input and passing the System.in stream to it

    int a = input.nextInt(); // Reading an integer from the standard input and storing it in a
    int b = input.nextInt(); // Reading an integer from the standard input and storing it in b
    int c = input.nextInt(); // Reading an integer from the standard input and storing it in c

    if(a<b && b<c){ // Starting the if condition block
      System.out.println("Yes"); // If the condition is true, print "Yes" to the standard output
    }else{ // Starting the else condition block
      System.out.println("No"); // If the condition is false, print "No" to the standard output
    }
  }
}
