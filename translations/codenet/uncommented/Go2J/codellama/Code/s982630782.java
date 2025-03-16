
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.Set;
import java.util.TreeSet;
import java.util.Iterator;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        Map<Integer, Integer> m = new HashMap<Integer, Integer>();
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            m.put(x, m.getOrDefault(x, 0) + 1);
        }
        for (int i = 0; i < M; i++) {
            int B = sc.nextInt();
            int C = sc.nextInt();
            m.put(C, m.getOrDefault(C, 0) + B);
        }
        Set<Integer> ints = new TreeSet<Integer>(m.keySet());
        int rest = N;
        int sum = 0;
        for (int i : ints) {
            int num = m.get(i);
            if (num >= rest) {
                sum += rest * i;
                break;
            }
            sum += num * i;
            rest -= num;
        }
        System.out.println(sum);
    }
}

