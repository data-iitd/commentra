public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        if (n % 1000 == 0) {
            System.out.println(0);
        } else {
            System.out.println((n / 1000 + 1) * 1000 - n);
        }
    }
}
