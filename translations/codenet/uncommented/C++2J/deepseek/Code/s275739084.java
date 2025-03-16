public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = A + B;
        if (A % 3 != 0 && B % 3 != 0 && C % 3 != 0) {
            System.out.println("Impossible");
        } else {
            System.out.println("Possible");
        }
    }
}
