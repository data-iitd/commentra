public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        java.util.List<Long> a = new java.util.ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextLong());
        }

        java.util.List<Long> abs_a = new java.util.ArrayList<>(a);

        for (int i = 0; i < n; i++) {
            if (abs_a.get(i) < 0) {
                abs_a.set(i, -abs_a.get(i));
            }
        }

        long ans = 0;
        long min = abs_a.get(0);
        for (long e : abs_a) {
            ans += e;
            if (min > e) {
                min = e;
            }
        }
        int num_negative = 0;
        for (long e : a) {
            if (e < 0) {
                num_negative++;
            }
        }

        if (num_negative % 2 != 0) {
            ans -= min * 2;
        }

        System.out.println(ans);
    }
}
