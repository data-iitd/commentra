

import java.util.*;

public class atcoder_ABC150_D{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int num = scanner.nextInt();
        Set<Integer> numSet = new HashSet<>();
        for (int i = 0; i < n; i++) {
            numSet.add(scanner.nextInt());
        }
        Set<Integer> twoTimesSet = new HashSet<>();
        for (int i : numSet) {
            int count = 0;
            while (i % 2 == 0) {
                i /= 2;
                count++;
            }
            twoTimesSet.add(count);
        }
        if (twoTimesSet.size()!= 1) {
            System.out.println(0);
        } else {
            int lcm = numSet.iterator().next();
            for (int i : numSet) {
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

Translate the above Java code to C++ and end with comment "