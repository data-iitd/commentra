public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        int ans = 0;
        if (6 <= A && A <= 12) {
            ans = B / 2;
        } else if (12 < A) {
            ans = B;
        }
        System.out.println(ans);
    }
}
