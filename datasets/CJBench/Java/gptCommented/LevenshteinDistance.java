import java.util.Scanner;
import java.util.stream.IntStream;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Method to calculate the Levenshtein distance using a naive approach
    public static int naiveMain(final String string1, final String string2) {
        // Initialize the distance matrix
        int[][] distanceMatrix = IntStream.rangeClosed(0, string1.length())
                .mapToObj(i -> IntStream.rangeClosed(0, string2.length())
                        .map(j -> (i == 0) ? j : (j == 0) ? i : 0).toArray())
                .toArray(int[][]::new);
        
        // Fill the distance matrix based on the Levenshtein distance algorithm
        IntStream.range(1, string1.length() + 1).forEach(i -> IntStream.range(1, string2.length() + 1).forEach(j -> {
            // Determine the cost of substitution
            final int cost = (string1.charAt(i - 1) == string2.charAt(j - 1)) ? 0 : 1;
            // Calculate the minimum cost for the current cell in the matrix
            distanceMatrix[i][j] = Math.min(distanceMatrix[i - 1][j - 1] + cost,
                    Math.min(distanceMatrix[i][j - 1] + 1, distanceMatrix[i - 1][j] + 1));
        }));
        
        // Return the computed Levenshtein distance
        return distanceMatrix[string1.length()][string2.length()];
    }

    // Method to calculate the Levenshtein distance using an optimized approach
    public static int optimizedMain(final String string1, final String string2) {
        // If the first string is empty, return the length of the second string
        if (string1.isEmpty()) {
            return string2.length();
        }
        
        // Initialize the previous distance array
        int[] previousDistance = IntStream.rangeClosed(0, string1.length()).toArray();
        
        // Iterate through each character of the second string
        for (int j = 1; j <= string2.length(); j++) {
            // Store the cost of the previous substitution
            int prevSubstitutionCost = previousDistance[0];
            // Update the first element of the previous distance array
            previousDistance[0] = j;
            
            // Iterate through each character of the first string
            for (int i = 1; i <= string1.length(); i++) {
                // Calculate costs for deletion, insertion, and substitution
                final int deletionCost = previousDistance[i] + 1;
                final int insertionCost = previousDistance[i - 1] + 1;
                final int substitutionCost = (string1.charAt(i - 1) == string2.charAt(j - 1)) ? prevSubstitutionCost : prevSubstitutionCost + 1;
                
                // Update the previous substitution cost
                prevSubstitutionCost = previousDistance[i];
                
                // Update the current cell in the previous distance array with the minimum cost
                previousDistance[i] = Math.min(deletionCost, Math.min(insertionCost, substitutionCost));
            }
        }
        
        // Return the computed Levenshtein distance
        return previousDistance[string1.length()];
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the first string from user input
        String string1 = scanner.nextLine();
        // Read the second string from user input
        String string2 = scanner.nextLine();
        // Read the method choice from user input
        int method = scanner.nextInt();
        int distance;
        
        // Choose the method to calculate distance based on user input
        if (method == 1) {
            distance = naiveMain(string1, string2);
        } else {
            distance = optimizedMain(string1, string2);
        }
        
        // Output the calculated Levenshtein distance
        System.out.println("The Levenshtein distance between the two strings is: " + distance);
    }
}
