
public class s760945395{
  public static void main(String[] args) {
    // The code starts a loop that will run 5 times
    for (int i = 0; i < 5; i++) {
      // Declares an integer variable 'a' to store the input
      int a;
      // Reads an integer input from the user and stores it in 'a'
      Scanner scanner = new Scanner(System.in);
      a = scanner.nextInt();
      // Checks if the input is 0
      if (a == 0) {
        // Prints the current iteration number (starting from 1)
        System.out.println(i + 1);
      }
    }
  }
}
