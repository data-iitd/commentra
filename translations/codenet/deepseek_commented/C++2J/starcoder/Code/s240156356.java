import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String str1 = sc.next();
    String str2 = sc.next();

    // Sort the first string in ascending order
    char[] ch1 = str1.toCharArray();
    Arrays.sort(ch1);
    str1 = new String(ch1);

    // Sort the second string in descending order
    char[] ch2 = str2.toCharArray();
    Arrays.sort(ch2);
    Arrays.sort(ch2, Collections.reverseOrder());
    str2 = new String(ch2);

    // Determine the loop limit based on the length of the shorter string
    int loop = str1.length() > str2.length()? str2.length() : str1.length();
    boolean flag = false;

    // Compare characters of the two sorted strings
    for(int i = 0; loop > i; i++){
      char ch1 = str1.charAt(i);
      char ch2 = str2.charAt(i);

      // If characters match, continue to the next character
      if(ch1 == ch2){
        if(loop == i + 1 && str1.length() < str2.length()){
          flag = true;
          break;
        }else{
          continue;
        }
      }else{
        // If characters do not match, check if the character from the second string is greater
        if(ch2 > ch1){
          flag = true;
          break;
        }else{
          break;
        }
      }
    }

    // Check the flag and print the result
    if(flag){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}

