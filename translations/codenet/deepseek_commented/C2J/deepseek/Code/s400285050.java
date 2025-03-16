public class GCDCalculator {
    public static int you(int x, int y) {
        int z;
        while (true) {
            z = x % y;
            x = y;
            y = z;
            if (y <= 0) {
                break;
            }
        }
        return x;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z;
        if (x >= y) {
            z = you(x, y);
        } else {
            z = you(y, x);
        }
        System.out.println(z);
    }
}
