import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int R = scanner.nextInt();
        int S = scanner.nextInt();
        int P = scanner.nextInt();
        String T = scanner.next();
        
        Map<String, Integer> dict = new HashMap<>();
        dict.put("r", 0);
        dict.put("s", 0);
        dict.put("p", 0);
        
        boolean[] s = new boolean[N];
        boolean[] r = new boolean[N];
        boolean[] p = new boolean[N];
        
        for (int i = 0; i < N; i++) {
            s[i] = true;
            r[i] = true;
            p[i] = true;
        }
        
        for (int i = 0; i < T.length(); i++) {
            String charAtI = String.valueOf(T.charAt(i));
            if (i >= K) {
                if (charAtI.equals(String.valueOf(T.charAt(i - K)))) {
                    switch (charAtI) {
                        case "s":
                            if (s[i % K]) {
                                s[i % K] = false;
                                continue;
                            } else {
                                s[i % K] = true;
                            }
                            break;
                        case "r":
                            if (r[i % K]) {
                                r[i % K] = false;
                                continue;
                            } else {
                                r[i % K] = true;
                            }
                            break;
                        case "p":
                            if (p[i % K]) {
                                p[i % K] = false;
                                continue;
                            } else {
                                p[i % K] = true;
                            }
                            break;
                    }
                } else {
                    switch (charAtI) {
                        case "s":
                            s[i % K] = true;
                            break;
                        case "r":
                            r[i % K] = true;
                            break;
                        case "p":
                            p[i % K] = true;
                            break;
                    }
                }
            }
            switch (charAtI) {
                case "s":
                    dict.put("s", dict.get("s") + 1);
                    break;
                case "r":
                    dict.put("r", dict.get("r") + 1);
                    break;
                case "p":
                    dict.put("p", dict.get("p") + 1);
                    break;
            }
        }
        
        int res = P * dict.get("r") + S * dict.get("p") + R * dict.get("s");
        System.out.println(res);
    }
}
// <END-OF-CODE>
