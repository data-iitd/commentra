import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int N = Integer.parseInt(tokenizer.nextToken());
        Map<Integer, Integer> map = new HashMap<>();
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(tokenizer.nextToken());
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        tokenizer = new StringTokenizer(reader.readLine());
        int M = Integer.parseInt(tokenizer.nextToken());
        for (int i = 0; i < M; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int B = Integer.parseInt(tokenizer.nextToken());
            int C = Integer.parseInt(tokenizer.nextToken());
            map.put(C, map.getOrDefault(C, 0) + B);
        }
        List<Integer> list = new ArrayList<>(map.keySet());
        Collections.sort(list, (a, b) -> b - a);
        int rest = N;
        long sum = 0;
        for (int key : list) {
            int freq = map.get(key);
            if (freq >= rest) {
                sum += rest * key;
                break;
            }
            sum += freq * key;
            rest -= freq;
        }
        System.out.println(sum);
    }
}

