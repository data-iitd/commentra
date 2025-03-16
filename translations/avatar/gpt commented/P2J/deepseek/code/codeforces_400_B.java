import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        Set<Integer> differences = new HashSet<>();

        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            int indexS = s.indexOf('S');
            int indexG = s.indexOf('G');
            if (indexS < indexG) {
                differences.add(indexS - indexG);
            } else {
                System.out.println(-1);
                return;
            }
        }

        System.out.println(differences.size());
    }
}
