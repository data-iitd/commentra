import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // n gu m ki
        int ans = 0;
        
        // gu gu
        ans += n * (n - 1) / 2;
        
        // kiki
        ans += m * (m - 1) / 2;
        
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
