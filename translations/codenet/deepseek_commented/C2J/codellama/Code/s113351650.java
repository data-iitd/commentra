
public class Main {
  public static void main(String[] args) {
    // Declare an integer variable to store the input value.
    int x;

    // Read an integer input from the user and store it in the variable x.
    x = Integer.parseInt(args[0]);

    // Check the value of x and print 1 or 0 based on the value of x.
    if (x == 0) {
      System.out.println("1");
    }
    if (x == 1) {
      System.out.println("0");
    }
  }
}

