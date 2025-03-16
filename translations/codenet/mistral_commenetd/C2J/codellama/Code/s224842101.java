
import java.util.Scanner; // Import the Scanner class

public class Main { // The Main class is the entry point of the program
  public static void main(String[] args) { // The main function is the entry point of the program
    int i, a, b, s; // Declare variables i, a, b, s of integer type
    int[] count = new int[4]; // Declare an array count of size 4 to store the count of each number

    // Initialize the count array with zeros
    for(i = 0;i < 4;i++) count[i] = 0;

    // Read three pairs of numbers from the user and update the count array accordingly
    Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the console
    for(i = 0;i < 3;i++){
      a = sc.nextInt(); // Read the first number a from the user
      b = sc.nextInt(); // Read the second number b from the user
      count[a-1]++; // Increment the count of number a in the count array
      count[b-1]++; // Increment the count of number b in the count array
    }

    // Calculate the product of all counts in the count array
    s = 1;
    for(i = 0;i < 4;i++) s *= count[i];

    // Check if the product of all counts is equal to 4
    if(s == 4) System.out.println("YES"); // If yes, print "YES" to the console
    else System.out.println("NO"); // Else, print "NO" to the console

    // Return 0 to indicate successful execution of the program
    return;
  }
}

