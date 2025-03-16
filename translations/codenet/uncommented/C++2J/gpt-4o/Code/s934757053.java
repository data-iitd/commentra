import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int ans = 0;
        int out = 1;

        while (out < B) {
            out--;
            out += A;
            ans++;
        }
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
