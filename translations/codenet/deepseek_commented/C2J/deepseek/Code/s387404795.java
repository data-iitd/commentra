public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
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
            if (str.substring(i, i + plen).equals(p)) flag = true;
        }
        
        // Output the result
        if (flag) System.out.println("Yes");
        else System.out.println("No");
    }
}
