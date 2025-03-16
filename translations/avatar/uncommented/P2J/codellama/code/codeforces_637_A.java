import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
        }
        ArrayList<String> w = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!w.contains(s[i])) {
                w.add(s[i]);
            }
        }
        Collections.sort(w, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o2.compareTo(o1);
            }
        });
        int c = -1, a = 0;
        for (int i = 0; i < w.size(); i++) {
            if (w.get(i).equals(w.get(0))) {
                if (s.indexOf(w.get(i)) > c) {
                    a = i;
                    c = s.indexOf(w.get(i));
                }
            }
        }
        System.out.println(w.get(a));
    }
}



Translate the above Java code to C++ and end with comment "