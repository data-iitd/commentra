
import java.util.Objects;
import java.util.Scanner;
public final class Damm {
    private Damm() {
    }
    private static final byte[][] DAMM_TABLE = {
        {0, 3, 1, 7, 5, 9, 8, 6, 4, 2},
        {7, 0, 9, 2, 1, 5, 4, 8, 6, 3},
        {4, 2, 0, 6, 8, 7, 1, 3, 5, 9},
        {1, 7, 5, 0, 9, 8, 3, 4, 2, 6},
        {6, 1, 2, 3, 0, 4, 5, 9, 7, 8},
        {3, 6, 7, 4, 2, 0, 9, 5, 8, 1},
        {5, 8, 6, 9, 7, 2, 0, 1, 3, 4},
        {8, 9, 4, 5, 3, 6, 2, 0, 1, 7},
        {9, 4, 3, 8, 6, 1, 7, 2, 0, 5},
        {2, 5, 8, 1, 4, 3, 6, 7, 9, 0},
    };
    public static boolean dammCheck(String digits) {
        checkInput(digits);
        int[] numbers = toIntArray(digits);
        int checksum = 0;
        for (int number : numbers) {
            checksum = DAMM_TABLE[checksum][number];
        }
        return checksum == 0;
    }
    public static String addDammChecksum(String initialDigits) {
        checkInput(initialDigits);
        int[] numbers = toIntArray(initialDigits);
        int checksum = 0;
        for (int number : numbers) {
            checksum = DAMM_TABLE[checksum][number];
        }
        return initialDigits + checksum;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String operation = sc.nextLine();
        if (operation.equalsIgnoreCase("check")) {
            String digits = sc.nextLine();
            try {
                boolean isValid = dammCheck(digits);
                System.out.println("The input '" + digits + "' is " + (isValid ? "valid" : "not valid"));
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        } else if (operation.equalsIgnoreCase("generate")) {
            System.out.println("Enter the input digits to generate checksum:");
            String digits = sc.nextLine();
            try {
                String result = addDammChecksum(digits);
                System.out.println("Generated value with checksum: " + result);
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        } else {
            System.out.println("Invalid operation. Please enter 'check' or 'generate'.");
        }
        sc.close();
    }
    private static void checkInput(String input) {
        Objects.requireNonNull(input);
        if (!input.matches("\\d+")) {
            throw new IllegalArgumentException("Input '" + input + "' contains not only digits");
        }
    }
    private static int[] toIntArray(String string) {
        return string.chars().map(i -> Character.digit(i, 10)).toArray();
    }
}
