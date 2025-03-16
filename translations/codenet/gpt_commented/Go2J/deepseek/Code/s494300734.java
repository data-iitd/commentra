public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        String s = System.console().readLine();
        
        // Initialize the answer variable with "No"
        String ans = "No";
        
        // Check if the first occurrence of 'C' is before the last occurrence of 'F'
        int firstC = s.indexOf('C');
        int lastF = s.lastIndexOf('F');
        if (firstC != -1 && firstC < lastF) {
            // If true, set the answer to "Yes"
            ans = "Yes";
        }
        
        // Print the final answer
        System.out.println(ans);
    }
}
