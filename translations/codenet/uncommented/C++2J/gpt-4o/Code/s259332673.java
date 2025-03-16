import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int h1 = scanner.nextInt();
        int m1 = scanner.nextInt();
        int h2 = scanner.nextInt();
        int m2 = scanner.nextInt();
        int k = scanner.nextInt();
        
        int ans = h2 * 60 + m2 - (h1 * 60 + m1);
        
        System.out.println(ans - k);
        
        scanner.close();
    }
}

// <END-OF-CODE>
