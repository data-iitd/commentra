public class Main {
    public static int solution(int n, int m) {
        n = n - 2;
        m = m - 2;
        if (n < 0) {
            n = 1;
        }
        if (m < 0) {
            m = 1;
        }
        return n * m;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        System.out.println(solution(n, m));
    }
}
