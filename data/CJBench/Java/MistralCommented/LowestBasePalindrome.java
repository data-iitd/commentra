
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    private Main() {}

    // Initializes the scanner and reads an integer from the standard input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        scanner.close();

        // Checks if the input number is valid
        checkNumber(number);

        // Computes the lowest base palindrome for the given number
        int base = lowestBasePalindrome(number);

        // Prints the result to the standard output
        System.out.println(base);
    }

    // Throws an IllegalArgumentException if the base is not greater than 1
    private static void checkBase(int base) {
        if (base <= 1) {
            throw new IllegalArgumentException("Base must be greater than 1.");
        }
    }

    // Throws an IllegalArgumentException if the number is negative
    private static void checkNumber(int number) {
        if (number < 0) {
            throw new IllegalArgumentException("Number must be non-negative.");
        }
    }

    // Computes the digits of a number in a given base and returns them as a list
    public static List<Integer> computeDigitsInBase(int number, int base) {
        checkNumber(number);
        checkBase(base);

        // Initializes an empty list to store the digits
        List<Integer> digits = new ArrayList<>();

        // Computes the digits of the number in the given base and adds them to the list
        while (number > 0) {
            digits.add(number % base);
            number /= base;
        }

        // Returns the list of digits
        return digits;
    }

    // Checks if a list of integers is a palindrome
    public static boolean isPalindromic(List<Integer> list) {
        int size = list.size();

        // Checks if the list has an odd length, which means it cannot be a palindrome
        if (size % 2 != 0) {
            return false;
        }

        // Compares the first and last elements of the list and moves towards the middle
        for (int i = 0; i < size / 2; i++) {
            if (!list.get(i).equals(list.get(size - 1 - i))) {
                return false;
            }
        }

        // Returns true if the list is a palindrome
        return true;
    }

    // Checks if a number is a palindrome in a given base
    public static boolean isPalindromicInBase(int number, int base) {
        checkNumber(number);
        checkBase(base);

        // Returns true if the number is less than or equal to 1, as these numbers are palindromes in any base
        if (number <= 1) {
            return true;
        }

        // Checks if the number is a multiple of the base, which means it cannot be a palindrome in this base
        if (number % base == 0) {
            return false;
        }

        // Computes the digits of the number in the given base and checks if the list is a palindrome
        List<Integer> digits = computeDigitsInBase(number, base);
        return isPalindromic(digits);
    }

    // Computes the lowest base palindrome for a given number
    public static int lowestBasePalindrome(int number) {
        checkNumber(number);

        // Initializes the base to 2 and increments it until a palindrome is found
        int base = 2;
        while (!isPalindromicInBase(number, base)) {
            base++;
        }

        // Returns the base as the result
        return base;
    }
}