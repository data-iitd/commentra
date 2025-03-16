// <START-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String source = sc.next();

        if (source.length() > 10 || source.length() < 1) {
            System.out.println(-1);
            return;
        }

        int max_i = (int) Math.pow(2, source.length() - 1);

        double sum = 0;

        for (int i = 0; i < max_i; ++i) {
            String binary = Integer.toBinaryString(i);
            String working = source;

            for (int j = 0; j < binary.length(); ++j) {
                if (binary.charAt(j) == '1') {
                    sum += Double.parseDouble(working.substring(0, j + 1));
                    working = working.substring(j + 1);
                }
            }

            sum += Double.parseDouble(working);
        }

        System.out.println(sum);
    }
}

// 