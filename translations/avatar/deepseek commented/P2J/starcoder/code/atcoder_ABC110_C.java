
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        System.out.println(run(s, t));
    }

    public static String run(String s, String t) {
        List<Integer> ss = new ArrayList<Integer>(Collections.frequency(s.split(""), ""));
        Collections.sort(ss);
        List<Integer> tt = new ArrayList<Integer>(Collections.frequency(t.split(""), ""));
        Collections.sort(tt);
        if (ss.equals(tt)) {
            return "Yes";
        } else {
            return "No";
        }
    }
}

