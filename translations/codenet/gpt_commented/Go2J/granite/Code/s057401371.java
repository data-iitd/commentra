
import java.util.Scanner;

public class s057401371{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int d = 'a' - 'A';
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if ('A' <= c && c <= 'Z') {
                c = (char) (c + d);
            } else if ('a' <= c && c <= 'z') {
                c = (char) (c - d);
            }
            sb.append(c);
        }
        System.out.println(sb.toString());
    }
}
