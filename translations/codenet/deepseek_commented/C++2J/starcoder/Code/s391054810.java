import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Read the input from the standard input (stdin)
    Scanner stdin = new Scanner(System.in);
    
    // Read the values of the variables h, w, hh, ww from stdin
    int h = stdin.nextInt();
    int w = stdin.nextInt();
    int hh = stdin.nextInt();
    int ww = stdin.nextInt();
    
    // Output the result to the standard output (stdout)
    System.out.println((h-hh) * (w-ww));
    
    // Close the input stream
    stdin.close();
  }
}

