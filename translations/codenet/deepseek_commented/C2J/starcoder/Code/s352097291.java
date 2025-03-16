import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String c = sc.next();
        String ans = "";

        // Process the input string
        for (int i = 0; i < c.length(); i++) {
            if (c.charAt(i)!= 'B')
                ans += c.charAt(i); // Append character to ans if not 'B'
            else
                ans = ans.substring(0, ans.length() - 1); // Remove last character from ans if 'B'
        }

        System.out.println(ans); // Output the result string ans
    }
}
