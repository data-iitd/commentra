
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.Set;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < N; i++) {
            int num = sc.nextInt();
            m.put(num, m.getOrDefault(num, 0) + 1);
        }
        int M = sc.nextInt();
        for (int i = 0; i < M; i++) {
            int B = sc.nextInt();
            int C = sc.nextInt();
            m.put(C, m.getOrDefault(C, 0) + B);
        }
        ArrayList<Integer> ints = new ArrayList<>();
        for (int k : m.keySet()) {
            ints.add(k);
        }
        Collections.sort(ints, Collections.reverseOrder());
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

