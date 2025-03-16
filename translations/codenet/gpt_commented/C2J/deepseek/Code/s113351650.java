public class Main {
  
  public static void main(String[] args) {
    
    // Declare an integer variable 'x' to store user input
    int x;
    
    // Create a Scanner object to read input from the user
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    
    // Prompt the user for input and read an integer value into 'x'
    x = scanner.nextInt();
    
    // Check if the input value is 0
    if (x == 0) 
      // If true, print "1" to the output
      System.out.println("1");
    
    // Check if the input value is 1
    if (x == 1) 
      // If true, print "0" to the output
      System.out.println("0");
    
    // Return 0 to indicate successful completion of the program
    // Note: In Java, the main method returns an int, but for simplicity, we can use System.exit(0);
    System.exit(0);
    
  }
  
}
