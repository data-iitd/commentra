
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
public static void main(String[] args) {
  // Initialize Scanner to read input from the standard input stream
  Scanner in = new Scanner(System.in);
  
  // Read the size of the array from the input
  int[] num = new int[in.nextInt()];
  
  // Initialize the array with values from 1 to the size of the array
  for (int i = 0; i < num.length; i++) {
    num[i] = i + 1;
  }
  
  // Read the number of swaps to be performed
  int count = in.nextInt();
  
  // Create a pattern to match pairs of digits separated by a comma
  Pattern pt = Pattern.compile("(\\d+),(\\d+)");
  
  // Initialize an array to store the indices of the elements to be swapped
  int line[] = new int[2];
  
  // Perform the specified number of swaps
  for (int i = 0; i < count; i++) {
    // Read the next input line and match it against the pattern
    String next = in.next(pt);
    
    // Parse the matched groups into integers and adjust for zero-based indexing
    for (int j = 0; j < line.length; j++) {
      Matcher matcher = pt.matcher(next);
      matcher.matches();
      line[j] = Integer.parseInt(matcher.group(j + 1)) - 1;
    }
    
    // Swap the elements at the specified indices
    int change = num[line[0]];
    num[line[0]] = num[line[1]];
    num[line[1]] = change;
  }
  
  // Output the final state of the array
  for (int i = 0; i < num.length; i++) {
    System.out.println(num[i]);
  }
}
}