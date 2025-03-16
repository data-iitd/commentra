import java.util.Scanner; // Import the Scanner class to read input from the user

public class Main { // Define the public class Main
  public static void main(String[] args) { // The main method is the entry point of the program
    Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user
    int[] count = new int[4]; // Declare an array count of size 4 to store the count of each number

    // Initialize the count array with zeros
    for(int i = 0; i < 4; i++) count[i] = 0;

    // Read three pairs of numbers from the user and update the count array accordingly
    for(int i = 0; i < 3; i++){
      int a = scanner.nextInt(); // Read the first number a from the user
      int b = scanner.nextInt(); // Read the second number b from the user
      count[a-1]++; // Increment the count of number a in the count array
      count[b-1]++; // Increment the count of number b in the count array
    }

    // Calculate the product of all counts in the count array
    int s = 1;
    for(int i = 0; i < 4; i++) s *= count[i];

    // Check if the product of all counts is equal to 4
    if(s == 4) System.out.println("YES"); // If yes, print "YES" to the console
    else System.out.println("NO"); // Else, print "NO" to the console

    // Close the Scanner object to free up resources
    scanner.close();
  }
}
