import java.util.Scanner;

public class Main {
    public static int solve(int a, int b, int c) {
        int temp_ = 0;
        if (c == a + b) {
            temp_ = b + c;
        } else if (c - 1 > a + b) {
            int temp = (c - 1) - (a + b);
            temp_ = b + c - temp;
        } else {
            temp_ = b + c;
        }
        return temp_;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        
        int ans = solve(a, b, c);
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
