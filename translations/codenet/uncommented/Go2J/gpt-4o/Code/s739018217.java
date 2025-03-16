import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = m * 1900 + (n - m) * 100;
        System.out.println(x * Math.pow(2.0, m));
        scanner.close();
    }
}

// <END-OF-CODE>
