import java.util.Scanner;

public class Main {
    static final int SIZE = 100001;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = scanner.nextInt();
        int l, r;
        int[] mem = new int[SIZE];

        for (int i = 0; i < n; i++) {
            l = scanner.nextInt();
            r = scanner.nextInt();
            mem[l] += 1;
            mem[r] -= 1;
        }

        int ans = mem[0];
        for (int i = 1; i <= t; i++) {
            mem[i] += mem[i - 1];
            if (ans < mem[i]) {
                ans = mem[i];
            }
        }

        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
