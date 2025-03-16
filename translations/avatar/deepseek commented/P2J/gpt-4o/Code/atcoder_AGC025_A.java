import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to take input from the user.
        String n = scanner.nextLine();  // Taking an input from the user and storing it in the variable `n`.
        String[] a = {"10", "100", "1000", "10000", "100000"};  // Defining an array `a` containing string representations of numbers.
        
        int newSum = 0;  // Initializing a variable to store the sum of the digits.
        for (char digit : n.toCharArray()) {  // Converting the input `n` to a character array and iterating over it.
            newSum += Character.getNumericValue(digit);  // Summing up the digits.
        }
        
        boolean found = false;  // Flag to check if `n` is found in `a`.
        for (String value : a) {  // Iterating over the array `a`.
            if (n.equals(value)) {  // Checking if `n` is equal to the current value in `a`.
                found = true;  // Set the flag to true if found.
                break;  // Exit the loop as we found a match.
            }
        }
        
        if (found) {  // If `n` is found in `a`...
            System.out.println(10);  // Print the number 10.
        } else {  // Otherwise...
            System.out.println(newSum);  // Print the value of `newSum`.
        }
        
        scanner.close();  // Closing the scanner.
    }
}
