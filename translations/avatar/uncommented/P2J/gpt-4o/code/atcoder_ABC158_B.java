import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long mod = 1000000007;
        int N = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        long ans = 0;
        int rep = N / (A + B);
        ans += rep * A;
        int res = N - rep * (A + B);
        ans += Math.min(res, A);
        
        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
