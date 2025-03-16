

import java.util.*;
import java.io.*;

public class codeforces_408_B{
    public static void main(String[] args) throws Exception {
        // Read the first line of input and create a HashMap to store the count of each color
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] bought = br.readLine().split("");
        HashMap<String, Integer> boughtCount = new HashMap<>();
        for (String color : bought) {
            boughtCount.put(color, boughtCount.getOrDefault(color, 0) + 1);
        }
        
        // Read the second line of input and create a HashMap to store the count of each color
        String[] made = br.readLine().split("");
        HashMap<String, Integer> madeCount = new HashMap<>();
        for (String color : made) {
            madeCount.put(color, madeCount.getOrDefault(color, 0) + 1);
        }
        
        // Initialize the result variable to store the total number of colors that can be made
        int res = 0;
        
        // Iterate over each color in the'madeCount' HashMap
        for (String color : madeCount.keySet()) {
            // Check if the color is not in the 'boughtCount' HashMap
            if (!boughtCount.containsKey(color)) {
                // If a color is not bought, print -1 and exit
                System.out.println(-1);
                return;
            }
            // Calculate the minimum of the counts of the current color in both 'boughtCount' and'madeCount'
            // and add this to the result
            res += Math.min(boughtCount.get(color), madeCount.get(color));
        }
        
        // Print the final result
        System.out.println(res);
    }
}

Translate the above Java code to C++ and end with comment "