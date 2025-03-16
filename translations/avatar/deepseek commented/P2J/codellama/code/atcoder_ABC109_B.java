import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] l = new String[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextLine();
        }
        Map<String, Integer> s = new HashMap<>();
        String f = "Yes";
        for (int i = 0; i < n; i++) {
            if (s.containsKey(l[i])) {
                s.put(l[i], s.get(l[i]) + 1);
            } else {
                s.put(l[i], 1);
            }
            if (s.get(l[i]) >= 2) {
                f = "No";
            }
            if (i != 0 && l[i - 1].charAt(l[i - 1].length() - 1) != l[i].charAt(0)) {
                f = "No";
            }
        }
        System.out.println(f);
    }
}

