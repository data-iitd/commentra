import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String str = scanner.next();
        String p = scanner.next();
        
        String tmp = str;
        str += tmp; // Concatenate str with itself
        
        int slen = str.length();
        int plen = p.length();
        
        boolean flag = false;
        for (int i = 0; i <= slen - plen; i++) {
            if (str.substring(i, i + plen).equals(p)) {
                flag = true;
                break; // Exit loop if match is found
            }
        }
        
        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
