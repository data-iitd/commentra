import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long m = n;
        n--;
        for (; n > 1; n--) {
            m *= n;
        }
        System.out.println(m);
        scanner.close();
    }
}

// <END-OF-CODE>
