import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.close();

        System.out.println(aaa(0));
    }

    public static int aaa(int n) {
        if (n > N) {
            return 0;
        }

        int ans = n == 7 || n == 5 || n == 3 ? 1 : 0;

        if (n == 0) {
            ans += aaa(7);
            ans += aaa(5);
            ans += aaa(3);
        } else {
            ans += aaa(n * 10 + 7);
            ans += aaa(n * 10 + 5);
            ans += aaa(n * 10 + 3);
        }

        return ans;
    }
}
