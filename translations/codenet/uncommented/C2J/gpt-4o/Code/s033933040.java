import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a, b, mawari, menseki;
        
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        mawari = a + a + b + b;
        menseki = a * b;
        
        System.out.println(menseki + " " + mawari);
        
        scanner.close();
    }
}

// <END-OF-CODE>
