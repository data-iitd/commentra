import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading the input values for n and k, and the string s
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        String s = scanner.next();
        
        // Initializing L with the first character of s, and ans, cnt to zero
        char L = s.charAt(0);
        long ans = 0;
        long cnt = 0;
        long ans2 = 0;
        
        // Loop through the string starting from the second character
        for (int i = 1; i < n; i++) {
            // If the current character is the same as L, increment cnt
            if (L == s.charAt(i)) {
                cnt++;
            } else {
                // Update L to the new character, add cnt to ans, increment ans2, and reset cnt
                L = s.charAt(i);
                ans += cnt;
                ans2++;
                cnt = 0;
            }
        }
        
        // Add the final count to ans and increment ans2
        ans += cnt;
        ans2++;
        
        // Calculate the output as ans + min(2*k, ans2-1) and print it
        System.out.println(ans + Math.min(2 * k, ans2 - 1));
        
        scanner.close();
    }
}

// <END-OF-CODE>
