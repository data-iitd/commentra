public class Main {
    public static void main(String[] args) {
        int i = 1;
        int Input;

        // Start an infinite loop
        while (true) {
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            Input = scanner.nextInt(); // Read an integer from the user
            if (Input == 0) {          // Check if the input is 0
                break;                // Exit the loop if the input is 0
            }
            System.out.printf("Case %d: %d\n", i, Input); // Print the current case number and input value
            i++;                      // Increment the case number
        }
    }
}
