public class Main {
    public static void main(String[] args) {
        // Declare variables for input and a map to store string entries
        int n; // Number of commands to process
        String com, str; // Strings to hold command and string inputs
        java.util.Map<String, Boolean> T = new java.util.HashMap<>(); // Map to track the presence of strings (true if present)

        // Read the number of commands from input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        
        // Loop through each command
        for (int i = 0; i < n; i++) {
            // Read the command and the associated string
            com = scanner.next();
            str = scanner.next();
            
            // Check if the command is 'insert' (indicated by the first character being 'i')
            if (com.equals("insert")) {
                // Insert the string into the map with a value of true
                T.put(str, true);
            } else {
                // If the command is not 'insert', check if the string exists in the map
                if (T.containsKey(str) && T.get(str)) {
                    // If the string exists, print "yes"
                    System.out.println("yes");
                } else {
                    // If the string does not exist, print "no"
                    System.out.println("no");
                }
            }
        }
        
        // Return 0 to indicate successful execution
    }
}
