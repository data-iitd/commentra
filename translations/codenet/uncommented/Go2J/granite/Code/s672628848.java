
import java.util.Scanner;

public class s672628848{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        int e = scanner.nextInt();

        int[] al = {a, b, c, d, e};

        for (int n = 0; n < al.length; n++) {
            if (al[n] == 0) {
                System.out.println(n + 1);
                break;
            }
        }
    }
}

