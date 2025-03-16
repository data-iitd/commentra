public class MinMaxSum {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        long min = 1000000, max = -1000000, sum = 0;

        for (int i = 0; i < n; i++) {
            int tmp = scanner.nextInt();
            if (min > tmp) min = tmp;
            if (max < tmp) max = tmp;
            sum += tmp;
        }

        System.out.println(min + " " + max + " " + sum);
    }
}
