import java.util.*;
public final class Main {
    private Main() {
    }

    // Luhn algorithm implementation to validate credit card numbers
    public static boolean luhnCheck(int[] digits) {
        int[] numbers = Arrays.copyOf(digits, digits.length); // Copy the input array
        int sum = 0;
        for (int i = numbers.length - 1; i >= 0; i--) {
            if ((numbers.length - i) % 2 == 0) { 
                int temp = numbers[i] * 2; // Double every second digit from the right
                if (temp > 9) {
                    temp = temp - 9; // If doubling results in a number greater than 9, subtract 9
                }
                numbers[i] = temp; // Update the digit
            }
            sum += numbers[i]; // Add the digit to the sum
        }
        return sum % 10 == 0; // Check if the sum is divisible by 10
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the number of digits
        int[] inputDigits = new int[n];
        for (int i = 0; i < n; i++) {
            inputDigits[i] = sc.nextInt(); // Read the digits
        }
        boolean isValid = luhnCheck(inputDigits); // Validate the card number using Luhn algorithm
        System.out.println("The input is " + (isValid ? "valid" : "not valid") + " according to the Main algorithm.");
        sc.nextLine(); 
        String cardNumber = sc.nextLine(); // Read the card number as a string
        try {
            CreditCard creditCard = CreditCard.fromString(cardNumber); // Create a CreditCard object
            System.out.println("Credit card is valid: " + creditCard); // Print whether the card is valid
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage()); // Print error message if the card number is invalid
        }
        sc.close(); // Close the Scanner
    }

    // Private nested class to encapsulate credit card logic
    private static class CreditCard {
        private static final int DIGITS_COUNT = 16; // Number of digits in a credit card number
        private final int[] digits; // Array of digits representing the card number

        // Constructor for CreditCard
        public CreditCard(int[] digits) {
            this.digits = digits;
        }

        // Method to create a CreditCard object from a string
        public static CreditCard fromString(String cardNumber) {
            Objects.requireNonNull(cardNumber); // Ensure the card number is not null
            String trimmedCardNumber = cardNumber.replaceAll(" ", ""); // Remove spaces from the card number
            if (trimmedCardNumber.length() != DIGITS_COUNT || !trimmedCardNumber.matches("\\d+")) {
                throw new IllegalArgumentException("{" + cardNumber + "} - is not a valid card number"); // Validate the card number format
            }
            int[] cardNumbers = toIntArray(trimmedCardNumber); // Convert the card number string to an array of digits
            if (!luhnCheck(cardNumbers)) { // Validate the card number using the Luhn algorithm
                throw new IllegalArgumentException("Credit card number {" + cardNumber + "} failed the Main check"); // Throw an exception if the card number is invalid
            }
            return new CreditCard(cardNumbers); // Return the CreditCard object
        }

        // Method to format the card number for display
        public String number() {
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < DIGITS_COUNT; i++) {
                if (i % 4 == 0 && i != 0) {
                    result.append(" "); // Add a space every four digits
                }
                result.append(digits[i]); // Append the digit to the result
            }
            return result.toString(); // Return the formatted card number
        }

        // Override the toString method to provide a string representation of the CreditCard object
        @Override
        public String toString() {
            return String.format("CreditCard[number=%s]", number()); // Return the formatted string
        }

        // Method to convert a string of digits to an array of integers
        private static int[] toIntArray(String string) {
            return string.chars().map(Character::getNumericValue).toArray(); // Convert each character to its numeric value and return the array
        }
    }
}
