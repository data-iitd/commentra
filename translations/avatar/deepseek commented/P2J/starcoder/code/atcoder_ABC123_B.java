
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<List<Integer>> menu = new ArrayList<List<Integer>>();
        for (int i = 0; i < 5; i++) {
            String m = sc.next();
            int e = Integer.parseInt(m.substring(m.length() - 1));
            if (e == 0) {
                e = 10;
            }
            menu.add(Arrays.asList(Integer.parseInt(m), e));
        }
        Collections.sort(menu, (a, b) -> a.get(1) - b.get(1));
        int ans = 0;
        for (List<Integer> m : menu.subList(1, menu.size())) {
            ans += Math.ceil(m.get(0) / 10.0) * 10;
        }
        System.out.println(ans + menu.get(0).get(0));
    }
}
