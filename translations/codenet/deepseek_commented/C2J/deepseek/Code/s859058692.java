public class SumMinMax {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        long sum = 0;

        for (int i = 0; i < n; i++) {
            int m = scanner.nextInt();
            sum += m;

            if (m < min) {
                min = m;
            }

            if (m > max) {
                max = m;
            }
        }

        System.out.println(min + " " + max + " " + sum);
    }
}
