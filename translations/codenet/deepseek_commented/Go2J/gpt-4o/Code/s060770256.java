import java.util.Scanner;

public class Main {
    // solution method takes two integers, n and m, as input.
    // It adjusts both n and m by subtracting 2 from each.
    // It then checks if the adjusted values are less than 0, and if so, it sets them to 1.
    // Finally, it returns the product of the adjusted n and m.
    public static int solution(int n, int m) {
        n = n - 2;
        m = m - 2;
        if (n < 0) {
            n = 1;
        }
        if (m < 0) {
            m = 1;
        }
        return n * m;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        System.out.println(solution(n, m));
        scanner.close();
    }
}

// <END-OF-CODE>
