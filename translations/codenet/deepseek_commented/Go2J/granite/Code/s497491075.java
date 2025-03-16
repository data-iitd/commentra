
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
        List<List<Integer>> points = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            input = reader.readLine().split(" ");
            List<Integer> point = new ArrayList<>();
            point.add(Integer.parseInt(input[0]));
            point.add(Integer.parseInt(input[1]));
            points.add(point);
        }
        int count = 0;
        for (List<Integer> point : points) {
            if (Math.sqrt(Math.pow(point.get(0), 2) + Math.pow(point.get(1), 2)) <= D) {
                count++;
            }
        }
        System.out.println(count);
    }
}

// END-OF-CODE