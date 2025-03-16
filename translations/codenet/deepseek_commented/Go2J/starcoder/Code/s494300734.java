import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    sc.close();
    
    String ans = "No";
    
    // Check if 'C' appears before the last occurrence of 'F' in the string s
    if (s.indexOf('C') < s.lastIndexOf('F')) {
      ans = "Yes";
    }
    
    // Check if 'C' does not appear in the string s
    if (s.indexOf('C') < 0) {
      ans = "No";
    }
    
    System.out.println(ans);
  }
}

