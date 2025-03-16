import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int num = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        String[] numStrArray = scanner.nextLine().split(" ");
        Set<Integer> numSet = new HashSet<>();
        for (String s : numStrArray) {
            numSet.add(Integer.parseInt(s));
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
        if (twoTimesSet.size() != 1) {
            System.out.println(0);
            return;
        }
        int[] numArray = new int[numSet.size()];
        int index = 0;
        for (int i : numSet) {
            numArray[index++] = i;
        }
        int lcm = numArray[0];
        for (int i = 1; i < numArray.length; i++) {
            lcm = lcm(lcm, numArray[i]);
        }
        int result = (num - lcm / 2) / lcm + 1;
        System.out.println(result);
    }

    // Function to calculate the Least Common Multiple (LCM)
    public static int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }

    // Function to calculate the Greatest Common Divisor (GCD)
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
