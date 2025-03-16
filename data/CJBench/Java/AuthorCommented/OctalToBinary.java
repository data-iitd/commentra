import java.util.Scanner;

/**
 * A utility class to convert an octal (base-8) number into its binary (base-2) representation.
 *
 * <p>This class provides methods to:
 * <ul>
 *     <li>Convert an octal number to its binary equivalent</li>
 *     <li>Convert individual octal digits to binary</li>
 * </ul>
 *
 * @author Bama Charan Chhandogi
 */
public final class OctalToBinary {

    private OctalToBinary() {
    }

    /**
     * Converts an octal number to its binary representation.
     *
     * @param octalNumber the octal number to convert (non-negative integer)
     * @return the binary equivalent as a long
     */
    public static long convertOctalToBinary(int octalNumber) {
        long binaryNumber = 0;
        int digitPosition = 1;

        while (octalNumber != 0) {
            int octalDigit = octalNumber % 10;
            long binaryDigit = convertOctalDigitToBinary(octalDigit);

            binaryNumber += binaryDigit * digitPosition;

            octalNumber /= 10;
            digitPosition *= 1000;
        }

        return binaryNumber;
    }

    /**
     * Converts a single octal digit (0-7) to its binary equivalent.
     *
     * @param octalDigit a single octal digit (0-7)
     * @return the binary equivalent as a long
     */
    public static long convertOctalDigitToBinary(int octalDigit) {
        long binaryDigit = 0;
        int binaryMultiplier = 1;

        while (octalDigit != 0) {
            int octalDigitRemainder = octalDigit % 2;
            binaryDigit += octalDigitRemainder * binaryMultiplier;

            octalDigit /= 2;
            binaryMultiplier *= 10;
        }

        return binaryDigit;
    }

    /**
     * Main method to take user input and perform octal-to-binary conversion.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int octalNumber = scanner.nextInt();

        long binaryNumber = convertOctalToBinary(octalNumber);

        System.out.println("Binary equivalent: " + binaryNumber);

        scanner.close();
    }
}
