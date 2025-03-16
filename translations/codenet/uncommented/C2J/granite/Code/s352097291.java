
import java.util.Scanner;
public class s352097291{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String c = sc.nextLine();
        String ans = "";
        for (int i = 0; i < c.length(); i++) {
            if (c.charAt(i)!= 'B') {
                ans += c.charAt(i);
            } else {
                ans = ans.substring(0, ans.length() - 1);
            }
        }
        System.out.println(ans);
    }
}
// 