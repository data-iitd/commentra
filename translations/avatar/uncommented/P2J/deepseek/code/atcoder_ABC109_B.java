import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        HashMap<String, Integer> s = new HashMap<>();
        String[] l = new String[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.next();
        }
        String f = "Yes";
        for (int i = 0; i < n; i++) {
            s.put(l[i], s.getOrDefault(l[i], 0) + 1);
            if (s.get(l[i]) >= 2) {
                f = "No";
            }
            if (i > 0 && l[i - 1].charAt(l[i - 1].length() - 1) != l[i].charAt(0)) {
                f = "No";
            }
        }
        System.out.println(f);
    }
}
