public class Main {
    public static void main(String[] args) {
        // Declare a string variable to hold the input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String W = scanner.next();
        
        // Sort the characters in the string in ascending order
        char[] charArray = W.toCharArray();
        java.util.Arrays.sort(charArray);
        W = new String(charArray);

        // Iterate through the sorted string, checking pairs of characters
        for (int i = 0; i < W.length(); i += 2) {
            // Check if the current character is not equal to the next character
            if (i + 1 >= W.length() || W.charAt(i) != W.charAt(i + 1)) {
                // If they are not equal, print "No" and exit the program
                System.out.println("No");
                return;
            }
        }
        
        // If all pairs are equal, print "Yes"
        System.out.println("Yes");
    }
}
