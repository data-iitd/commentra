// Java program For handling Input/Output 
import java.io.*; 
import java.util.*;
import java.math.*;
//import java.awt.*;

public class Main { 
    Scanner sc; // Initialize Scanner object
    int max = 0, cur = 0; // Initialize max and cur variables

    // Function to solve the problem
    void solve(){
        // Read two integers from the user
        int a = ni();
        int b = ni();

        // Print the maximum value of (a-2*b) or 0
        System.out.println(Math.max(0, a-2*b));
    }

    // Constructor
    Main(){
        try{  
            sc = new Scanner(System.in); // Initialize Scanner object in constructor
        }catch(Exception e){
            System.out.println(e); // Print exception message if any
        }
    }

    // Main method
    public static void main(String[] args) 
    { 
        // Create an instance of Main class and call solve method
        new Main().solve();
    }

    // Utility methods

    // Input an integer from scanner
    int ni()
    {
        int a = sc.nextInt(); // Read an integer from the user
        return a; // Return the integer
    }

    // Input a long from scanner
    long nl()
    {
        return sc.nextLong(); // Read a long from the user
    }

    // Input a float from scanner
    float nf(){
        return sc.nextFloat(); // Read a float from the user
    }

    // Input a double from scanner
    double nd(){
        return sc.nextDouble(); // Read a double from the user
    }

    // Input a sentence from scanner
    String ns(){
        return sc.nextLine(); // Read a sentence from the user
    }

    // Convert a String to StringTokenizer
    StringTokenizer nst(String s){
        return new StringTokenizer(s); // Create a StringTokenizer object
    }

    // Input an integer array
    void ia(int a[]){
        for(int i = 0;i < a.length;i++) // Iterate through the array
            a[i] = sc.nextInt(); // Read an integer from the user and assign it to the array
    }

    // Input a long array
    void la(long a[]){
        for(int i = 0;i < a.length;i++) // Iterate through the array
            a[i] = sc.nextLong(); // Read a long from the user and assign it to the array
    }

    // Input a float array
    void fa(float a[]){
        for(int i = 0;i < a.length;i++) // Iterate through the array
            a[i] = sc.nextFloat(); // Read a float from the user and assign it to the array
    }

    // Input a double array
    void da(double a[]){
        for(int i = 0;i < a.length;i++) // Iterate through the array
            a[i] = sc.nextDouble(); // Read a double from the user and assign it to the array
    }

    // Input a string array either with all empty input or from scanner
    void sa(String a[], boolean empty){
        if(empty) // If empty input is required
        {
            for(int i = 0;i < a.length;i++) // Iterate through the array
                a[i] = ""; // Assign an empty string to each element
        }
        else // Else read strings from the user and assign them to the array
        {
            for(int i = 0;i < a.length;i++)
                a[i] = ns();
        }
    }

    // Input two dimensional integer array
    void ida(int a[][], int n, int m)
    {
        for(int i = 0;i < n;i++) // Iterate through rows
        {
            for(int j = 0;j < m;j++) // Iterate through columns
                a[i][j] = ni(); // Read an integer from the user and assign it to the array
        }
    }

    // Input two dimentional long array
    void lda(long a[][], int n, int m)
    {
        for(int i = 0;i < n;i++) // Iterate through rows
        {
            for(int j = 0;j < m;j++) // Iterate through columns
                a[i][j] = nl(); // Read a long from the user and assign it to the array
        }
    }

    // Input two dimensional double array
    void dda(double a[][], int n, int m)
    {
        for(int i = 0;i < n;i++) // Iterate through rows
        {
            for(int j = 0;j < m;j++) // Iterate through columns
                a[i][j] = nd(); // Read a double from the user and assign it to the array
        }
    }

    // Convert string to integer
    int stoi(String s){
        return Integer.parseInt(s); // Parse the string to an integer
    }

    // Convert string to double
    double stod(String s){
        return Double.parseDouble(s); // Parse the string to a double
    }

    // Find minimum in a long array
    long lmin(long a[])
    {
        long min = Long.MAX_VALUE; // Initialize minimum to maximum long value
        for(int i = 0;i < a.length;i++) // Iterate through the array
        {
            if(min > a[i]) // If current element is smaller than minimum
                min = a[i]; // Update minimum
        }
        return min; // Return the minimum
    }

    // Find minimum in an integer array
    int imin(int a[])
    {
        int min = Integer.MAX_VALUE; // Initialize minimum to maximum integer value
        for(int i = 0;i < a.length;i++) // Iterate through the array
        {
            if(min > a[i]) // If current element is smaller than minimum
                min = a[i]; // Update minimum
        }
        return min; // Return the minimum
    }

    // Find maximum in a long array
    long lmax(long a[])
    {
        long max = Long.MIN_VALUE; // Initialize maximum to minimum long value
        for(int i = 0;i < a.length;i++) // Iterate through the array
        {
            if(max < a[i]) // If current element is greater than maximum
                max = a[i]; // Update maximum
        }
        return max; // Return the maximum
    }

    // Find maximum in an integer array
    int imax(int a[])
    {
        int max = Integer.MIN_VALUE; // Initialize maximum to minimum integer value
        for(int i = 0;i < a.length;i++) // Iterate through the array
        {
            if(max < a[i]) // If current element is greater than maximum
                max = a[i]; // Update maximum
        }
        return max; // Return the maximum
    }

    // Check whether an element is present in an integer array by binary search
    boolean ibs(int a[], int toFind)
    {
        Arrays.sort(a); // Sort the array
        int min = 0;
        int max = a.length-1;
        boolean found = false;

        while(min <= max && !found) // Continue searching until the element is found or the array is exhausted
        {
            int mid = min + (max-min)/2; // Calculate the middle index
            if(a[mid] == toFind) // If the middle element matches the target
                found = true; // Set found flag
            else if(toFind > a[mid]) // If the target is greater than the middle element
                min = mid+1; // Search in the right half of the array
            else // If the target is smaller than the middle element
                max = mid-1; // Search in the left half of the array
        }
        return found; // Return the found flag
    }

    // Check whether an element is present in a long array
    boolean lbs(long a[], long toFind)
    {
        Arrays.sort(a); // Sort the array
        int min = 0;
        int max = a.length-1;
        boolean found = false;

        while(min <= max && !found) // Continue searching until the element is found or the array is exhausted
        {
            int mid = min + (max-min)/2; // Calculate the middle index
            if(a[mid] == toFind) // If the middle element matches the target
                found = true; // Set found flag
            else if(toFind > a[mid]) // If the target is greater than the middle element
                min = mid+1; // Search in the right half of the array
            else // If the target is smaller than the middle element
                max = mid-1; // Search in the left half of the array
        }
        return found; // Return the found flag
    }

    int stb(String s)
    {
        int sum = 0; // Initialize sum to zero
        int k = 0; // Initialize carry to zero

        for(int i = s.length()-1;i >= 0;i--) // Iterate through the string from right to left
        {
            int digit = Character.isDigit(s.charAt(i)) // Check if the character is a digit
                        ? Character.isDigit(s.charAt(i))-'0' // If yes, convert it to an integer and add to sum
                        : stoi(String.valueOf(s.charAt(i)))*Math.pow(2, k++); // If no, convert it to an integer and add it to sum multiplied by 2^carry

            sum += digit; // Add the digit to sum
        }
        return sum; // Return the sum
    }

}