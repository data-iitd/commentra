
import java.util.Scanner; // Importing the Scanner class from the java.util package

public class Main { // Starting the Main class
  public static void main(String[] args) { // Starting the main function
    Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read from the standard input
    int a = sc.nextInt(); // Reading an integer from the standard input and storing it in variable a
    int b = sc.nextInt(); // Reading an integer from the standard input and storing it in variable b
    int c = sc.nextInt(); // Reading an integer from the standard input and storing it in variable c

    if(a<b && b<c){ // Starting the if condition block
      System.out.println("Yes"); // If the condition is true, print "Yes" to the standard output
    }else{ // Starting the else condition block
      System.out.println("No"); // If the condition is false, print "No" to the standard output
    }
  }
}

