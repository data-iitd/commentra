import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String W = scanner.next();
        scanner.close();
        
        char[] charArray = W.toCharArray();
        Arrays.sort(charArray);
        W = new String(charArray);
        
        for (int i = 0; i < W.length(); i += 2) {
            if (i + 1 >= W.length() || W.charAt(i) != W.charAt(i + 1)) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
