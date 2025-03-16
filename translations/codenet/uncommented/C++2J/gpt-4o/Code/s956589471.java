import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        int e = scanner.nextInt();
        int k = scanner.nextInt();
        
        System.out.println((e - a <= k) ? "Yay!" : ":(");
        
        scanner.close();
    }
}

// <END-OF-CODE>
