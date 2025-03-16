import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        // Declare two string variables and read input from the user
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.next();
        String str2 = scanner.next();

        // Sort the characters in string str1 in ascending order and in string str2 in descending order
        str1 = sortString(str1);
        str2 = sortString(str2);

        // Determine the length of the shorter string to be used as the loop limit
        int loop = str1.length() > str2.length() ? str2.length() : str1.length();

        // Initialize a boolean flag to false
        boolean flag = false;

        // Loop through the characters in both strings up to the length of the shorter string
        for(int i = 0; loop > i; i++){
            // Get the characters at the current index in both strings
            char ch1 = str1.charAt(i);
            char ch2 = str2.charAt(i);

            // Check if the characters are equal. If they are, check if we have reached the end of the strings
            if(ch1 == ch2){
                // If we have reached the end of str1 and str2 is not empty, set the flag to true and break out of the loop
                if(loop == i + 1 && str1.length() < str2.length()){
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

    public static String sortString(String str){
        char[] charArray = str.toCharArray();
        for(int i = 0; i < charArray.length; i++){
            for(int j = i + 1; j < charArray.length; j++){
                if(charArray[i] > charArray[j]){
                    char temp = charArray[i];
                    charArray[i] = charArray[j];
                    charArray[j] = temp;
                }
            }
        }
        return new String(charArray);
    }
}

