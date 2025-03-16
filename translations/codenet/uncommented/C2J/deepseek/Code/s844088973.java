public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int K = scanner.nextInt();
        int X = scanner.nextInt();
        for (int i = X - K + 1; i <= X + K - 1; i++) {
            System.out.print(i);
            if (i < X + K - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}
