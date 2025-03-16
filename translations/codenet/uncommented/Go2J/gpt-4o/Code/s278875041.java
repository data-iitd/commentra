import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.next();
        
        String tmp = a.replace("1", "0");
        String b = tmp.replace("9", "1");
        String ans = b.replace("0", "9");
        
        System.out.println(ans);
    }
}

// <END-OF-CODE>
