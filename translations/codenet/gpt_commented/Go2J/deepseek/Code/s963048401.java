import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> as = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            as.add(scanner.nextInt());
        }

        List<Integer> xs = new ArrayList<>();
        xs.add(as.get(0));

        for (int j = 1; j < n; j++) {
            int current = as.get(j);
            int idx = Collections.binarySearch(xs, current);
            if (idx < 0) {
                idx = -(idx + 1);
            }
            if (idx == xs.size()) {
                xs.add(current);
            } else {
                xs.set(idx, current);
            }
        }

        System.out.println(xs.size());
    }
}

