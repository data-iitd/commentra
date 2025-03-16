import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        s = s.replaceAll("dream", "D");
        s = s.replaceAll("erase", "E");
        s = s.replaceAll("Der", "");
        s = s.replaceAll("Er", "");
        s = s.replaceAll("D", "");
        s = s.replaceAll("E", "");
        s = s.trim();

        if (s.isEmpty()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
