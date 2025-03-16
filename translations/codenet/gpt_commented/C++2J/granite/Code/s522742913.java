
import java.util.Scanner;

public class s522742913{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String source = scanner.nextLine();

        if (source.length() > 10 || source.length() < 1) {
            System.out.println(-1);
            return;
        }

        int maxI = (int) Math.pow(2, source.length() - 1);
        double sum = 0;

        for (int i = 0; i < maxI; i++) {
            String plus = Integer.toBinaryString(i);
            while (plus.length() < source.length() - 1) {
                plus = "0" + plus;
            }

            double number = 0;
            String working = source;
            for (int j = 0; j < plus.length(); j++) {
                if (plus.charAt(j) == '1') {
                    int k = 0;
                    while (working.charAt(k)!= '+') {
                        k++;
                    }
                    sum += Double.parseDouble(working.substring(0, k + 1));
                    working = working.substring(k + 1);
                }
            }
            sum += Double.parseDouble(working);
        }

        System.out.println((int) sum);
    }
}
