import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int A = scanner.nextInt();
        System.out.println((N % 500 <= A) ? "Yes" : "No");
        scanner.close();
    }
}

// <END-OF-CODE>
