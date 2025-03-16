

import java.util.*;

public class s941927127{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String W = sc.next();
    char[] W_char = W.toCharArray();
    Arrays.sort(W_char);
    boolean is_pair = true;
    for (int i = 0; i < W_char.length; i += 2) {
      if (W_char[i]!= W_char[i + 1]) {
        is_pair = false;
        break;
      }
    }
    if (is_pair) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}

