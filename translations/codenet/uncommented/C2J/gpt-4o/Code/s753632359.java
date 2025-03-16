import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N, D; // N, D are integers between 1 and 20
        int ans, rem;

        N = scanner.nextInt();
        D = scanner.nextInt();

        ans = N / (D * 2 + 1);
        rem = N % (D * 2 + 1);

        if (rem != 0) {
            ans = ans + 1;
        }

        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
