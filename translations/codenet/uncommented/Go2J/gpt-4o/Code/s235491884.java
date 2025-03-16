import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        
        int n = s.length() - s.replace("o", "").length();
        System.out.println(700 + n * 100);
        
        scanner.close();
    }
}

// <END-OF-CODE>
