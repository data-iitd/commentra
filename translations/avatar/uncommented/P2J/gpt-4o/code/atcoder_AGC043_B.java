import java.util.Scanner;

public class Main {
    public static int twosInFactorial(int n) {
        return n - Integer.bitCount(n);
    }

    public static boolean parityOfNCr(int n, int i) {
        int f = twosInFactorial(n);
        return f - twosInFactorial(n - i) - twosInFactorial(i) > 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int j = 0; j < n; j++) {
            nums[j] = scanner.nextInt() - 1;
        }

        boolean noOne = false;
        for (int num : nums) {
            if (num == 1) {
                noOne = true;
                break;
            }
        }

        if (!noOne) {
            for (int j = 0; j < nums.length; j++) {
                nums[j] /= 2;
            }
            noOne = true;
        }

        boolean isOdd = false;
        for (int i = 0; i < nums.length; i++) {
            if (!parityOfNCr(n - 1, i) && (nums[i] & 1) != 0) {
                isOdd ^= true;
            }
        }

        if (!isOdd) {
            System.out.println(0);
        } else {
            System.out.println(1 << (noOne ? 1 : 0));
        }

        scanner.close();
    }
}
// <END-OF-CODE>
