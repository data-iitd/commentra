import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String source = scanner.nextLine();

        if (source.length() > 10 || source.length() < 1) {
            return;
        }

        int max_i = (int) Math.pow(2, source.length() - 1);
        double sum = 0;

        for (int i = 0; i < max_i; ++i) {
            StringBuilder plus = new StringBuilder(Integer.toBinaryString(i));
            while (plus.length() < source.length() - 1) {
                plus.insert(0, '0');
            }

            double number = 0;
            String working = source;
            int index = 0;

            while (index < plus.length() && plus.charAt(index) == '0') {
                index++;
            }

            while (index < plus.length()) {
                int j = index;
                while (j < plus.length() && plus.charAt(j) == '0') {
                    j++;
                }
                if (j < plus.length()) {
                    sum += Double.parseDouble(working.substring(0, j + 1));
                    plus.delete(0, j + 1);
                    working = working.substring(j + 1);
                    index = 0; // Reset index for the next iteration
                } else {
                    break;
                }
            }
            sum += Double.parseDouble(working);
        }

        System.out.printf("%.0f%n", sum);
    }
}
// <END-OF-CODE>
