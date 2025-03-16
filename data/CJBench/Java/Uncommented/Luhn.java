
import java.util.*;
public final class Luhn {
    private Luhn() {
    }
    public static boolean luhnCheck(int[] digits) {
        int[] numbers = Arrays.copyOf(digits, digits.length);
        int sum = 0;
        for (int i = numbers.length - 1; i >= 0; i--) {
            if ((numbers.length - i) % 2 == 0) { 
                int temp = numbers[i] * 2;
                if (temp > 9) {
                    temp = temp - 9;
                }
                numbers[i] = temp;
            }
            sum += numbers[i];
        }
        return sum % 10 == 0;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] inputDigits = new int[n];
        for (int i = 0; i < n; i++) {
            inputDigits[i] = sc.nextInt();
        }
        boolean isValid = luhnCheck(inputDigits);
        System.out.println("The input is " + (isValid ? "valid" : "not valid") + " according to the Luhn algorithm.");
        sc.nextLine(); 
        String cardNumber = sc.nextLine();
        try {
            CreditCard creditCard = CreditCard.fromString(cardNumber);
            System.out.println("Credit card is valid: " + creditCard);
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
        sc.close();
    }
    private static class CreditCard {
        private static final int DIGITS_COUNT = 16;
        private final int[] digits;
        public CreditCard(int[] digits) {
            this.digits = digits;
        }
        public static CreditCard fromString(String cardNumber) {
            Objects.requireNonNull(cardNumber);
            String trimmedCardNumber = cardNumber.replaceAll(" ", "");
            if (trimmedCardNumber.length() != DIGITS_COUNT || !trimmedCardNumber.matches("\\d+")) {
                throw new IllegalArgumentException("{" + cardNumber + "} - is not a valid card number");
            }
            int[] cardNumbers = toIntArray(trimmedCardNumber);
            if (!luhnCheck(cardNumbers)) {
                throw new IllegalArgumentException("Credit card number {" + cardNumber + "} failed the Luhn check");
            }
            return new CreditCard(cardNumbers);
        }
        public String number() {
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < DIGITS_COUNT; i++) {
                if (i % 4 == 0 && i != 0) {
                    result.append(" ");
                }
                result.append(digits[i]);
            }
            return result.toString();
        }
        @Override
        public String toString() {
            return String.format("CreditCard[number=%s]", number());
        }
        private static int[] toIntArray(String string) {
            return string.chars().map(Character::getNumericValue).toArray();
        }
    }
}
