import java.util.Scanner;

public class TimeConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int S = scanner.nextInt();

        if (S < 60) {
            System.out.printf("0:0:%d%n", S);
        } else if (S < 3600) {
            System.out.printf("0:%d:%d%n", S / 60, S % 60);
        } else {
            System.out.printf("%d:%d:%d%n", S / 3600, (S % 3600) / 60, S % 60);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
