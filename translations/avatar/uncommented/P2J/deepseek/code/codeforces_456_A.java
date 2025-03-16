import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<int[]> m = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            int[] row = new int[2];
            row[0] = scanner.nextInt();
            row[1] = scanner.nextInt();
            m.add(row);
        }
        
        Collections.sort(m, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return b[1] - a[1];
            }
        });
        
        int[] a = m.get(0);
        for (int i = 1; i < m.size(); i++) {
            int[] current = m.get(i);
            if (current[1] > a[1]) {
                System.out.println("Happy Alex");
                return;
            }
            a = current;
        }
        System.out.println("Poor Alex");
    }
}
