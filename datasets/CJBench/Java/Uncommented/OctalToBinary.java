import java.util.Scanner;
public final class OctalToBinary {
    private OctalToBinary() {
    }
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
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int octalNumber = scanner.nextInt();
        long binaryNumber = convertOctalToBinary(octalNumber);
        System.out.println("Binary equivalent: " + binaryNumber);
        scanner.close();
    }
}
