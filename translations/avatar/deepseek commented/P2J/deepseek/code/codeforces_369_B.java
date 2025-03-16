public class Main {
    public static void main(String[] args) {
        // Read input values for n, k, l, r, sa, and sk
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int sa = scanner.nextInt();
        int sk = scanner.nextInt();

        // Use the get_nums function to calculate the distribution of sk and sa - sk
        int[] ans = get_nums(k, sk, n);
        int[] ans2 = get_nums(n - k, sa - sk, n);

        // Print the result as a space-separated string of numbers
        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i] + " ");
        }
        for (int i = 0; i < ans2.length; i++) {
            System.out.print(ans2[i] + " ");
        }
    }

    public static int[] get_nums(int num, int t, int total_num) {
        // This function distributes the value t among num parts.
        // It calculates the base number for each part by dividing t by num.
        // It adds 1 to the base number for the first t % num parts.
        int[] result = new int[total_num];
        for (int i = 0; i < total_num; i++) {
            if (i < t % num) {
                result[i] = t / num + 1;
            } else {
                result[i] = t / num;
            }
        }
        return result;
    }
}
