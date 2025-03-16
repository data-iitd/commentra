public class Main {
    public static void main(String[] args) {
        // Declare a string variable to hold the input
        String str = "";
        // Read input string from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        str = scanner.nextLine();
        
        // Initialize variables to track the maximum length of valid characters and the current count
        int max = 0, cnt = 0;
        
        // Iterate through each character in the input string
        for (char sc : str.toCharArray()) {
            // Check if the character is one of the valid DNA bases
            if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
                // Increment the count for consecutive valid characters
                cnt++;
            } else {
                // Reset the count if an invalid character is encountered
                cnt = 0;
            }
            // Update the maximum length if the current count exceeds the previous maximum
            max = Math.max(max, cnt);
        }
        
        // Output the maximum length of consecutive valid characters found
        System.out.println(max);
    }
}
