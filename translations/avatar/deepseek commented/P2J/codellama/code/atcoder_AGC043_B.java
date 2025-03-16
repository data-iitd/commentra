public class Main {
    public static int twosInFactorial(int n) {
        // Calculate the number of factors of 2 in the factorial of n
        return n - Integer.bitCount(n);
    }

    public static boolean parityOfnCr(int n, int i) {
        // Determine the parity (odd or even) of the binomial coefficient nCr
        int f = twosInFactorial(n);
        return f - twosInFactorial(n - i) - twosInFactorial(i) > 0;
    }

    public static void main(String[] args) {
        // Read an integer n and a list of integers from the input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        // If the list does not contain the number 1, halve each number in the list and set no_one to True
        boolean no_one = false;
        if (Arrays.stream(nums).noneMatch(num -> num == 1)) {
            for (int i = 0; i < n; i++) {
                nums[i] /= 2;
            }
            no_one = true;
        }

        // Initialize is_odd to False
        boolean is_odd = false;

        // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
        for (int i = 0; i < n; i++) {
            if (!parityOfnCr(n - 1, i) && nums[i] % 2 == 1) {
                is_odd ^= true;
            }
        }

        // If is_odd is False, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
        if (!is_odd) {
            System.out.println(0);
        } else {
            System.out.println(1 << no_one);
        }
    }
}
