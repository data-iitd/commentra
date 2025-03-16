import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputNumbers = scanner.nextLine();
        
        int a, b, c, d;
        int sum;
        char[] symbols = new char[3];

        a = Character.getNumericValue(inputNumbers.charAt(0));
        b = Character.getNumericValue(inputNumbers.charAt(1));
        c = Character.getNumericValue(inputNumbers.charAt(2));
        d = Character.getNumericValue(inputNumbers.charAt(3));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (i == 0) {
                        sum = a + b;
                        symbols[0] = '+';
                    } else {
                        sum = a - b;
                        symbols[0] = '-';
                    }

                    if (j == 0) {
                        sum += c;
                        symbols[1] = '+';
                    } else {
                        sum -= c;
                        symbols[1] = '-';
                    }

                    if (k == 0) {
                        sum += d;
                        symbols[2] = '+';
                    } else {
                        sum -= d;
                        symbols[2] = '-';
                    }

                    if (sum == 7) {
                        System.out.printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d);
                        return;
                    }
                }
            }
        }

        scanner.close();
    }
}
// <END-OF-CODE>
