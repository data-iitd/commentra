
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Generates all permutations of a given string
    public static List<String> permutation(List<String> list, String target, String ans) {
        if (target.length() <= 1) {
            list.add(ans + target);
        } else {
            for (int i = 0; i < target.length(); i++) {
                permutation(list, target.substring(0, i) + target.substring(i + 1), ans + target.charAt(i));
            }
        }
        return list;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of strings
        Integer n = Integer.parseInt(scanner.next());
        // Initialize a 2D array to store the input strings
        String[][] line = new String[2][1];
        for (int i = 0; i < 2; i++) {
            Arrays.fill(line[i], "");
            // Read n strings and concatenate them
            for (int j = 0; j < n; j++) {
                line[i][0] += scanner.next();
            }
        }
        // Generate the number string for permutations
        String number = "";
        for (int i = 1; i <= n; i++) {
            number += i;
        }
        // Create a list to store permutations
        List<String> listA = new ArrayList<>();
        // Generate all permutations of the number string
        permutation(listA, number, "");
        // Initialize sum to calculate the result
        int sum = 0;
        // Compare permutations with input strings and calculate the sum
        for (int j = 0; j < line.length; j++) {
            for (int i = 0; i < listA.size(); i++) {
                if (listA.get(i).equals(line[j][0])) {
                    if (sum == 0) {
                        sum += i;
                    } else {
                        sum -= i;
                    }
                }
            }
        }
        // Print the absolute value of the sum
        System.out.println(Math.abs(sum));
    }
}

