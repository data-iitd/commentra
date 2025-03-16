import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num = sc.nextInt();
        Set<Integer> num_set = new HashSet<Integer>();
        for (int i = 0; i < n; i++) {
            num_set.add(sc.nextInt());
        }
        Set<Integer> two_times_set = new HashSet<Integer>();
        for (int i : num_set) {
            for (int j = 1; j < 30; j++) {
                i /= 2;
                if (i % 2!= 0) {
                    two_times_set.add(j);
                    break;
                }
            }
            if (two_times_set.size()!= 1) {
                System.out.println(0);
                return;
            }
        }
        List<Integer> num_list = new ArrayList<Integer>(num_set);
        int lcm = num_list.get(0);
        for (int i = 1; i < num_list.size(); i++) {
            lcm = lcm * num_list.get(i) / gcd(lcm, num_list.get(i));
        }
        System.out.println((num - lcm / 2) / lcm + 1);
    }
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
