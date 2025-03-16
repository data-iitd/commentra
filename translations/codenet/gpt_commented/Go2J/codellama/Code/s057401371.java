
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int d = 'a' - 'A';
        for (int i = 0; i < s.length(); i++) {
            char r = s.charAt(i);
            char rr = r;
            if ('A' <= r && r <= 'Z') {
                rr = (char) (r + d);
            } else if ('a' <= r && r <= 'z') {
                rr = (char) (r - d);
            }
            System.out.print(rr);
        }
        System.out.println();
    }
}

