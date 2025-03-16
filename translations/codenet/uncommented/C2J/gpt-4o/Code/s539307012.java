import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int min = scanner.nextInt();
        x -= min;
        
        for (int i = 1; i < n; i++) {
            int m = scanner.nextInt();
            x -= m;
            if (min > m) {
                min = m;
            }
        }
        
        System.out.println(n + x / min);
        scanner.close();
    }
}

// <END-OF-CODE>
