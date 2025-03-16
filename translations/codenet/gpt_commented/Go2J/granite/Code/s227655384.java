
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class s227655384{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < 4; i++) {
            String line = reader.readLine();
            if (i == 1) {
                String[] tokens = line.split(" ");
                for (String token : tokens) {
                    int num = Integer.parseInt(token);
                    map.put(num, 1);
                }
            } else if (i == 3) {
                String[] tokens = line.split(" ");
                for (String token : tokens) {
                    int num = Integer.parseInt(token);
                    if (map.containsKey(num)) {
                        map.remove(num);
                    } else {
                        map.put(num, 1);
                    }
                }
            }
        }

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            list.add(entry.getKey());
        }

        Collections.sort(list);

        for (int num : list) {
            writer.write(num + "\n");
        }

        writer.flush();
    }
}

