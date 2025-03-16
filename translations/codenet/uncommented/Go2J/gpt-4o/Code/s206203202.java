import java.util.Scanner;

public class Main {
    public static int abs(int x) {
        return x < 0 ? -x : x;
    }

    public static int min(int a, int b) {
        return (a > b) ? b : a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        int x = N % K;
        x = min(abs(x - K), x);
        System.out.println(x);
        
        scanner.close();
    }
}

// <END-OF-CODE>
