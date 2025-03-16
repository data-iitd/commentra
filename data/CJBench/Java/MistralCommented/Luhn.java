
import java.util.*;

public final class Main {
    private Main() {
    }

    // Private constructor to prevent instantiation of the class from outside

    public static boolean luhnCheck(int[] digits) {
        int[] numbers = Arrays.copyOf(digits, digits.length); // Create a copy of the input array to modify it in place
        int sum = 0; // Initialize sum variable to store the sum of digits

        for (int i = numbers.length - 1; i >= 0; i--) { // Iterate through the array from the last digit to the first one
            if ((numbers.length - i) % 2 == 0) { // If the current index is even
                int temp = numbers[i] * 2; // Multiply the current digit by 2
                if (temp > 9) { // If the result is greater than 9
                    temp -= 9; // Subtract 9 to get the first digit of the result
                }
                numbers[i] = temp; // Update the current digit with the first digit of the result
            }
            sum += numbers[i]; // Add the current digit (or its doubled value) to the sum
        }

        return sum % 10 == 0; // Return true if the sum is a multiple of 10, indicating a valid number according to the Luhn algorithm
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the console

        // Read the number of digits in the input card number
        int n = sc.nextInt();

        int[] inputDigits = new int[n]; // Create an array to store the input digits

        // Read the input digits from the console
        for (int i = 0; i < n; i++) {
            inputDigits[i] = sc.nextInt();
        }

        boolean isValid = luhnCheck(inputDigits); // Check if the input digits form a valid number according to the Luhn algorithm

        System.out.println("The input is " + (isValid ? "valid" : "not valid") + " according to the Main algorithm."); // Print the result

        sc.nextLine(); // Consume the newline character left after reading the integer input

        String cardNumber = sc.nextLine(); // Read the credit card number as a string from the console

        try {
            CreditCard creditCard = CreditCard.fromString(cardNumber); // Create a CreditCard object from the input string
            System.out.println("Credit card is valid: " + creditCard); // Print the valid credit card object
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage()); // Print the error message if the input is invalid
        }

        sc.close(); // Close the Scanner object
    }

    private static class CreditCard {
        private static final int DIGITS_COUNT = 16; // Constant representing the number of digits in a credit card number

        private final int[] digits; // Store the digits of the credit card number

        public CreditCard(int[] digits) { // Constructor to initialize the CreditCard object with the input digits
            this.digits = digits;
        }

        public static CreditCard fromString(String cardNumber) { // Static method to create a CreditCard object from a string representation of the card number
            Objects.requireNonNull(cardNumber); // Check if the input string is not null

            String trimmedCardNumber = cardNumber.replaceAll(" ", ""); // Remove any spaces from the input string

            if (trimmedCardNumber.length() != DIGITS_COUNT || !trimmedCardNumber.matches("\\d+")) { // Check if the input string has the correct length and is composed only of digits
                throw new IllegalArgumentException("{" + cardNumber + "} - is not a valid card number"); // Throw an exception if the input is invalid
            }

            int[] cardNumbers = toIntArray(trimmedCardNumber); // Convert the input string to an array of integers

            if (!luhnCheck(cardNumbers)) { // Check if the input digits form a valid number according to the Luhn algorithm
                throw new IllegalArgumentException("Credit card number {" + cardNumber + "} failed the Main check"); // Throw an exception if the input is invalid
            }

            return new CreditCard(cardNumbers); // Return a new CreditCard object with the valid digits
        }

        public String number() { // Method to format and return the credit card number as a string
            StringBuilder result = new StringBuilder();

            for (int i = 0; i < DIGITS_COUNT; i++) { // Iterate through each digit and add a space every 4 digits (except for the last one)
                if (i % 4 == 0 && i != 0) {
                    result.append(" ");
                }
                result.append(digits[i]);
            }

            return result.toString();
        }

        @Override
        public String toString() { // Override the default toString method to return a meaningful string representation of the CreditCard object
            return String.format("CreditCard[number=%s]", number());
        }

        private static int[] toIntArray(String string) { // Helper method to convert a string to an array of integers
            return string.chars().map(Character::getNumericValue).toArray();
        }
    }
}