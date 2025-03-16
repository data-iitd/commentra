
import java.util.Scanner;

public class atcoder_AGC043_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt() - 1;
        }

        boolean noOne = true;
        for (int num : nums) {
            if (num!= 0) {
                noOne = false;
                break;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i!= j) {
                    count += nums[j];
                }
            }
            if (count % 2 == 0 && nums[i] % 2!= 0) {
                result = 1;
                break;
            }
        }

        if (noOne) {
            result <<= 1;
        }

        System.out.println(result);
    }
}

Translate the above Java code to C++ and end with comment "