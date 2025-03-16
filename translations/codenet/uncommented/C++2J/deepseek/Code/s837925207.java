public class Main {
    public static void main(String[] args) {
        int x, ans = 0;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x = scanner.nextInt();

        ans = x + x*x + x*x*x;

        System.out.println(ans);
    }
}
