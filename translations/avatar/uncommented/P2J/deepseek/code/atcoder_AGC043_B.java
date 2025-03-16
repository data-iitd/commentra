import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static int twosInFactorial(int n) {
        return n - Integer.bitCount(n);
    }

    public static boolean parityOfNCR(int n, int i) {
        int f = twosInFactorial(n) - twosInFactorial(n - i) - twosInFactorial(i);
        return f > 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] input = scanner.nextLine().split(" ");
        List<Integer> nums = new ArrayList<>();
        for (String s : input) {
            nums.add(Integer.parseInt(s) - 1);
        }

        boolean noOne = nums.contains(1);
        if (!noOne) {
            nums.replaceAll(num -> num / 2);
        }

        boolean isOdd = false;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums.get(i);
            if (!parityOfNCR(n - 1, i) && num % 2 != 0) {
                isOdd ^= true;
            }
        }

        if (!isOdd) {
            System.out.println(0);
        } else {
            System.out.println(1 << (noOne ? 1 : 0));
        }
    }
}
