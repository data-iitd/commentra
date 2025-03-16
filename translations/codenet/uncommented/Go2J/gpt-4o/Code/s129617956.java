import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int rt = (int) Math.sqrt(n);
        int minf = 100;

        for (int i = 1; i <= rt; i++) {
            if (n % i == 0) {
                int b = n / i;
                int ndigit = 0;
                while (b > 0) {
                    b /= 10;
                    ndigit++;
                }
                minf = Math.min(minf, ndigit);
            }
        }
        System.out.println(minf);
    }
}

// <END-OF-CODE>
