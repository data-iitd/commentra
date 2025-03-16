public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        String a = scanner.next();
        String b = scanner.next();
        String c = scanner.next();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (a.charAt(i) == b.charAt(i) && b.charAt(i) == c.charAt(i)) {
            } else if (a.charAt(i) == b.charAt(i) || b.charAt(i) == c.charAt(i) || a.charAt(i) == c.charAt(i)) {
                ans++;
            } else {
                ans += 2;
            }
        }
        System.out.println(ans);
    }
}
