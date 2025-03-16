
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class s227655384{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] lines = new String[4];
        for (int i = 0; i < 4; i++) {
            lines[i] = br.readLine();
        }
        br.close();

        Map<Integer, Integer> map = new HashMap<>();
        String[] a = lines[1].split(" ");
        for (String s : a) {
            map.put(Integer.parseInt(s), 1);
        }

        List<Integer> result = new ArrayList<>();
        String[] b = lines[3].split(" ");
        for (String s : b) {
            int num = Integer.parseInt(s);
            if (map.containsKey(num)) {
                map.remove(num);
            } else {
                map.put(num, 1);
            }
        }
        result.addAll(map.keySet());
        Collections.sort(result);
        for (int num : result) {
            System.out.println(num);
        }
    }
}

