import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }
        Collections.sort(a);
        for (int i = 0; i < n - 1; i++) {
            if (a.get(i).equals(a.get(i + 1))) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
