public class Main {
    public static int twos_in_factorial(int n) {
        return n - Integer.bitCount(n);
    }
    public static boolean parity_of_nCr(int n, int i) {
        return twos_in_factorial(n) - twos_in_factorial(n - i) - twos_in_factorial(i) > 0;
    }
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int[] nums = new int[args.length - 1];
        boolean no_one = false;
        if (args[1].indexOf('1') == -1) {
            for (int i = 0; i < nums.length; i++) {
                nums[i] = Integer.parseInt(args[i + 1]) / 2;
            }
            no_one = true;
        } else {
            for (int i = 0; i < nums.length; i++) {
                nums[i] = Integer.parseInt(args[i + 1]) - 1;
            }
        }
        boolean is_odd = false;
        for (int i = 0; i < nums.length; i++) {
            if (!parity_of_nCr(n - 1, i) && (nums[i] & 1) == 1) {
                is_odd ^= true;
            }
        }
        if (!is_odd) {
            System.out.println(0);
        } else {
            System.out.println(1 << no_one);
        }
    }
}
