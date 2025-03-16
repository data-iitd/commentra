import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt() - 1;
        }

        boolean noOne = false;
        if (Arrays.stream(nums).noneMatch(x -> x == 1)) {
            for (int i = 0; i < n; i++) {
                nums[i] /= 2;
            }
            noOne = true;
        }

        boolean isOdd = false;
        for (int i = 0; i < n; i++) {
            if (!parityOfNCr(n - 1, i) && (nums[i] & 1) == 1) {
                isOdd ^= true;
            }
        }

        if (!isOdd) {
            System.out.println(0);
        } else {
            System.out.println(1 << noOne);
        }
    }

    public static boolean parityOfNCr(int n, int r) {
        int f = twosInFactorial(n);
        return f - twosInFactorial(n - r) - twosInFactorial(r) > 0;
    }

    public static int twosInFactorial(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
}

