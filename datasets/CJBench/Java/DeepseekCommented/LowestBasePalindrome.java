import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    private Main() {} // Ensures that no instances of Main can be created

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt(); // Reads an integer from the user
        scanner.close(); // Closes the scanner
        int base = lowestBasePalindrome(number); // Finds the lowest base in which the number is palindromic
        System.out.println(base); // Prints the base
    }

    private static void checkBase(int base) {
        if (base <= 1) {
            throw new IllegalArgumentException("Base must be greater than 1."); // Throws an exception if base is less than or equal to 1
        }
    }

    private static void checkNumber(int number) {
        if (number < 0) {
            throw new IllegalArgumentException("Number must be non-negative."); // Throws an exception if number is negative
        }
    }

    public static List<Integer> computeDigitsInBase(int number, int base) {
        checkNumber(number); // Checks if the number is non-negative
        checkBase(base); // Checks if the base is greater than 1
        List<Integer> digits = new ArrayList<>();
        while (number > 0) {
            digits.add(number % base); // Adds the remainder to the list
            number /= base; // Divides the number by the base
        }
        return digits; // Returns the list of digits
    }

    public static boolean isPalindromic(List<Integer> list) {
        int size = list.size();
        for (int i = 0; i < size / 2; i++) {
            if (!list.get(i).equals(list.get(size - 1 - i))) { // Checks if the list is the same forwards and backwards
                return false;
            }
        }
        return true; // Returns true if the list is palindromic
    }

    public static boolean isPalindromicInBase(int number, int base) {
        checkNumber(number); // Checks if the number is non-negative
        checkBase(base); // Checks if the base is greater than 1
        if (number <= 1) {
            return true; // Numbers 0 and 1 are palindromic in any base
        }
        if (number % base == 0) {
            return false; // If the number is divisible by the base, it cannot be palindromic
        }
        return isPalindromic(computeDigitsInBase(number, base)); // Checks if the digits in the base form a palindrome
    }

    public static int lowestBasePalindrome(int number) {
        checkNumber(number); // Checks if the number is non-negative
        int base = 2;
        while (!isPalindromicInBase(number, base)) { // Finds the smallest base in which the number is palindromic
            base++;
        }
        return base; // Returns the smallest base
    }
}
