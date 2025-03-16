public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        String s = TenToN(N, K);
        System.out.println(s.length());
    }

    public static String TenToN(int number, int n) {
        StringBuilder s = new StringBuilder();
        int tmp = number;
        while (true) {
            s.insert(0, Integer.toString(tmp % n));
            if (tmp < n) {
                break;
            }
            tmp /= n;
        }
        return s.toString();
    }
}
