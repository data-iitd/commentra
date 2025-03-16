import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        List<String> v = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            String s = scanner.next();
            v.add(s);
        }

        Collections.sort(v);

        StringBuilder result = new StringBuilder();
        for (String s : v) {
            result.append(s);
        }
        System.out.println(result.toString());
    }
}
