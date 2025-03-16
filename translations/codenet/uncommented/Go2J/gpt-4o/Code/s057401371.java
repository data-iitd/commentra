import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        
        int d = 'a' - 'A';
        StringBuilder result = new StringBuilder();
        
        for (char r : s.toCharArray()) {
            char rr = r;
            if ('A' <= r && r <= 'Z') {
                rr = (char) (r + d);
            } else if ('a' <= r && r <= 'z') {
                rr = (char) (r - d);
            }
            result.append(rr);
        }
        
        System.out.println(result.toString());
        sc.close();
    }
}

// <END-OF-CODE>
