public class Main {
    public static void main(String[] args) {
        // Declare a string to hold the input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String str = scanner.nextLine();
        
        // Initialize a variable to hold the sum of digits
        long sum = 0;
        
        // Iterate through each character in the string
        for(char x : str.toCharArray()) {
            // Convert character to integer and add to sum
            sum += (x - '0'); // '0' is the ASCII value of '0'
        }
        
        // Check if the sum of digits is divisible by 9
        if(sum % 9 == 0) {
            // If divisible, print "Yes"
            System.out.println("Yes");
        } else {
            // If not divisible, print "No"
            System.out.println("No");
        }
    }
}
