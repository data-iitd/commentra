public class Main {
    public static void main(String[] args) {
        // Declare a variable to store the input string
        String s;
        
        // Read a string input from the user and store it in `s`
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        
        // Check if the first three characters of `s` are the same or if the second three characters of `s` are the same
        if (s.charAt(0) == s.charAt(1) && s.charAt(1) == s.charAt(2)) || (s.charAt(1) == s.charAt(2) && s.charAt(2) == s.charAt(3)){
            // If either condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // Otherwise, print "No"
            System.out.println("No");
        }
    }
}
