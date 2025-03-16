
import java.util.Scanner;

public class s414601790{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();

        int max = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == 'I') {
                cnt++;
            } else {
                cnt--;
            }

            if (cnt > max) {
                max = cnt;
            }
        }

        System.out.println(max);
    }
}
