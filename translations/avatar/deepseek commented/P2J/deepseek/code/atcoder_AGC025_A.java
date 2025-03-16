import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();  // Taking an input from the user and storing it in the variable `n`.
        String[] a = {"10", "100", "1000", "10000", "100000"};  // Defining an array `a` containing string representations of numbers.
        int newSum = 0;  // Initializing a variable `newSum` to store the sum of the digits of `n`.

        // Converting the input `n` to a list of its digits, summing them up, and storing the result in `newSum`.
        for (char digit : n.toCharArray()) {
            newSum += Character.getNumericValue(digit);
        }

        boolean isInArray = false;  // Initializing a boolean variable `isInArray` to check if `n` is in the array `a`.
        for (String num : a) {  // Iterating through the array `a` to check if `n` is in it.
            if (n.equals(num)) {
                isInArray = true;
                break;
            }
        }

        if (isInArray) {  // Checking if `n` is in the array `a`.
            System.out.println(10);  // If `n` is in `a`, print the number 10.
        } else {  // Otherwise...
            System.out.println(newSum);  // Print the value of `newSum`.
        }
    }
}
