import java.util.Scanner; // Import the Scanner class for user input

class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read an integer input from the user
        int num = sc.nextInt();
        
        // Check if the input number is less than 1200
        if(num < 1200)
            // If true, print "ABC"
            System.out.println("ABC");
        else
            // If false (num is 1200 or greater), print "ARC"
            System.out.println("ARC");
    }
}
