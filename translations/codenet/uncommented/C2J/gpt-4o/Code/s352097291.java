import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String c = scanner.next();
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < c.length(); i++) {
            char currentChar = c.charAt(i);
            if (currentChar != 'B') {
                ans.append(currentChar);
            } else if (ans.length() > 0) {
                ans.deleteCharAt(ans.length() - 1);
            }
        }
        
        System.out.println(ans.toString());
        scanner.close();
    }
}
// <END-OF-CODE>
