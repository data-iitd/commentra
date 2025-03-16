import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        while (n-- > 0) {
            int p = scanner.nextInt();
            int q = scanner.nextInt();
            int l = (int) Math.sqrt(p * p + q * q);
            boolean isPrime = true;

            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    int x = i * i + j * j;
                    if (x <= 1 || x >= p * p + q * q) continue;
                    if ((i * p + j * q) % x == 0 && (i * q - j * p) % x == 0) {
                        isPrime = false;
                    }
                }
            }
            System.out.println(isPrime ? "P" : "C");
        }
        scanner.close();
    }
}

// <END-OF-CODE>
