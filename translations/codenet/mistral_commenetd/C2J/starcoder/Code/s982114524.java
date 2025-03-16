
// The main function is the starting point of the program
public class Main {
  public static void main(String[] args) {
    int i, N, x; // Declare and initialize three integer variables: i, N, and x
    x = 0; // Initialize x to 0

    // Prompt the user to enter a number
    System.out.print("Enter a number: ");
    N = Integer.parseInt(System.console().readLine());

    // Use a for loop to iterate from 1 to N and sum up the numbers
    for(i=1; i<=N; i++){
      x += i; // Add the current value of i to x
    }

    // Print the sum of the numbers to the console
    System.out.printf("The sum of numbers from 1 to %d is: %d\n", N, x);
  }
}
