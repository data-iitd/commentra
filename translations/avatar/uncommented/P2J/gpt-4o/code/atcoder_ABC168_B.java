import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int K = Integer.parseInt(scanner.nextLine());
        String S = scanner.nextLine();
        
        if (S.length() <= K) {
            System.out.println(S);
        } else {
            System.out.println(S.substring(0, K) + "...");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
