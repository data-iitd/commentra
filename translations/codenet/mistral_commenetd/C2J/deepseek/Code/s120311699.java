import java.util.Scanner; // Importing the Scanner class to read input from the user

public class Main { // Starting the Main class
  public static void main(String[] args) { // Starting the main method
    Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input from the user
    int a, b, c; // Declaring three integer variables a, b, and c
    a = scanner.nextInt(); // Reading the first integer from the user and storing it in variable a
    b = scanner.nextInt(); // Reading the second integer from the user and storing it in variable b
    c = scanner.nextInt(); // Reading the third integer from the user and storing it in variable c

    if(a < b && b < c){ // Starting the if condition block
      System.out.println("Yes"); // If the condition is true, print "Yes" to the standard output
    } else { // Starting the else condition block
      System.out.println("No"); // If the condition is false, print "No" to the standard output
    }

    scanner.close(); // Closing the Scanner object
  }
}
