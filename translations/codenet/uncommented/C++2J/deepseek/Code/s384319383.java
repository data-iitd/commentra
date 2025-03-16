public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] cnt = new int[26];
        java.util.List<Character> s = new java.util.ArrayList<>();
        scanner.nextLine(); // Consume newline left-over
        String line = scanner.nextLine();
        for (int i = 0; i < n; ++i) {
            s.add(line.charAt(i));
            cnt[line.charAt(i) - 'a']++;
        }

        long ans = cnt[0];
        for (int i = 1; i < 26; ++i) {
            ans *= cnt[i];
            ans %= 1_000_000_007;
        }

        System.out.println(ans - 1);
    }
}
