import java.util.Scanner;
import java.util.HashMap;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        HashMap<String, Integer> s = new HashMap<String, Integer>();
        String[] l = new String[n];
        for (int i = 0; i < n; i++) {
            l[i] = in.next();
            if (s.containsKey(l[i])) {
                s.put(l[i], s.get(l[i]) + 1);
            } else {
                s.put(l[i], 1);
            }
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

