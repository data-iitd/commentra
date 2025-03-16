import java.util.Scanner;

public class TimeConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int S = scanner.nextInt();
        
        System.out.printf("%d:%d:%d\n", S / 3600, (S % 3600) / 60, S % 60);
        
        scanner.close();
    }
}

// <END-OF-CODE>
