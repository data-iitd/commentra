
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<List<String>> s = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            s.add(Arrays.asList(sc.next().split(" ")));
        }
        boolean flag = false;
        List<String> d1 = new ArrayList<>();
        List<String> d2 = new ArrayList<>();
        Set<String> rem = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    d1.add(s.get(i).get(j));
                }
                if (i == n - j - 1) {
                    d2.add(s.get(i).get(j));
                }
                if (i!= j && i!= n - j - 1) {
                    rem.add(s.get(i).get(j));
                }
            }
        }
        if (rem.size()!= 1) {
            System.out.println("NO");
            return;
        }
        if (!d1.equals(d2)) {
            System.out.println("NO");
            return;
        }
        if (d1.size()!= 1) {
            System.out.println("NO");
            return;
        }
        if (d1.get(0) == null) {
            System.out.println("NO");
            return;
        }
        if (rem.contains(d1.get(0))) {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
    }
}

