import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        Set<Integer> c = new HashSet<>();

        for (int i = 0; i < n; i++) {
            String row = scanner.nextLine();
            int indexS = row.indexOf('S');
            int indexG = row.indexOf('G');
            if (indexS != -1 && indexG != -1) {
                c.add(indexS - indexG);
            }
        }

        boolean hasNegative = false;
        for (int diff : c) {
            if (diff < 0) {
                hasNegative = true;
                break;
            }
        }

        System.out.println(hasNegative ? -1 : c.size());
    }
}
