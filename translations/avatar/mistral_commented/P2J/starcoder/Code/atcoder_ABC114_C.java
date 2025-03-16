
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        System.out.println(aaa(N));
    }

    public static int aaa(int n) {
        if (n > N) {
            return 0;
        }
        int ans = 1;
        if (new HashSet<String>(Arrays.asList(Integer.toString(n).split(""))).equals(new HashSet<String>(Arrays.asList("7", "5", "3")))) {
            ans = 1;
        } else {
            ans = 0;
        }
        for (char c : "753".toCharArray()) {
            ans += aaa(n + c - '0');
        }
        return ans;
    }
}

