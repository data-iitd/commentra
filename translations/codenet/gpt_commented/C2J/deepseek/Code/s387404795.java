public class Main {
    public static void main(String[] args) {
        // Declare character arrays for input strings and temporary storage
        char[] str = new char[201];
        char[] tmp = new char[101];
        char[] p = new char[101];
        
        // Declare integer variables for string lengths and loop control
        int slen, plen;
        int i, j, flag;
        
        // Read two strings from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String inputStr = scanner.next();
        String inputP = scanner.next();
        
        // Copy the original string into a temporary variable and concatenate it with itself
        System.arraycopy(inputStr.toCharArray(), 0, str, 0, inputStr.length());
        System.arraycopy(inputStr.toCharArray(), 0, tmp, 0, inputStr.length());
        str = inputStr.concat(String.valueOf(tmp)).toCharArray();
        
        // Calculate the lengths of the concatenated string and the pattern string
        slen = str.length;
        plen = inputP.length();
        
        // Initialize a flag to indicate if the pattern is found
        flag = 0;
        
        // Loop through the concatenated string to search for the pattern
        for (i = 0; i < slen - plen; i++) {
            // Compare the substring of str with the pattern p
            if (java.util.Arrays.equals(java.util.Arrays.copyOfRange(str, i, i + plen), inputP.toCharArray())) 
                flag = 1; // Set flag if a match is found
        }
        
        // Output "Yes" if the pattern was found, otherwise output "No"
        if (flag != 0) 
            System.out.println("Yes");
        else 
            System.out.println("No");
    }
}
