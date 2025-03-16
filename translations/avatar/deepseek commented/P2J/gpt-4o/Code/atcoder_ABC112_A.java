import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object for input
        int age = scanner.nextInt();  // Taking an integer input for the variable `age`
        
        if (age == 1) {  // Checking if `age` is equal to 1
            System.out.println("Hello World");  // If `age` is 1, it prints "Hello World"
        } else {  // If `age` is not 1
            int a = scanner.nextInt();  // Taking the first integer input and assigning it to variable `a`
            int b = scanner.nextInt();  // Taking the second integer input and assigning it to variable `b`
            System.out.println(a + b);  // Printing the sum of `a` and `b`
        }
        
        scanner.close();  // Closing the scanner
    }
}

// <END-OF-CODE>
