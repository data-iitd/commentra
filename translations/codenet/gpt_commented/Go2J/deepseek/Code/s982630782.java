import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        
        int N = Integer.parseInt(tokenizer.nextToken());
        int M = Integer.parseInt(tokenizer.nextToken());
        
        Map<Integer, Integer> map = new HashMap<>();
        
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(tokenizer.nextToken());
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        for (int i = 0; i < M; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int B = Integer.parseInt(tokenizer.nextToken());
            int C = Integer.parseInt(tokenizer.nextToken());
            map.put(C, map.getOrDefault(C, 0) + B);
        }
        
        List<Integer> keys = new ArrayList<>(map.keySet());
        keys.sort((a, b) -> b - a);
        
        int rest = N;
        long sum = 0;
        
        for (int key : keys) {
            int count = map.get(key);
            if (count >= rest) {
                sum += (long) rest * key;
                break;
            }
            sum += (long) count * key;
            rest -= count;
        }
        
        System.out.println(sum);
    }
}
