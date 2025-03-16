import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long N = scanner.nextLong();
        long X = scanner.nextLong();
        
        long ans = 0;
        long min = Long.MAX_VALUE;
        
        for (int i = 0; i < N; i++) {
            long tmp = scanner.nextLong();
            X -= tmp;
            ans++;
            if (tmp < min) min = tmp;
        }
        
        ans += X / min;
        
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
