

import java.util.Scanner;
import java.util.TreeSet;

public class codeforces_274_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        TreeSet<Integer> set = new TreeSet<>();
        int max = 0;
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (num % k!= 0 ||!set.contains(num / k)) {
                set.add(num);
                max = Math.max(max, set.size());
            }
        }
        System.out.println(max);
    }
}

Translate the above Java code to C++ and end with comment "