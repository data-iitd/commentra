
public class s760945395{
  public static void main(String[] args) {
    // Loop to iterate 5 times
    for (int i = 0; i < 5; i++) {
      Scanner scanner = new Scanner(System.in); // Create a scanner to read user input
      int a = scanner.nextInt(); // Read an integer input from the user and store it in 'a'
      
      // Check if the input value is zero
      if (a == 0) {
        // Print the current iteration index + 1 if the input is zero
        System.out.println(i + 1);
      }
    }
  }
}
