import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int ans = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                ans++;
            }
        }
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
