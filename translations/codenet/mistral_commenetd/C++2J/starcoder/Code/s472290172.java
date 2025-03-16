
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();

        int max = 0, cnt = 0;

        for (char sc : str.toCharArray()) {
            if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
                cnt++;
            } else {
                cnt = 0;
            }

            max = max < cnt? cnt : max;
        }

        System.out.println(max);
    }
}

