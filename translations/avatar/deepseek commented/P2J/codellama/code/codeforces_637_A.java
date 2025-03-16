import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] s = sc.nextLine().split(" ");

        Map<String, Integer> w = new HashMap<>();
        for (String i : s) {
            if (w.containsKey(i)) {
                w.put(i, w.get(i) + 1);
            } else {
                w.put(i, 1);
            }
        }

        ArrayList<String> list = new ArrayList<>(w.keySet());
        Collections.sort(list, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return w.get(o2) - w.get(o1);
            }
        });

        int c = -1;
        String a = "";
        for (String i : list) {
            if (w.get(i) == w.get(list.get(0))) {
                if (s.length - 1 - s.lastIndexOf(i) > c) {
                    a = i;
                    c = s.length - 1 - s.lastIndexOf(i);
                }
            }
        }

        System.out.println(a);
    }
}

