import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        ArrayList<String[]> s = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] k = scanner.nextLine().split(" ");
            s.add(k);
        }

        HashSet<String> rem = new HashSet<>();
        ArrayList<String> d1 = new ArrayList<>();
        ArrayList<String> d2 = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    d1.add(s.get(i)[j]);
                }
                if (i == n - j - 1) {
                    d2.add(s.get(i)[j]);
                }
                if (i != j && i != n - j - 1) {
                    rem.add(s.get(i)[j]);
                }
            }
        }

        if (rem.size() != 1) {
            System.out.println("NO");
            return;
        }

        if (!d1.equals(d2)) {
            System.out.println("NO");
            return;
        }

        if (new HashSet<>(d1).size() != 1) {
            System.out.println("NO");
            return;
        }

        if (new HashSet<>(d1).equals(rem)) {
            System.out.println("NO");
            return;
        }

        System.out.println("YES");
    }
}
