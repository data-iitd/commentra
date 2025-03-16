import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num = sc.nextInt();
        Set<Integer> num_set = new HashSet<>();
        Set<Integer> two_times_set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            num_set.add(sc.nextInt());
        }
        for (int i : num_set) {
            for (int j = 1; j < 30; j++) {
                if (i % 2 != 0) {
                    two_times_set.add(j);
                    break;
                }
                i /= 2;
            }
        }
        if (two_times_set.size() != 1) {
            System.out.println(0);
        } else {
            List<Integer> num_list = new ArrayList<>(num_set);
            int lcm = num_list.get(0);
            for (int i = 1; i < num_list.size(); i++) {
                lcm = lcm * num_list.get(i) / gcd(lcm, num_list.get(i));
            }
            System.out.println((num - lcm / 2) / lcm + 1);
        }
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
}

