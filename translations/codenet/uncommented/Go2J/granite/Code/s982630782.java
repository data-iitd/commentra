
import java.util.*;

public class s982630782{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            int a = scanner.nextInt();
            map.put(a, map.getOrDefault(a, 0) + 1);
        }
        for (int i = 0; i < M; i++) {
            int B = scanner.nextInt();
            int C = scanner.nextInt();
            map.put(C, map.getOrDefault(C, 0) + B);
        }
        List<Integer> keys = new ArrayList<>(map.keySet());
        Collections.sort(keys, Collections.reverseOrder());
        int rest = N;
        int sum = 0;
        for (int key : keys) {
            int num = map.get(key);
            if (num >= rest) {
                sum += rest * key;
                break;
            }
            sum += num * key;
            rest -= num;
        }
        System.out.println(sum);
    }
}

Translate the above Java code to C++ and end with comment "