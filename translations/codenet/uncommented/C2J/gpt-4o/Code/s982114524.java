import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int i, N, x = 0;
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        for (i = 1; i <= N; i++) {
            x += i;
        }
        System.out.println(x);
        scanner.close();
    }
}

// <END-OF-CODE>
