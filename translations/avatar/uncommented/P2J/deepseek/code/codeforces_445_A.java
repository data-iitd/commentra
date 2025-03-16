import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Chessboard {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<char[]> l = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            char[] chars = s.toCharArray();
            for (int j = 0; j < m; j++) {
                if (chars[j] == '.') {
                    if ((i + j) % 2 == 0) {
                        chars[j] = 'B';
                    } else {
                        chars[j] = 'W';
                    }
                }
            }
            l.add(chars);
        }
        
        for (char[] c : l) {
            System.out.println(new String(c));
        }
    }
}
