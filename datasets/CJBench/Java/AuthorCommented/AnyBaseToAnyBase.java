
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

/**
 * Class for converting from "any" base to "any" other base, when "any" means
 * from 2-36. Works by going from base 1 to decimal to base 2. Includes
 * auxiliary method for determining whether a number is valid for a given base.
 *
 * @author Michael Rolland
 * @version 2017.10.10
 */
public final class AnyBaseToAnyBase {
    private AnyBaseToAnyBase() {}

    /**
     * Smallest and largest base you want to accept as valid input
     */
    static final int MINIMUM_BASE = 2;
    static final int MAXIMUM_BASE = 36;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String n = in.next();

        int b1 = in.nextInt();
        while (b1 < MINIMUM_BASE || b1 > MAXIMUM_BASE) {
            System.out.println("Invalid base! Please enter again.");
            b1 = in.nextInt();
        }

        if (!validForBase(n, b1)) {
            System.out.println("The number is invalid for this base!");
            return;
        }

        int b2 = in.nextInt();
        while (b2 < MINIMUM_BASE || b2 > MAXIMUM_BASE) {
            System.out.println("Invalid base! Please enter again.");
            b2 = in.nextInt();
        }

        String result = base2base(n, b1, b2);
        System.out.println("Converted number: " + result);
        in.close();
    }

    /**
     * Checks if a number (as a String) is valid for a given base.
     */
    public static boolean validForBase(String n, int base) {
        char[] validDigits = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        };
        char[] digitsForBase = Arrays.copyOfRange(validDigits, 0, base);

        HashSet<Character> digitsList = new HashSet<>();
        for (char c : digitsForBase) {
            digitsList.add(c);
        }

        for (char c : n.toUpperCase().toCharArray()) {
            if (!digitsList.contains(c)) {
                return false;
            }
        }

        return true;
    }

    /**
     * Method to convert any integer from base b1 to base b2. Works by
     * converting from b1 to decimal, then decimal to b2.
     *
     * @param n The integer to be converted.
     * @param b1 Beginning base.
     * @param b2 End base.
     * @return n in base b2.
     */
    public static String base2base(String n, int b1, int b2) {
        int decimalValue = 0;
        StringBuilder output = new StringBuilder();

        for (char charB1 : n.toUpperCase().toCharArray()) {
            int charB2 = (charB1 >= 'A' && charB1 <= 'Z') ? 10 + (charB1 - 'A') : charB1 - '0';
            decimalValue = decimalValue * b1 + charB2;
        }

        if (decimalValue == 0) {
            return "0";
        }

        while (decimalValue != 0) {
            int remainder = decimalValue % b2;
            output.insert(0, (char) (remainder < 10 ? '0' + remainder : 'A' + (remainder - 10)));
            decimalValue /= b2;
        }

        return output.toString();
    }
}
