import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int x, y;
        x = 0; 
        y = 0;   

        Scanner scanner = new Scanner(System.in);
        x = scanner.nextInt();
        y = scanner.nextInt();
        
        System.out.println((x * y) + " " + ((2 * x) + (2 * y)));

        scanner.close();
    }
}

// <END-OF-CODE>
