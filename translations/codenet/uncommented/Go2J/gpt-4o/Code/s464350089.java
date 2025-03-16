import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int h = scanner.nextInt();
        int n = scanner.nextInt();
        int a = 0;

        for (int i = 0; i < n; i++) {
            a += scanner.nextInt();
        }

        if (h > a) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
