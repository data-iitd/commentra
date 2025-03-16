import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        Set<Integer> c = new HashSet<>();

        scanner.nextLine(); // Consume newline
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            int indexS = s.indexOf('S');
            int indexG = s.indexOf('G');

            if (indexS != -1 && indexG != -1) {
                int difference = indexS - indexG;
                c.add(difference);
            }
        }

        boolean hasNegative = false;
        for (int a : c) {
            if (a < 0) {
                hasNegative = true;
                break;
            }
        }

        if (hasNegative) {
            System.out.println(-1);
        } else {
            System.out.println(c.size());
        }
    }
}
