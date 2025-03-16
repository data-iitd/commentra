import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("\\n");
        String s = sc.next();

        char d = 'a' - 'A';
        for (char r : s.toCharArray()) {
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
