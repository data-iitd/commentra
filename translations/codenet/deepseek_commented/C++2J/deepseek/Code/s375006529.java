public class Main {
    public static void main(String[] args) {
        // Step 1: Reading the Input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.next();

        // Step 2: Calculating the Size of the String
        int n = s.length();

        // Step 3: Initializing an Array to Count Character Frequencies
        int[] v = new int[26];

        // Step 4: Counting Character Frequencies
        for (int i = 0; i < n; i++) {
            v[s.charAt(i) - 'a']++;
        }

        // Step 5: Determining the Result
        String ans = "Yes";
        for (int i = 0; i < 26; i++) {
            if (v[i] % 2 != 0) {
                ans = "No";
                break;
            }
        }

        // Step 6: Outputting the Result
        System.out.println(ans);
    }
}
