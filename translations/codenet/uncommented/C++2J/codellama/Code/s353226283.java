import java.util.Scanner;
import java.util.Vector;
import java.util.Collections;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        Vector<Integer> vec = new Vector<Integer>();
        for (int i = 0; i < n; i++) {
            vec.add(sc.nextInt());
        }
        Collections.sort(vec, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return a - b;
            }
        });
        int ans = 1000000001;
        for (int i = 0; i + k - 1 < n; i++) {
            int diff = vec.get(i + k - 1) - vec.get(i);
            if (diff < ans) {
                ans = diff;
            }
        }
        System.out.println(ans);
    }
}

