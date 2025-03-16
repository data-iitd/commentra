import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<int[]> menu = new ArrayList<>();

        for (int i = 0; i < 5; i++) {
            String m = scanner.nextLine();
            int e = Character.getNumericValue(m.charAt(m.length() - 1));
            if (e == 0) {
                e = 10;
            }
            menu.add(new int[]{Integer.parseInt(m), e});
        }

        Collections.sort(menu, Comparator.comparingInt(a -> a[1]));

        int ans = 0;
        for (int i = 1; i < menu.size(); i++) {
            ans += Math.ceil(menu.get(i)[0] / 10.0) * 10;
        }

        System.out.println(ans + menu.get(0)[0]);
        scanner.close();
    }
}
//<END-OF-CODE>
