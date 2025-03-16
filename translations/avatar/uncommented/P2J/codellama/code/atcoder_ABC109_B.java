import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, Integer> s = new HashMap<>();
        String[] l = new String[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.next();
            s.put(l[i], s.getOrDefault(l[i], 0) + 1);
        }
        String f = "Yes";
        for (int i = 0; i < n - 1; i++) {
            if (s.get(l[i]) >= 2) {
                f = "No";
                break;
            }
            if (l[i].charAt(l[i].length() - 1) != l[i + 1].charAt(0)) {
                f = "No";
                break;
            }
        }
        System.out.println(f);
    }
}

