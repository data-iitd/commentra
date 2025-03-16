import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt();
        int r = scanner.nextInt();
        
        if (r > -h) {
            System.out.println("1");
        } else if (r == -h) {
            System.out.println("0");
        } else {
            System.out.println("-1");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
