
import java.util.*;

public class Main {
  public static void main(String... args) { // 1. The main method is the entry point of the program.
    Scanner scan = new Scanner(System.in); // 2. A Scanner object is created to read input from the user.
    int r = scan.nextInt(); // 3. The user is prompted to enter an integer, which is read and stored in the variable 'r'.
    int res = (int)Math.pow(r,2); // 4. The square of the entered integer is calculated and stored in the variable 'res'.
    System.out.println(res); // 5. The result is printed to the console.
  }
}

