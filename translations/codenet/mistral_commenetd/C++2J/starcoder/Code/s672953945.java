
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty vector 'v' of strings
        Vector<String> v = new Vector<String>();

        // Read the number of strings 'N' and their lengths 'L' from the standard input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int L = sc.nextInt();

        // Allocate memory for 'N' strings in the vector 'v'
        for(int i=0;i<N;i++){
            // Read a string's' from the standard input and push it back into the vector 'v'
            String s = sc.next();
            v.add(s);
        }

        // Sort the strings in the vector 'v' in ascending order using the'sort' function
        Collections.sort(v);

        // Iterate through the sorted strings in the vector 'v' and print each string to the standard output
        for(int i=0;i<v.size();i++){
            // Print the current string from the vector 'v' to the standard output
            System.out.print(v.get(i));
        }

        // Print a newline character at the end of the output
        System.out.println();
    }
}

