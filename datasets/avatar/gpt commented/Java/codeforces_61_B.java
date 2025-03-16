import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner in = new Scanner(System.in); 
        
        // Read three words from the input, remove non-alphabetic characters, and convert them to lowercase
        String word1 = in.nextLine().replaceAll("[^a-zA-Z]", "").toLowerCase(); 
        String word2 = in.nextLine().replaceAll("[^a-zA-Z]", "").toLowerCase(); 
        String word3 = in.nextLine().replaceAll("[^a-zA-Z]", "").toLowerCase(); 
        
        // Generate all possible permutations of the three words
        String perm1 = word1 + word2 + word3; 
        String perm2 = word1 + word3 + word2; 
        String perm3 = word2 + word1 + word3; 
        String perm4 = word2 + word3 + word1; 
        String perm5 = word3 + word2 + word1; 
        String perm6 = word3 + word1 + word2; 
        
        // Read the number of students (test cases)
        int students = in.nextInt(); 
        in.nextLine(); // Consume the newline character after the integer input
        
        // Loop through each student's test case
        for (int i = 0; i < students; i++) { 
            // Read the test case input, remove non-alphabetic characters, and convert to lowercase
            String testCase = in.nextLine().replaceAll("[^a-zA-Z]", "").toLowerCase(); 
            
            // Check if the test case matches any of the generated permutations
            if (testCase.equals(perm1) || testCase.equals(perm2) || 
                testCase.equals(perm3) || testCase.equals(perm4) || 
                testCase.equals(perm5) || testCase.equals(perm6)) { 
                // If it matches, print "ACC" (Accepted)
                System.out.println("ACC"); 
            } else { 
                // If it doesn't match, print "WA" (Wrong Answer)
                System.out.println("WA"); 
            } 
        } 
    } 
}
