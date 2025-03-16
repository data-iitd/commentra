public class Main {
    public static void main(String[] args) {
        // Declare a character array 'c' to store the input string and 'ans' to store the result
        char[] c = new char[11];
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read a string input from the user
        c = scanner.nextLine().toCharArray();
        
        // Declare a StringBuilder 'ans' to store the result
        StringBuilder ans = new StringBuilder();
        
        // Iterate through each character of the input string until the null terminator is encountered
        for (char ch : c) {
            // If the current character is not 'B', append it to the 'ans' string
            if (ch != 'B') {
                ans.append(ch);
            } 
            // If the current character is 'B', remove the last character from 'ans' (if it exists)
            else {
                if (ans.length() > 0) {
                    ans.deleteCharAt(ans.length() - 1);
                }
            }
        }
        
        // Print the resulting string after processing the input
        System.out.println(ans.toString());
    }
}
