import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i = 1;
        int input;

        while (true) {
            input = scanner.nextInt();
            if (input == 0) {
                break;
            }
            System.out.printf("Case %d: %d%n", i, input);
            i++;
        }
        scanner.close();
    }
}

// <END-OF-CODE>
