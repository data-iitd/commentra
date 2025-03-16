
import java.util.*;
public class Main {
    public static void main(String[] args){
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        // Read the number of strings
        int n = sc.nextInt();
        // Create an array to store the strings
        String array[] = new String[n];
        // Initialize counters for counting distinct strings
        int cnt = 0;
        int cnt2=0;

        // Read n strings from the user and store them in the array
        for(int i =0; i<n;i++){
            array[i] = sc.next();
        }

        // Sort the array of strings
        Arrays.sort(array);

        // Initialize the first string to compare with others
        String a = array[0];
        // Increment the counter for the first string
        cnt++;
        // Iterate through the array to count distinct strings
        for(int i=0;i<n;i++){
        
            if(a.equals(array[i])){
                // Do nothing if the current string is the same as the previous one
            }else{
                // Increment the counter when a new distinct string is found
                cnt++;
            }
             // Update the string to compare with the next one
             a = array[i];
       }
       // Print the number of distinct strings
       System.out.println(cnt);
    }
}

