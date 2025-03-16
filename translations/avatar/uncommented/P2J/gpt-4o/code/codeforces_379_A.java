import java.util.Scanner;

public class CandleCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int candeleIntere = scanner.nextInt();
        int b = scanner.nextInt();
        int s = 0;
        int restoSciolte = 0;

        while (candeleIntere > 0 || restoSciolte >= b) {
            restoSciolte += candeleIntere % b;
            s += candeleIntere;
            candeleIntere += restoSciolte / b;
            restoSciolte %= b;
            candeleIntere /= b;
        }

        System.out.println(s);
        scanner.close();
    }
}

// <END-OF-CODE>
