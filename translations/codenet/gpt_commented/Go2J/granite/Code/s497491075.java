
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class s497491075{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int D = Integer.parseInt(line[1]);
        List<List<Integer>> lines = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            List<Integer> pair = new ArrayList<>();
            pair.add(Integer.parseInt(line[0]));
            pair.add(Integer.parseInt(line[1]));
            lines.add(pair);
        }
        int count = 0;
        for (List<Integer> pair : lines) {
            int x = pair.get(0);
            int y = pair.get(1);
            if (Math.sqrt(x * x + y * y) <= D) {
                count++;
            }
        }
        System.out.println(count);
    }
}

// 