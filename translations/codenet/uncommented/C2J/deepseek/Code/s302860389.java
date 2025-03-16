public class Main {
    public static void main(String[] args) {
        String inputNumbers = "1234"; // Example input
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
                        System.out.println(a + "" + symbols[0] + b + "" + symbols[1] + c + "" + symbols[2] + d + "=7");
                        return;
                    }
                }
            }
        }
    }
}
