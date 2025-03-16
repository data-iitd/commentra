
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> menu = new ArrayList<Integer>();
        for (int i = 0; i < 5; i++) {
            String m = sc.nextLine();
            int e = Integer.parseInt(m.substring(m.length() - 1));
            if (e == 0) {
                e = 10;
            }
            menu.add(Integer.parseInt(m) * e);
        }
        Collections.sort(menu);
        int ans = 0;
        for (int i = 1; i < menu.size(); i++) {
            ans += (int) Math.ceil((double) menu.get(i) / 10) * 10;
        }
        System.out.println(ans + menu.get(0));
    }
}

