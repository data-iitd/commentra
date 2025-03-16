import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int s = scanner.nextInt();
        int d = 2;
        HashSet<Integer> a = new HashSet<>();
        a.add(s);

        while (true) {
            int x;
            if (s % 2 == 0) {
                x = s / 2;
                if (a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            } else {
                x = 3 * s + 1;
                if (a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            }
            s = x;
            d++;
        }
    }
}
// <END-OF-CODE>
