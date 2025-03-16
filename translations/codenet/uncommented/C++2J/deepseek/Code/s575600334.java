public class BitwiseOperations {
    public static void binPrint(int x, int bits) {
        for (int i = bits - 1; i >= 0; i--) {
            System.out.print(x & (1 << i) ? 1 : 0);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        binPrint(a & b, 32);
        binPrint(a | b, 32);
        binPrint(a ^ b, 32);
    }
}
