public class Main {
    public static void main(String[] args) {
        int A, B;
        int ans = 0;
        int out = 1;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextInt();
        B = scanner.nextInt();

        while (out < B) {
            out--;
            out += A;
            ans++;
        }
        System.out.println(ans);
    }
}
