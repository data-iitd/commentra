public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        if (n % 2 == 0) {
            System.out.println(n / 2);
        } else {
            System.out.println((n / 2) + 1);
        }
    }
}
