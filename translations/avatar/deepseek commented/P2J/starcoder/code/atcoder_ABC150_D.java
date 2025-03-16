
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num = sc.nextInt();
        Set<Integer> numSet = new HashSet<>();
        for (int i = 0; i < n; i++) {
            numSet.add(sc.nextInt());
        }
        Set<Integer> twoTimesSet = new HashSet<>();
        for (int i : numSet) {
            int j = 1;
            while (i % 2 == 0) {
                i /= 2;
                twoTimesSet.add(j);
                j++;
            }
        }
        if (twoTimesSet.size()!= 1) {
            System.out.println(0);
            return;
        }
        int lcm = numSet.iterator().next();
        for (int i : numSet) {
            lcm = lcm * i / Math.gcd(lcm, i);
        }
        System.out.println((num - lcm / 2) / lcm + 1);
    }
}

