public class Main {
    public static void main(String[] args) {
        int n, t;
        int l, r;
        int[] mem = new int[100001];
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        t = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            l = scanner.nextInt();
            r = scanner.nextInt();
            mem[l] += 1;
            mem[r] -= 1;
        }
        int ans = mem[0];
        for (int i = 1; i < t + 1; i++) {
            mem[i] += mem[i - 1];
            if (ans < mem[i]) {
                ans = mem[i];
            }
        }
        System.out.println(ans);
    }
}
