import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[] train = new int[2];
        int[] bus = new int[2];

        train[0] = scanner.nextInt();
        train[1] = scanner.nextInt();
        bus[0] = scanner.nextInt();
        bus[1] = scanner.nextInt();

        System.out.println(Math.min(train[0], train[1]) + Math.min(bus[0], bus[1]));

        scanner.close();
    }
}

// <END-OF-CODE>
