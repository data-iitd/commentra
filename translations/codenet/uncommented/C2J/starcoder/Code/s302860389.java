
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String inputNumbers = sc.next();
        char temp[] = new char[2];
        int a, b, c, d;
        int sum;
        char symbols[] = new char[3];

        temp[1] = '\0';

        temp[0] = inputNumbers.charAt(0);
        a = Integer.parseInt(temp);
        temp[0] = inputNumbers.charAt(1);
        b = Integer.parseInt(temp);
        temp[0] = inputNumbers.charAt(2);
        c = Integer.parseInt(temp);
        temp[0] = inputNumbers.charAt(3);
        d = Integer.parseInt(temp);

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
                        sum = sum + c;
                        symbols[1] = '+';
                    } else {
                        sum = sum - c;
                        symbols[1] = '-';
                    }

                    if (k == 0) {
                        sum = sum + d;
                        symbols[2] = '+';
                    } else {
                        sum = sum - d;
                        symbols[2] = '-';
                    }

                    if (sum == 7) {
                        System.out.printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d);

                        return;
                    }
                }
            }
        }
    }
}

