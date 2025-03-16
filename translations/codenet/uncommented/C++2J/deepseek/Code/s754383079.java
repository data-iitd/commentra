public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String a = scanner.next();
        String b = scanner.next();
        int n = a.length();
        int m = b.length();
        int ans = n + 10;

        for (int i = 0; i + m - 1 < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                if (a.charAt(i + j) != b.charAt(j)) {
                    sum++;
                }
            }
            ans = Math.min(ans, sum);
        }
        System.out.println(ans);
    }
}
