
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

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
                j++;
            }
            if (i % 2 != 0) {
                twoTimesSet.add(j);
            }
        }
        if (twoTimesSet.size() != 1) {
            System.out.println(0);
        } else {
            int[] numArray = new int[numSet.size()];
            int i = 0;
            for (int num : numSet) {
                numArray[i++] = num;
            }
            int lcm = numArray[0];
            for (int j = 1; j < numArray.length; j++) {
                lcm = lcm * numArray[j] / gcd(lcm, numArray[j]);
            }
            System.out.println((num - lcm / 2) / lcm + 1);
        }
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

