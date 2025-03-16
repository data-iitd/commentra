import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        ArrayList<String> s = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String k = scanner.nextLine();
            s.add(k);
        }
        int flag = 0;
        ArrayList<Character> d1 = new ArrayList<>();
        ArrayList<Character> d2 = new ArrayList<>();
        Set<Character> rem = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    d1.add(s.get(i).charAt(j));
                }
                if (i == n - j - 1) {
                    d2.add(s.get(i).charAt(j));
                }
                if (i != j && i != n - j - 1) {
                    rem.add(s.get(i).charAt(j));
                }
            }
        }
        if (rem.size() != 1) {
            System.out.println("NO");
        } else if (!d1.equals(d2)) {
            System.out.println("NO");
        } else if (d1.stream().distinct().count() != 1) {
            System.out.println("NO");
        } else if (d1.get(0).equals(rem.iterator().next())) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
    }
}
