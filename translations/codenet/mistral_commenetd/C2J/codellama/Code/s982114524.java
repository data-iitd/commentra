
public class Main {
  public static void main(String[] args) {
    int i, N, x; // Declare and initialize three integer variables: i, N, and x
    x = 0; // Initialize x to 0

    // Prompt the user to enter a number
    System.out.print("Enter a number: ");
    Scanner scanner = new Scanner(System.in);
    N = scanner.nextInt();

    // Use a for loop to iterate from 1 to N and sum up the numbers
    for(i=1; i<=N; i++){
      x += i; // Add the current value of i to x
    }

    // Print the sum of the numbers to the console
    System.out.println("The sum of numbers from 1 to " + N + " is: " + x);
  }
}

