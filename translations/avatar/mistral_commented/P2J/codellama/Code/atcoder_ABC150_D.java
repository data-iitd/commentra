
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num = sc.nextInt();
        Set<Integer> num_set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            num_set.add(sc.nextInt());
        }

        Set<Integer> two_times_set = new HashSet<>();
        for (int i : num_set) {
            int power_of_two = 0;
            while (i % 2 == 0) {
                power_of_two++;
                i /= 2;
            }
            if (power_of_two > 1) {
                System.out.println(0);
                return;
            }
            two_times_set.add(power_of_two);
        }
        if (two_times_set.size() != 1) {
            System.out.println(0);
            return;
        }

        int[] num_list = new int[num_set.size()];
        int i = 0;
        for (int j : num_set) {
            num_list[i++] = j;
        }
        int lcm = num_list[0];
        for (i = 1; i < num_list.length; i++) {
            lcm = lcm * num_list[i] / (int) Math.gcd(lcm, num_list[i]);
        }
        System.out.println((num - lcm / 2) / lcm + 1);
    }
}

