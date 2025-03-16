import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the first line (not used in the original code)
        String firstLine = br.readLine();
        
        // Read the second line and split it into a list of integers
        String secondLine = br.readLine();
        String[] strArr = secondLine.split(" ");
        int[] arr = new int[strArr.length];
        
        for (int i = 0; i < strArr.length; i++) {
            arr[i] = Integer.parseInt(strArr[i]);
        }
        
        // Sort the array
        Arrays.sort(arr);
        
        // Check if the smallest element is divisible by any other element
        int smallest = arr[0];
        boolean isDivisible = false;
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] % smallest == 0) {
                isDivisible = true;
                break;
            }
        }
        
        // Print the result
        System.out.println(isDivisible ? smallest : -1);
    }
}
// <END-OF-CODE>
