import java.util.*;

public final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    // Method to perform Luhn check on an array of digits
    public static boolean luhnCheck(int[] digits) {
        // Create a copy of the input digits to avoid modifying the original array
        int[] numbers = Arrays.copyOf(digits, digits.length);
        int sum = 0; // Initialize sum to accumulate the processed digits

        // Iterate over the digits from right to left
        for (int i = numbers.length - 1; i >= 0; i--) {
            // Double every second digit from the right
            if ((numbers.length - i) % 2 == 0) { 
                int temp = numbers[i] * 2; // Double the digit
                // If the result is greater than 9, subtract 9
                if (temp > 9) {
                    temp = temp - 9;
                }
                numbers[i] = temp; // Update the digit in the array
            }
            sum += numbers[i]; // Add the processed digit to the sum
        }
        // Return true if the sum is a multiple of 10 (valid Luhn number)
        return sum % 10 == 0;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for input
        int n = sc.nextInt(); // Read the number of digits
        int[] inputDigits = new int[n]; // Initialize an array to hold the digits

        // Read the digits from input
        for (int i = 0; i < n; i++) {
            inputDigits[i] = sc.nextInt();
        }

        // Perform Luhn check on the input digits and store the result
        boolean isValid = luhnCheck(inputDigits);
        // Output the validity of the input according to the Luhn algorithm
        System.out.println("The input is " + (isValid ? "valid" : "not valid") + " according to the Main algorithm.");

        sc.nextLine(); // Consume the newline character after the integer input
        String cardNumber = sc.nextLine(); // Read the credit card number from input

        // Try to create a CreditCard object from the input string
        try {
            CreditCard creditCard = CreditCard.fromString(cardNumber);
            // Output the validity of the credit card
            System.out.println("Credit card is valid: " + creditCard);
        } catch (IllegalArgumentException e) {
            // Handle invalid credit card input
            System.out.println("Error: " + e.getMessage());
        }
        sc.close(); // Close the scanner to free resources
    }

    // Nested class to represent a Credit Card
    private static class CreditCard {
        private static final int DIGITS_COUNT = 16; // Constant for the number of digits in a credit card
        private final int[] digits; // Array to hold the credit card digits

        // Constructor to initialize the CreditCard with digits
        public CreditCard(int[] digits) {
            this.digits = digits;
        }

        // Static method to create a CreditCard object from a string representation
        public static CreditCard fromString(String cardNumber) {
            // Ensure the card number is not null
            Objects.requireNonNull(cardNumber);
            // Remove spaces from the card number
            String trimmedCardNumber = cardNumber.replaceAll(" ", "");
            // Validate the length and format of the card number
            if (trimmedCardNumber.length() != DIGITS_COUNT || !trimmedCardNumber.matches("\\d+")) {
                throw new IllegalArgumentException("{" + cardNumber + "} - is not a valid card number");
            }
            // Convert the trimmed card number to an integer array
            int[] cardNumbers = toIntArray(trimmedCardNumber);
            // Perform Luhn check on the card numbers
            if (!luhnCheck(cardNumbers)) {
                throw new IllegalArgumentException("Credit card number {" + cardNumber + "} failed the Main check");
            }
            // Return a new CreditCard object if valid
            return new CreditCard(cardNumbers);
        }

        // Method to return the credit card number as a formatted string
        public String number() {
            StringBuilder result = new StringBuilder();
            // Format the card number in groups of four digits
            for (int i = 0; i < DIGITS_COUNT; i++) {
                if (i % 4 == 0 && i != 0) {
                    result.append(" "); // Add space after every four digits
                }
                result.append(digits[i]); // Append the digit to the result
            }
            return result.toString(); // Return the formatted card number
        }

        // Override toString method to provide a string representation of the CreditCard
        @Override
        public String toString() {
            return String.format("CreditCard[number=%s]", number());
        }

        // Helper method to convert a string of digits to an integer array
        private static int[] toIntArray(String string) {
            return string.chars().map(Character::getNumericValue).toArray(); // Convert each character to its numeric value
        }
    }
}
