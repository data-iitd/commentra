import java.util.Scanner;
import java.util.stream.IntStream;

public final class Main {
    private Main() {
    }

    // Naive approach to calculate the Levenshtein distance between two strings
    public static int naiveMain(final String string1, final String string2) {
        // Initialize the distance matrix with dimensions (string1.length() + 1) x (string2.length() + 1)
        int[][] distanceMatrix = IntStream.rangeClosed(0, string1.length())
                .mapToObj(i -> IntStream.rangeClosed(0, string2.length())
                        .map(j -> (i == 0) ? j : (j == 0) ? i : 0).toArray())
                .toArray(int[][]::new);

        // Fill the distance matrix based on the comparison of characters in the two strings
        IntStream.range(1, string1.length() + 1).forEach(i -> IntStream.range(1, string2.length() + 1).forEach(j -> {
            final int cost = (string1.charAt(i - 1) == string2.charAt(j - 1)) ? 0 : 1;
            distanceMatrix[i][j] = Math.min(distanceMatrix[i - 1][j - 1] + cost,
                    Math.min(distanceMatrix[i][j - 1] + 1, distanceMatrix[i - 1][j] + 1));
        }));

        // Return the Levenshtein distance between the two strings
        return distanceMatrix[string1.length()][string2.length()];
    }

    // Optimized approach to calculate the Levenshtein distance between two strings
    public static int optimizedMain(final String string1, final String string2) {
        // If the first string is empty, the distance is the length of the second string
        if (string1.isEmpty()) {
            return string2.length();
        }

        // Initialize the distance array with dimensions (string1.length() + 1)
        int[] previousDistance = IntStream.rangeClosed(0, string1.length()).toArray();

        // Fill the distance array based on the comparison of characters in the two strings
        for (int j = 1; j <= string2.length(); j++) {
            int prevSubstitutionCost = previousDistance[0];
            previousDistance[0] = j;
            for (int i = 1; i <= string1.length(); i++) {
                final int deletionCost = previousDistance[i] + 1;
                final int insertionCost = previousDistance[i - 1] + 1;
                final int substitutionCost = (string1.charAt(i - 1) == string2.charAt(j - 1)) ? prevSubstitutionCost : prevSubstitutionCost + 1;
                prevSubstitutionCost = previousDistance[i];
                previousDistance[i] = Math.min(deletionCost, Math.min(insertionCost, substitutionCost));
            }
        }

        // Return the Levenshtein distance between the two strings
        return previousDistance[string1.length()];
    }

    // Main method to read input, determine the method to use, and print the Levenshtein distance
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String string1 = scanner.nextLine();
        String string2 = scanner.nextLine();
        int method = scanner.nextInt();
        int distance;
        if (method == 1) {
            distance = naiveMain(string1, string2);
        } else {
            distance = optimizedMain(string1, string2);
        }
        System.out.println("The Levenshtein distance between the two strings is: " + distance);
    }
}
