import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int maxsize=0;
        int maxcnt=0;
        int ans_num; // Index of the longest string
        int ans_num2; // Index of the most frequent string
        Vector<String> str_v = new Vector<String>(); // Vector to store input strings
        
        // Variable to read input strings
        String in;
        while(in.hasNextLine()){
            in = in.nextLine();
            str_v.add(in); // Store the input string in the vector
            if(maxsize < in.length()){ // Check if the current string is the longest so far
                maxsize = in.length(); // Update the length of the longest string
                ans_num = str_v.size()-1; // Store the index of the longest string
            }
        }
        
        // Count occurrences of each string and find the most frequent string
        for(int i=0;i<str_v.size();i++){
            int cnt=0;
            for(int j=0;j<str_v.size();j++){
                if(str_v.get(i).equals(str_v.get(j))) cnt++; // Count occurrences of the current string
            }
            if(maxcnt < cnt){ // Check if the current string is the most frequent so far
                maxcnt = cnt; // Update the count of the most frequent string
                ans_num2 = i; // Store the index of the most frequent string
            }
        }
        
        // Output the most frequent and the longest string
        System.out.println(str_v.get(ans_num2) + " " + str_v.get(ans_num));
    }
}

