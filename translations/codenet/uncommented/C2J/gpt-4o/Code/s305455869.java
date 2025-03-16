import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        int ans = 0;
        if (a >= 13) {
            ans = b;
        } else if (a >= 6) {
            ans = b / 2;
        }
        
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
