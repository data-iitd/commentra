public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        String a = System.console().readLine();
        
        // Replace all occurrences of '1' with '0' in the input string
        String tmp = a.replace('1', '0');
        
        // Replace all occurrences of '9' with '1' in the modified string
        String b = tmp.replace('9', '1');
        
        // Replace all occurrences of '0' with '9' in the second modified string
        String ans = b.replace('0', '9');
        
        // Print the final transformed string
        System.out.println(ans);
    }
}
