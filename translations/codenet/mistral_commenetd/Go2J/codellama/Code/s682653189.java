
public class Main {
    public static void main(String[] args) {
        // Initialize a variable "s" of type String.
        String s = "";

        // Read a single string from the standard input (usually the keyboard) and store it in the variable "s".
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();

        // Iterate through each character in the string "s" using a for loop.
        for (int i = 0; i < s.length(); i++) {
            // Print the character at the current index "i" of the string "s" to the standard output (usually the terminal).
            System.out.print("x");
        }

        // Print a newline character to the standard output.
        System.out.println("");

        // Indicate the end of the code.
        System.out.println("