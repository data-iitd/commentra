import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String x;
        int sum;

        do {
            x = scanner.nextLine();
            sum = 0;

            for (int i = 0; i < x.length(); i++) {
                if (x.charAt(i) == '0') {
                    System.out.println(sum);
                    break;
                } else {
                    sum += x.charAt(i) - '0';
                }
            }
        } while (x.charAt(0) != '0');

        scanner.close();
    }
}
// <END-OF-CODE>
