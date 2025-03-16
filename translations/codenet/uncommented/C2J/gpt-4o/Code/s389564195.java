import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int x, kotae;
        
        x = scanner.nextInt();
        
        kotae = x * x * x;
        
        System.out.println(kotae);
        
        scanner.close();
    }
}

// <END-OF-CODE>
