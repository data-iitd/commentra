
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class codeforces_400_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            int sIndex = s.indexOf("S");
            int gIndex = s.indexOf("G");
            set.add(sIndex - gIndex);
        }
        if (set.contains(-1)) {
            System.out.println(-1);
        } else {
            System.out.println(set.size());
        }
    }
}
