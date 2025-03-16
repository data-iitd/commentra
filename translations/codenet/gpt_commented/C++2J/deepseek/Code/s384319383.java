public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize an array to count occurrences of each character (a-z)
        int[] cnt = new int[26];
        java.util.List<Character> s = new java.util.ArrayList<>();

        // Read characters and count their occurrences
        for (int i = 0; i < n; ++i) {
            char c = scanner.next().charAt(0);
            s.add(c);
            cnt[c - 'a']++;
        }

        long ans = cnt[0];

        // Calculate the product of counts for all characters from 'b' to 'z'
        for (int i = 1; i < 26; ++i) {
            ans *= cnt[i];
            ans %= 1000000007;
        }

        // Output the final result, subtracting 1 to exclude the empty product case
        System.out.println(ans - 1);
    }
}
