
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declaring a variable 'data' of type 'int' to read user input
        int data;

        // Reading user input and storing it in the 'data' variable
        Scanner scanner = new Scanner(System.in);
        data = scanner.nextInt();

        // Declaring a variable 'result' of type 'int' to store the result
        int result;

        // Assigning the value of 'data' cubed to the 'result' variable
        result = data * data * data;

        // Printing the result using the 'System.out.println' method
        System.out.println(result); // Printing the result with format specifier '%d' and newline character '\n'
    }
}

