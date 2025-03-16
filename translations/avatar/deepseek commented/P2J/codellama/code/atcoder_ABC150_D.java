
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;

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
            int j = 1;
            while (i % 2 == 0) {
                i /= 2;
                j++;
            }
            two_times_set.add(j);
        }
        if (two_times_set.size() != 1) {
            System.out.println(0);
        } else {
            int lcm = 1;
            for (int i : num_set) {
                lcm = lcm * i / gcd(lcm, i);
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

