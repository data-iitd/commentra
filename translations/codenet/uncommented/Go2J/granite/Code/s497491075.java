
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class s497491075{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int D = Integer.parseInt(input[1]);
        List<int[]> lines = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            input = reader.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            lines.add(new int[]{x, y});
        }
        int count = 0;
        for (int[] line : lines) {
            int distance = (int) Math.sqrt(Math.pow(line[0], 2) + Math.pow(line[1], 2));
            if (distance <= D) {
                count++;
            }
        }
        System.out.println(count);
    }
}

