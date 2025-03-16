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

        for (String s : v) {
            System.out.print(s);
        }

        System.out.println();
    }
}
