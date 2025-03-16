
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<String> l = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            char[] arr = s.toCharArray();
            for (int j = 0; j < m; j++) {
                if (arr[j] == '.') {
                    if ((i + j) % 2 == 1) {
                        arr[j] = 'W';
                    } else {
                        arr[j] = 'B';
                    }
                }
            }
            l.add(new String(arr));
        }
        for (String s : l) {
            System.out.println(s);
        }
    }
}
