import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int d = 'a' - 'A';

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

