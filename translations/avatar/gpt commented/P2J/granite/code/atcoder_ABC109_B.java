
import java.util.Scanner;
import java.util.HashMap;

public class atcoder_ABC109_B{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HashMap<String, Integer> map = new HashMap<>();
        String[] l = new String[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.next();
            map.put(l[i], map.getOrDefault(l[i], 0) + 1);
        }
        String f = "Yes";
        for (int i = 0; i < n; i++) {
            if (map.get(l[i]) > 1) {
                f = "No";
                break;
            }
            if (i > 0 && l[i - 1].charAt(l[i - 1].length() - 1)!= l[i].charAt(0)) {
                f = "No";
                break;
            }
        }
        System.out.println(f);
    }
}
