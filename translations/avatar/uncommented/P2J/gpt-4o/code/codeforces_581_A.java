import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        int min = Math.min(a, b);
        int max = Math.max(a, b);
        int difference = (max - min) / 2;
        
        System.out.println(min + " " + difference);
        
        scanner.close();
    }
}
// <END-OF-CODE>
