import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        List<Tuple> m = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] parts = scanner.nextLine().split(" ");
            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[1]);
            m.add(new Tuple(a, b));
        }

        Collections.sort(m, new Comparator<Tuple>() {
            @Override
            public int compare(Tuple t1, Tuple t2) {
                return Integer.compare(t2.a, t1.a);
            }
        });

        Tuple a = m.get(0);

        for (int i = 1; i < m.size(); i++) {
            Tuple current = m.get(i);
            if (current.b > a.b) {
                System.out.println("Happy Alex");
                return;
            }
            a = current;
        }

        System.out.println("Poor Alex");
    }

    static class Tuple {
        int a;
        int b;

        Tuple(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
}
