import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int X = scanner.nextInt();
        
        X = X / 50;
        
        int kosu = 0;
        
        for (int i = 0; i <= A; i++) {
            for (int j = 0; j <= B; j++) {
                for (int k = 0; k <= C; k++) {
                    if (X == (10 * i) + (2 * j) + k) {
                        kosu++;
                    }
                }
            }
        }
        
        System.out.println(kosu);
        
        scanner.close();
    }
}

// <END-OF-CODE>
