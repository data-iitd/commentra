import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        List<Integer> S = new ArrayList<>();
        
        String[] input = scanner.nextLine().split(" ");
        for (String num : input) {
            S.add(Integer.parseInt(num));
        }
        
        Collections.sort(S, Collections.reverseOrder());
        boolean[] flag = new boolean[S.size()];
        Arrays.fill(flag, true);
        List<Integer> cur = new ArrayList<>();
        cur.add(S.get(0));
        flag[0] = false;

        for (int i = 0; i < N; i++) {
            int j = 0;
            int jM = cur.size();
            for (int k = 0; k < S.size(); k++) {
                if (flag[k] && S.get(k) < cur.get(j)) {
                    cur.add(S.get(k));
                    j++;
                    flag[k] = false;
                    if (j == jM) {
                        break;
                    }
                }
            }
            if (j < jM) {
                System.out.println("No");
                return;
            }
            Collections.sort(cur, Collections.reverseOrder());
        }
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
