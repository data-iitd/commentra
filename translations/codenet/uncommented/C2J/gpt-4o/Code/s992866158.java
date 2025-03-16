import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int cnt = 0;
        
        while (n-- > 0) {
            int h = scanner.nextInt();
            if (h >= k) {
                cnt++;
            }
        }
        
        System.out.println(cnt);
        scanner.close();
    }
}

// <END-OF-CODE>
