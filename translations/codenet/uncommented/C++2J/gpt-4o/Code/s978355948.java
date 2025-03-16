import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        int[] L = new int[N];
        
        for (int i = 0; i < N; i++) {
            L[i] = scanner.nextInt();
        }
        
        int i;
        int d = 0;
        for (i = 0; i < N; i++) {
            d += L[i];
            if (d > X) {
                break;
            }
        }
        
        System.out.println(i + 1);
        scanner.close();
    }
}

// <END-OF-CODE>
