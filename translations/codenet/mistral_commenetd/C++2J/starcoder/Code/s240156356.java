import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Declare two string variables and read input from the user
    Scanner sc = new Scanner(System.in);
    String str1 = sc.next();
    String str2 = sc.next();

    // Sort the characters in string str1 in ascending order and in string str2 in descending order
    char[] arr1 = str1.toCharArray();
    char[] arr2 = str2.toCharArray();
    Arrays.sort(arr1);
    Arrays.sort(arr2, Collections.reverseOrder());

    // Determine the length of the shorter string to be used as the loop limit
    int loop = arr1.length > arr2.length? arr2.length : arr1.length;

    // Initialize a boolean flag to false
    boolean flag = false;

    // Loop through the characters in both strings up to the length of the shorter string
    for(int i = 0; loop > i; i++){
      // Get the characters at the current index in both strings
      char ch1 = arr1[i];
      char ch2 = arr2[i];

      // Check if the characters are equal. If they are, check if we have reached the end of the strings
      if(ch1 == ch2){
        // If we have reached the end of str1 and str2 is not empty, set the flag to true and break out of the loop
        if(loop == i + 1 && arr1.length < arr2.length){
          flag = true;
          break;
        }else{
          // If we have not reached the end of the strings, continue to the next iteration of the loop
          continue;
        }
      }else{
        // If the characters are not equal, compare their ASCII values. If ch2 is greater than ch1, set the flag to true and break out of the loop
        if(ch2 > ch1){
          flag = true;
          break;
        }else{
          // If ch1 is greater than or equal to ch2, continue to the next iteration of the loop
          break;
        }
      }
    }

    // If the flag is true, print "Yes" to the console. Otherwise, print "No" to the console
    if(flag){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
