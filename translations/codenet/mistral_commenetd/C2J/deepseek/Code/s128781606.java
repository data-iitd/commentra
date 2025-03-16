public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        int C = A + B;
        int D = A - B;
        int E = A * B;

        int max = C;

        if (max < D) {
            max = D;
        }

        if (max < E) {
            max = E;
        }

        System.out.println(max);
    }
}
