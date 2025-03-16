
import java.util.*;
import java.io.*;

public class s983388294{
    public static void main(String[] args) throws Exception {
        // Read the number of elements
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        // Initialize a list to store the input elements
        List<Integer> a = new ArrayList<>();
        int i;

        // Read n integers into the list
        String[] input = br.readLine().split(" ");
        for(i=0; i<n; i++) {
            a.add(Integer.parseInt(input[i]));
        }

        // Initialize a counter for the current expected number
        int curr=0;

        // Iterate through the list to find the longest prefix of consecutive integers starting from 1
        for(i=0; i<n; i++) {
            if(a.get(i)==curr+1) curr++; // Increment curr if the current element matches the expected value
        }

        // Check if any consecutive integers were found
        if(curr>0) {
            // Print the number of elements not in the consecutive sequence
            System.out.println(n-curr);
        }
        else {
            // If no consecutive integers were found, print -1
            System.out.println(-1);
        }
    }
}

