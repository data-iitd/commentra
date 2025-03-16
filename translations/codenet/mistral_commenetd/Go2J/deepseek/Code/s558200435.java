import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> a = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }

        List<Integer> b = new ArrayList<>();

        for (int v : a) {
            int x = Collections.binarySearch(b, v);
            if (x < 0) {
                x = -(x + 1);
            }
            if (x == b.size()) {
                b.add(v);
            } else {
                b.set(x, v);
            }
        }

        System.out.println(b.size());
