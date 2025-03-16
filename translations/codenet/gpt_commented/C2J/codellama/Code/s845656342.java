
public class Main {
  public static void main(String[] args) {
    int x; // Declare an integer variable x

    // Read an integer value from user input and store it in x
    x = Integer.parseInt(args[0]);

    // Check if the value of x is equal to 1
    if(x == 1) 
      System.out.println("0"); // If x is 1, print "0"
    else 
      System.out.println("1"); // If x is not 1, print "1"
  }
}

