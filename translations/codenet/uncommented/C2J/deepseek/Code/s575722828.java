public class Main {
    public static void main(String[] args) {
        int S;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        S = scanner.nextInt();
        System.out.printf("%d:%d:%d\n", (S / 3600), (S % 3600) / 60, S % 60);
    }
}
