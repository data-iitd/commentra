
import java.util.Objects;
import java.util.Scanner;
public final class Verhoeff {
    private Verhoeff() {}
    private static final byte[][] MULTIPLICATION_TABLE = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 0, 6, 7, 8, 9, 5},
        {2, 3, 4, 0, 1, 7, 8, 9, 5, 6},
        {3, 4, 0, 1, 2, 8, 9, 5, 6, 7},
        {4, 0, 1, 2, 3, 9, 5, 6, 7, 8},
        {5, 9, 8, 7, 6, 0, 4, 3, 2, 1},
        {6, 5, 9, 8, 7, 1, 0, 4, 3, 2},
        {7, 6, 5, 9, 8, 2, 1, 0, 4, 3},
        {8, 7, 6, 5, 9, 3, 2, 1, 0, 4},
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
    };
    private static final byte[] MULTIPLICATIVE_INVERSE = {
        0, 4, 3, 2, 1, 5, 6, 7, 8, 9
    };
    private static final byte[][] PERMUTATION_TABLE = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 5, 7, 6, 2, 8, 3, 0, 9, 4},
        {5, 8, 0, 3, 7, 9, 6, 1, 4, 2},
        {8, 9, 1, 6, 0, 4, 3, 5, 2, 7},
        {9, 4, 5, 3, 1, 2, 6, 8, 7, 0},
        {4, 2, 8, 6, 5, 7, 3, 9, 0, 1},
        {2, 7, 9, 3, 8, 0, 6, 4, 1, 5},
        {7, 0, 4, 6, 9, 1, 3, 2, 5, 8}
    };
    public static boolean verhoeffCheck(String digits) {
        checkInput(digits);
        int[] numbers = toIntArray(digits);
        int checksum = 0;
        for (int i = 0; i < numbers.length; i++) {
            int index = numbers.length - i - 1;
            byte b = PERMUTATION_TABLE[i % 8][numbers[index]];
            checksum = MULTIPLICATION_TABLE[checksum][b];
        }
        return checksum == 0;
    }
    public static String addVerhoeffChecksum(String initialDigits) {
        checkInput(initialDigits);
        String modifiedDigits = initialDigits + "0";
        int[] numbers = toIntArray(modifiedDigits);
        int checksum = 0;
        for (int i = 0; i < numbers.length; i++) {
            int index = numbers.length - i - 1;
            byte b = PERMUTATION_TABLE[i % 8][numbers[index]];
            checksum = MULTIPLICATION_TABLE[checksum][b];
        }
        checksum = MULTIPLICATIVE_INVERSE[checksum];
        return initialDigits + checksum;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number to validate: ");
        String inputToValidate = scanner.nextLine();
        System.out.println("Input is " + (verhoeffCheck(inputToValidate) ? "valid" : "not valid"));
        System.out.print("Enter a number to generate a checksum: ");
        String inputToGenerateChecksum = scanner.nextLine();
        System.out.println("Number with checksum: " + addVerhoeffChecksum(inputToGenerateChecksum));
        scanner.close();
    }
    private static void checkInput(String input) {
        Objects.requireNonNull(input);
        if (!input.matches("\\d+")) {
            throw new IllegalArgumentException("Input contains invalid characters: " + input);
        }
    }
    private static int[] toIntArray(String string) {
        return string.chars().map(Character::getNumericValue).toArray();
    }
}
