import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        
        String ans = "No";
        int firstCIndex = s.indexOf("C");
        int lastFIndex = s.lastIndexOf("F");
        
        if (firstCIndex >= 0 && firstCIndex < lastFIndex) {
            ans = "Yes";
        }
        
        System.out.println(ans);
    }
}

// <END-OF-CODE>
