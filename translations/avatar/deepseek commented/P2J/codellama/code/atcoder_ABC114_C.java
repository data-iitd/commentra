
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        System.out.println(aaa("0"));
    }

    public static int aaa(String n) {
        if (Integer.parseInt(n) > N) {
            return 0;
        }
        int ans = 1;
        if (n.contains("7") && n.contains("5") && n.contains("3")) {
            ans = 1;
        } else {
            ans = 0;
        }
        for (int i = 0; i < 3; i++) {
            ans += aaa(n + "753".charAt(i));
        }
        return ans;
    }
}

