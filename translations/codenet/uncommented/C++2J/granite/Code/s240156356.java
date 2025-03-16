
import java.util.Scanner;
import java.util.Arrays;

public class s240156356{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String str1 = scanner.next();
    String str2 = scanner.next();

    char[] ch1 = str1.toCharArray();
    char[] ch2 = str2.toCharArray();

    Arrays.sort(ch1);
    Arrays.sort(ch2);

    int loop = Math.min(ch1.length, ch2.length);
    boolean flag = false;

    for (int i = 0; loop > i; i++) {
      char ch1_i = ch1[i];
      char ch2_i = ch2[ch2.length - 1 - i];

      if (ch1_i == ch2_i) {
        if (loop == i + 1 && ch1.length < ch2.length) {
          flag = true;
          break;
        } else {
          continue;
        }
      } else {
        if (ch2_i > ch1_i) {
          flag = true;
          break;
        } else {
          break;
        }
      }
    }

    if (flag) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
