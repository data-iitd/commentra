import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        List<String> s = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            s.add(scanner.next());
        }

        Collections.sort(s);

        StringBuilder ans = new StringBuilder();
        for (String str : s) {
            ans.append(str);
        }
        System.out.println(ans.toString());
    }
}
