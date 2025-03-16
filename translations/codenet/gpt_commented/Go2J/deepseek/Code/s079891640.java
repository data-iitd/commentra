public class Main {
    public static void main(String[] args) {
        // Read input from the user and store it in the variable 's'
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        // Iterate over each character in the string 's'
        for (int i = 0; i < s.length(); i++) {
            // Check if the current character exists in the substring that follows it
            if (s.substring(i + 1).indexOf(s.charAt(i)) != -1) {
                // If the character is found in the remaining substring, print "no" and exit
                System.out.println("no");
                return;
            }
        }

        // If no duplicate characters were found, print "yes"
        System.out.println("yes");
    }
}
