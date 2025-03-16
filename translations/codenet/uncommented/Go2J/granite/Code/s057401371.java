
import java.util.Scanner;

public class s057401371{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        int d = 'a' - 'A';
        for (char r : s.toCharArray()) {
            char rr = r;
            if ('A' <= r && r <= 'Z') {
                rr = (char) (r + d);
            } else if ('a' <= r && r <= 'z') {
                rr = (char) (r - d);
            }
            System.out.printf("%c", rr);
        }
        System.out.println();
    }
}
