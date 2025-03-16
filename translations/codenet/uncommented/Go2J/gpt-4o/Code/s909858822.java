import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        int ans = 0;
        if (6 <= A && A <= 12) {
            ans = B / 2;
        } else if (A > 12) {
            ans = B;
        }
        
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
