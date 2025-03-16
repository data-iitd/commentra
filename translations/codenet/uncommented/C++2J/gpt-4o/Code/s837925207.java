import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x, ans = 0;

        x = scanner.nextInt();

        ans = x + x * x + x * x * x;

        System.out.println(ans);

        scanner.close();
    }
}

// <END-OF-CODE>
