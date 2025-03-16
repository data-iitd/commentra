import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {}

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input from the user
        int number = scanner.nextInt();
        
        // Close the scanner to prevent resource leaks
        scanner.close();
        
        // Find the lowest base in which the number is a palindrome
        int base = lowestBasePalindrome(number);
        
        // Output the result
        System.out.println(base);
    }

    // Method to check if the base is valid (greater than 1)
    private static void checkBase(int base) {
        if (base <= 1) {
            throw new IllegalArgumentException("Base must be greater than 1.");
        }
    }

    // Method to check if the number is valid (non-negative)
    private static void checkNumber(int number) {
        if (number < 0) {
            throw new IllegalArgumentException("Number must be non-negative.");
        }
    }

    // Method to compute the digits of a number in a given base
    public static List<Integer> computeDigitsInBase(int number, int base) {
        // Validate the input number and base
        checkNumber(number);
        checkBase(base);
        
        // List to store the digits of the number in the specified base
        List<Integer> digits = new ArrayList<>();
        
        // Convert the number to the specified base and store the digits
        while (number > 0) {
            digits.add(number % base);
            number /= base;
        }
        
        // Return the list of digits
        return digits;
    }

    // Method to check if a list of integers is palindromic
    public static boolean isPalindromic(List<Integer> list) {
        int size = list.size();
        
        // Compare elements from the start and end of the list
        for (int i = 0; i < size / 2; i++) {
            if (!list.get(i).equals(list.get(size - 1 - i))) {
                return false; // Not a palindrome
            }
        }
        
        // If all comparisons passed, it is a palindrome
        return true;
    }

    // Method to check if a number is palindromic in a given base
    public static boolean isPalindromicInBase(int number, int base) {
        // Validate the input number and base
        checkNumber(number);
        checkBase(base);
        
        // Numbers 0 and 1 are palindromic in any base
        if (number <= 1) {
            return true;
        }
        
        // If the number is divisible by the base, it cannot be a palindrome
        if (number % base == 0) {
            return false;
        }
        
        // Check if the digits of the number in the specified base form a palindrome
        return isPalindromic(computeDigitsInBase(number, base));
    }

    // Method to find the lowest base in which the number is a palindrome
    public static int lowestBasePalindrome(int number) {
        // Validate the input number
        checkNumber(number);
        
        // Start checking from base 2
        int base = 2;
        
        // Increment the base until a palindromic representation is found
        while (!isPalindromicInBase(number, base)) {
            base++;
        }
        
        // Return the lowest base found
        return base;
    }
}
