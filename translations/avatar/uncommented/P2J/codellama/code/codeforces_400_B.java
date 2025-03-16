
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Set<Integer> c = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            int indexOfS = s.indexOf("S");
            int indexOfG = s.indexOf("G");
            c.add(indexOfS - indexOfG);
        }
        if (c.contains(-1)) {
            System.out.println(-1);
        } else {
            System.out.println(c.size());
        }
    }
}

