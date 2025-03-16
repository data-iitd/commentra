import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.next();
        String ans = "Good";
        
        for (int i = 0; i < 3; i++) {
            if (a.charAt(i) == a.charAt(i + 1)) {
                ans = "Bad";
                break; // Exit the loop early if "Bad" is determined
            }
        }
        
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
