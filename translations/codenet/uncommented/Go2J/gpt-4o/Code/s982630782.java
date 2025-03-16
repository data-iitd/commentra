import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<Integer, Integer> m = new HashMap<>();
        
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        for (int i = 0; i < N; i++) {
            int num = scanner.nextInt();
            m.put(num, m.getOrDefault(num, 0) + 1);
        }
        
        for (int i = 0; i < M; i++) {
            int B = scanner.nextInt();
            int C = scanner.nextInt();
            m.put(C, m.getOrDefault(C, 0) + B);
        }
        
        List<Integer> ints = new ArrayList<>(m.keySet());
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
