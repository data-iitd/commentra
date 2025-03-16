import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the integer n and the list of strings s from standard input
        int n = Integer.parseInt(scanner.nextLine());
        String[] s = scanner.nextLine().split(" ");
        
        // Create a HashMap object w from the list s
        Map<String, Integer> w = new HashMap<>();
        for (String str : s) {
            w.put(str, w.getOrDefault(str, 0) + 1);
        }
        
        // Reverse the list s
        StringBuilder sb = new StringBuilder();
        for (int i = s.length - 1; i >= 0; i--) {
            sb.append(s[i]).append(" ");
        }
        String[] reversedS = sb.toString().trim().split(" ");
        
        // Initialize two variables c and a to -1 and 0 respectively
        int c = -1;
        String a = "";
        
        // Iterate over the items in the HashMap w
        int maxCount = 0;
        for (String key : w.keySet()) {
            if (w.get(key) > maxCount) {
                maxCount = w.get(key);
            }
        }
        
        for (String key : w.keySet()) {
            if (w.get(key) == maxCount) {
                // Check if the index of the key in the reversed list s is greater than the current value of c
                int currentIndex = java.util.Arrays.asList(reversedS).indexOf(key);
                if (currentIndex > c) {
                    // Update the value of a to the current key and update the value of c to the index of the current key in the reversed list s
                    a = key;
                    c = currentIndex;
                }
            }
        }
        
        // Print the value of a
        System.out.println(a);
    }
}
