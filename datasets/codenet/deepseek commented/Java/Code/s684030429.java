// Java program For handling Input/Output 
import java.io.*; 
import java.util.*;
import java.math.*;
//import java.awt.*;

public class Main { 
    Scanner sc;
    int max = 0,cur = 0;

    // Constructor: Initializes the scanner for input operations.
    Main(){
        try{  
            sc = new Scanner(System.in);
        }catch(Exception e){
            System.out.println(e);
        }
    }

    // Solve Method: The main logic of the program, calculating the maximum value based on given inputs.
    void solve(){
        int a = ni();
        int b = ni();

        System.out.println(Math.max(0, a-2*b));
    }

    // Utility methods for input operations.
    // input an integer from scanner
    int ni()
    {
        int a = sc.nextInt();
        return a;
    }
    // input a long from scanner
    long nl()
    {
        return sc.nextLong();
    }
    // input a float from scanner
    float nf(){
        float a = sc.nextFloat();
        return a;
    }
    // input a double from scanner
    double nd(){
        double a = sc.nextDouble();
        return a;
    }
    // input a sentence from scanner
    String ns(){
        return sc.nextLine();
    }
    // converts a string to stringtokenizer
    StringTokenizer nst(String s){
        return new StringTokenizer(s);
    }
    // input an intger array
    void ia(int a[]){
        for(int i = 0;i < a.length;i++)
            a[i] = sc.nextInt();
    }
    // input a float array
    void fa(float a[]){
        for(int i = 0;i < a.length;i++)
            a[i] = sc.nextFloat();
    }
    // input a double array
    void da(double a[]){
        for(int i = 0;i < a.length;i++)
            a[i] = sc.nextDouble();
    }
    // input a string array either with all empty input or from scanner
    void sa(String a[], boolean empty){
        if(empty)
        {
            for(int i = 0;i < a.length;i++)
            {
                a[i] = "";
            }
        }
        else
        {
            for(int i = 0;i < a.length;i++)
            {
                a[i] = ns();
            }
        }
    }
    // input two dimensional integer array
    void ida(int a[][], int n, int m)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                a[i][j] = ni();
            }
        }
    }
    // convert string to integer
    int stoi(String s){
        return Integer.parseInt(s);
    }
    // find minimum in a long array
    long lmin(long a[])
    {
        long min = Long.MAX_VALUE;
        for(int i = 0;i < a.length;i++)
        {
            if(min > a[i])
                min = a[i];
        }
        return min;
    }
    // find minimum in a integer array
    int imin(int a[])
    {
        int min = Integer.MAX_VALUE;
        for(int i = 0;i < a.length;i++)
        {
            if(min > a[i])
                min = a[i];
        }
        return min;
    }
    // check whether an element is present in an integer array by binary search
    boolean ibs(int a[], int toFind)
    {
        Arrays.sort(a);
        int min = 0;
        int max = a.length-1;
        boolean found = false;

        while(min <= max && !found)
        {
            int mid = min + (max-min)/2;
            if(a[mid] == toFind)
            {
               found = true;
            }
            else if(toFind > a[mid])
            {
                min = mid+1;
            }
            else
            {
                max = mid-1;
            }

        }
        return found;
    }

    // Main method: Entry point of the program.
    public static void main(String[] args) 
    { 
    	new Main().solve();
    }
}