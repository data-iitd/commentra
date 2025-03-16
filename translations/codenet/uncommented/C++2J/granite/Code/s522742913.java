
import java.util.Scanner;

public class s522742913{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String source = scanner.nextLine();

        if (source.length() > 10 || source.length() < 1) {
            return;
        }

        int maxI = (int) Math.pow(2, source.length() - 1);

        double sum = 0;

        for (int i = 0; i < maxI; ++i) {
            StringBuilder plus = new StringBuilder(Integer.toBinaryString(i));
            while (plus.length() < source.length() - 1) {
                plus.insert(0, '0');
            }

            double number = 0;

            String working = source;
            while (plus.length() > 0) {
                int index = 0;
                while (plus.charAt(index)!= '1') {
                    index++;
                }
                sum += Double.parseDouble(working.substring(0, index + 1));
                plus.delete(0, index + 1);
                working = working.substring(index + 1);
            }
            sum += Double.parseDouble(working);
        }

        System.out.printf("%.0f", sum);

        // 