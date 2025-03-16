
import java.util.Scanner;

public class s522742913{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String source = scanner.nextLine();

        if(source.length() > 10 || source.length() < 1)
        {
            System.out.println(-1);
            return;
        }

        int max_i = (int)Math.pow(2, source.length() - 1);

        double sum = 0;

        for (int i = 0; i < max_i; ++i)
        {
            String plus = Integer.toBinaryString(i);

            double number = 0;

            String working = source;
            while(!plus.isEmpty())
            {
                int i_ = 0;
                while(plus.charAt(i_)!= '1') ++i_;
                sum += Double.parseDouble(working.substring(0, i_ + 1));
                plus = plus.substring(i_ + 1);
                working = working.substring(i_ + 1);
            }
            sum += Double.parseDouble(working);
        }

        System.out.println((int)sum);
    }
}
