
import java.util.Scanner;

public class s306917423{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int ans = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
