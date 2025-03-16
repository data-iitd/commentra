import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two strings from the user
        String str = scanner.next();
        String p = scanner.next();
        
        // Duplicate and concatenate the string
        String tmp = str;
        str += tmp;
        
        // Calculate the lengths of the strings
        int slen = str.length();
        int plen = p.length();
        
        // Initialize flag to 0 (not found)
        boolean flag = false;
        
        // Check if the pattern exists in the concatenated string
        for (int i = 0; i <= slen - plen; i++) {
            if (str.substring(i, i + plen).equals(p)) {
                flag = true;
                break; // No need to continue if we found a match
            }
        }
        
        // Output the result
        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
