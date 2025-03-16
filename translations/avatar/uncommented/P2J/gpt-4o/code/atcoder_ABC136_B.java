import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int i = 1;
        long ans = 0;

        while (Math.pow(10, i) <= N) {
            ans += (Math.pow(10, i) - Math.pow(10, i - 1));
            i += 2;
        }
        ans += Math.max(0, N - Math.pow(10, i - 1) + 1);
        System.out.println(ans);
    }
}

// <END-OF-CODE>
