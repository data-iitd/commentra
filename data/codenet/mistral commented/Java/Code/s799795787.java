
import java.util.*;

public class Main {
    public static void main(String[] args){
        // Initialize Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);

        // Read the number of strings to be read from the console
        int n = sc.nextInt();

        // Create an array of strings with the given size
        String array[] = new String[n];

        // Initialize two counters: one for counting the number of unique strings, and another for counting the number of occurrences of each unique string
        int cnt = 0;
        int cnt2 = 0;

        // Read strings from the console and store them in the array
        for(int i =0; i<n;i++){
            // Read the next string from the console and store it in the array
            array[i] = sc.next();
        }

        // Sort the strings in the array in ascending order
        Arrays.sort(array);

        // Initialize a string variable to store the first string in the array
        String a = array[0];

        // Initialize a counter for counting the number of occurrences of each unique string
        for(int i=0;i<n;i++){
            // Compare the current string in the array with the first string
            if(a.equals(array[i])){
                // If they are equal, increment the counter for the number of occurrences of this unique string
                cnt2++;
            }else{
                // If they are not equal, increment the counter for the number of unique strings and reset the counter for the number of occurrences to zero
                cnt++;
                cnt2 = 0;
            }
            // Update the value of the string variable to the next string in the array
            a = array[i];
        }

        // Print the number of unique strings in the array
        System.out.println(cnt);
    }
}