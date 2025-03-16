

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class s635098814{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<Character, Integer> map = new HashMap<>();
        while (true) {
            String str = br.readLine();
            if (str.equals("")) {
                break;
            }
            char[] chars = str.toCharArray();
            for (char c : chars) {
                if (Character.isLetter(c)) {
                    char key = Character.toLowerCase(c);
                    map.put(key, map.getOrDefault(key, 0) + 1);
                }
            }
        }
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }
    }
}

// MODはとったか？
// 遷移だけじゃなくて最後の最後でちゃんと取れよ？

