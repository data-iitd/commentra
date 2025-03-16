public class Main {
    public static void main(String[] args) {
        int a; // Declare an integer variable 'a' to store user input

        // Prompt the user to enter a value for 'a'
        System.out.print("Enter a number: "); 
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a Scanner object to read input
        a = scanner.nextInt(); // Read the input value from the user and store it in 'a'

        // Calculate the expression a + a^2 + a^3 and output the result
        System.out.println(a + (a * a) + (a * a * a));
    }
}
