
import java.util.Scanner;
import java.util.stream.IntStream;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }

    public static int naiveMain(final String string1, final String string2) {
        int[][] distanceMatrix = initializeDistanceMatrix(string1, string2); // Initialize the distance matrix
        populateDistanceMatrix(distanceMatrix, string1, string2); // Populate the distance matrix with costs
        return getDistance(distanceMatrix); // Return the final distance
    }

    private static int[][] initializeDistanceMatrix(final String string1, final String string2) {
        int rows = string1.length() + 1;
        int columns = string2.length() + 1;
        return IntStream.rangeClosed(0, rows - 1)
                .mapToObj(i -> IntStream.rangeClosed(0, columns - 1)
                        .map(j -> (i == 0) ? j : (j == 0) ? i : 0).toArray())
                .toArray(int[][]::new);
    }

    private static void populateDistanceMatrix(final int[][] distanceMatrix, final String string1, final String string2) {
        IntStream.range(1, string1.length() + 1).forEach(i -> IntStream.range(1, string2.length() + 1).forEach(j -> {
            final int cost = (string1.charAt(i - 1) == string2.charAt(j - 1)) ? 0 : 1;
            setDistance(distanceMatrix, i, j, cost);
        }));
    }

    private static void setDistance(final int[][] distanceMatrix, final int i, final int j, final int cost) {
        distanceMatrix[i][j] = calculateMinimumDistance(distanceMatrix[i - 1][j - 1], distanceMatrix[i][j - 1], distanceMatrix[i - 1][j], cost);
    }

    private static int calculateMinimumDistance(final int a, final int b, final int c, final int cost) {
        return Math.min(a + cost, Math.min(b + 1, c + 1));
    }

    public static int optimizedMain(final String string1, final String string2) {
        if (string1.isEmpty()) {
            return lengthOfString2(string2);
        }
        int[] previousDistance = new int[string1.length() + 1]; // Initialize previous distances array
        for (int j = 1; j <= string2.length(); j++) {
            int prevSubstitutionCost = previousDistance[0];
            previousDistance[0] = j;
            for (int i = 1; i <= string1.length(); i++) {
                final int deletionCost = previousDistance[i] + 1;
                final int insertionCost = previousDistance[i - 1] + 1;
                final int substitutionCost = (string1.charAt(i - 1) == string2.charAt(j - 1)) ? prevSubstitutionCost : prevSubstitutionCost + 1;
                updatePreviousDistance(previousDistance, i, j, deletionCost, insertionCost, substitutionCost);
            }
        }
        return previousDistance[string1.length()];
    }

    private static void updatePreviousDistance(final int[] previousDistance, final int i, final int j, final int deletionCost, final int insertionCost, final int substitutionCost) {
        previousDistance[i] = Math.min(deletionCost, Math.min(insertionCost, substitutionCost));
    }

    private static int lengthOfString2(final String string2) {
        return string2.length();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize the scanner for reading input
        String string1 = scanner.nextLine(); // Read the first string from the input
        String string2 = scanner.nextLine(); // Read the second string from the input
        int method = scanner.nextInt(); // Read the method number from the input
        int distance;
        if (method == 1) {
            distance = naiveMain(string1, string2); // Call the naive method if method number is 1
        } else {
            distance = optimizedMain(string1, string2); // Call the optimized method if method number is other than 1
        }
        System.out.println("The Levenshtein distance between the two strings is: " + distance); // Print the result to the console