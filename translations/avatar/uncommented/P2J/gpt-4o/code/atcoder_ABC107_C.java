import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        List<Integer> lst = new ArrayList<>();
        
        for (int i = 0; i < N; i++) {
            lst.add(scanner.nextInt());
        }
        
        List<Integer> lst_p = new ArrayList<>();
        List<Integer> lst_m = new ArrayList<>();
        
        for (int i = 0; i < N; i++) {
            if (lst.get(i) == 0) {
                K--;
            }
            if (lst.get(i) > 0) {
                lst_p.add(lst.get(i));
            } else if (lst.get(i) < 0) {
                lst_m.add(lst.get(i));
            }
        }
        
        int lastx = lst_p.size();
        int lasty = lst_m.size();
        
        System.out.println(check(lst_p, lst_m, K, lastx, lasty));
    }
    
    public static int check(List<Integer> lst_p, List<Integer> lst_m, int k, int lastx, int lasty) {
        int ans = Integer.MAX_VALUE;
        
        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {
                continue;
            } else {
                int p = (j == 0) ? 0 : lst_p.get(j - 1);
                int m = (k - j == 0) ? 0 : lst_m.get(lasty - (k - j));
                ans = Math.min(ans, 2 * p + Math.abs(m));
                ans = Math.min(ans, p + 2 * Math.abs(m));
            }
        }
        
        return ans;
    }
}
// <END-OF-CODE>
