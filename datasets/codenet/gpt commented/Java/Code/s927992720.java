import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Infinite loop to continuously accept user input until a specific condition is met
        while (true) {
            // Read the first integer input
            int a = sc.nextInt();
            // Read the operator as a string
            String op = sc.next();
            // Read the second integer input
            int b = sc.nextInt();
            
            // Check if the operator is "?" to exit the loop
            if (op.equals("?")) break;
            // Perform addition if the operator is "+"
            if (op.equals("+")) System.out.println(a + b);
            // Perform subtraction if the operator is "-"
            if (op.equals("-")) System.out.println(a - b);
            // Perform multiplication if the operator is "*"
            if (op.equals("*")) System.out.println(a * b);
            // Perform division if the operator is "/"
            if (op.equals("/")) System.out.println(a / b);
        }
        // Close the scanner to prevent resource leaks (optional but good practice)
        sc.close();
    }
}
