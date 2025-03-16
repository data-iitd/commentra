import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold two integers and a character for the operation
        int a, b;
        char S;

        // Start an infinite loop to continuously accept user input
        while (true) {
            // Read two integers and an operator from the user
            Scanner sc = new Scanner(System.in);
            a = sc.nextInt();
            S = sc.next().charAt(0);
            b = sc.nextInt();

            // Perform addition if the operator is '+'
            if (S == '+') 
                System.out.println(a + b);

            // Perform subtraction if the operator is '-'
            if (S == '-') 
                System.out.println(a - b);

            // Perform multiplication if the operator is '*'
            if (S == '*') 
                System.out.println(a * b);

            // Perform division if the operator is '/'
            if (S == '/') 
                System.out.println(a / b);

            // Exit the loop if the operator is '?'
            if (S == '?') 
                break;
        }
    }
}

