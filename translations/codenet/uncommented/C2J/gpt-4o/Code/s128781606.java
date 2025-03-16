import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A, B, C, D, E, max;
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = A + B;
        D = A - B;
        E = A * B;
        max = C;
        if (max < D) {
            max = D;
        }
        if (max < E) {
            max = E;
        }
        System.out.println(max);
        scanner.close();
    }
}

// <END-OF-CODE>
