public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String c = scanner.next(); // Read input string into c
        StringBuilder ans = new StringBuilder(); // Declare StringBuilder ans

        // Process the input string
        for (int i = 0; i < c.length(); i++) {
            char ch = c.charAt(i);
            if (ch != 'B')
                ans.append(ch); // Append character to ans if not 'B'
            else if (ans.length() > 0)
                ans.deleteCharAt(ans.length() - 1); // Remove last character from ans if 'B'
        }

        System.out.println(ans.toString()); // Output the result string ans
    }
}
