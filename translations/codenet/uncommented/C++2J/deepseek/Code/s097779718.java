public class Main {
    public static long Euclid(long x, long y) {
        long tmp;

        if (x < y) {
            tmp = x;
            x = y;
            y = tmp;
        }

        if (x % y == 0) return y;
        return Euclid(y, x % y);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long B = scanner.nextLong();

        System.out.println((A * B) / Euclid(A, B));
    }
}
