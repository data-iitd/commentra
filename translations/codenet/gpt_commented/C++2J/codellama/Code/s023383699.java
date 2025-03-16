public class Main {
    public static void main(String[] args) {
        int x; // Declare an integer variable 'x' to store user input
        x = Integer.parseInt(args[0]); // Read an integer value from the user and store it in 'x'
        
        // Calculate the cube of 'x' and print the result
        System.out.println(x * x * x); // Output the cube of 'x' followed by a newline
    }
}
