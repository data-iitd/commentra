import java.util.Scanner;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        int max = 0, cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            char sc = str.charAt(i);
            if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
                cnt++;
            } else {
                cnt = 0;
            }
            max = max < cnt ? cnt : max;
        }

        System.out.println(max);
    }
}
