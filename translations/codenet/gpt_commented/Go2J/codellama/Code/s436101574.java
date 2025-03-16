
package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Ensure the buffered writer flushes its content before exiting
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            // Read the first string of runes (s)
            String s = br.readLine();
            // Read the second string of runes (t)
            String t = br.readLine();

            // Initialize a slice to hold possible answers
            List<String> ans = new ArrayList<>();

            // Iterate through the first string to find occurrences of the second string
            for (int i = 0; i < s.length() - t.length() + 1; i++) {
                boolean f = true; // Flag to check if the current position is valid
                char[] ss = s.toCharArray(); // Create a copy of the original string

                // Check if the substring of s can match t
                for (int j = 0; j < t.length(); j++) {
                    // If characters do not match and are not '?', set flag to false
                    if (ss[i + j] != t.charAt(j) && ss[i + j] != '?') {
                        f = false;
                        break;
                    } else {
                        // Replace '?' with the corresponding character from t
                        ss[i + j] = t.charAt(j);
                    }
                }
                // If the substring matched, replace remaining '?' with 'a' and store the result
                if (f) {
                    ans.add(new String(ss).replace("?", "a"));
                }
            }

            // Sort the possible answers
            ans.sort(String::compareTo);

            // Output the result: either the first valid answer or "UNRESTORABLE"
            if (ans.isEmpty()) {
                bw.write("UNRESTORABLE");
            } else {
                bw.write(ans.get(0));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

