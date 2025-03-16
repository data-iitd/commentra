
import java.util.Scanner;
import java.util.stream.IntStream;
public final class LevenshteinDistance {
    private LevenshteinDistance() {
    }
    public static int naiveLevenshteinDistance(final String string1, final String string2) {
        int[][] distanceMatrix = IntStream.rangeClosed(0, string1.length())
                .mapToObj(i -> IntStream.rangeClosed(0, string2.length())
                        .map(j -> (i == 0) ? j : (j == 0) ? i : 0).toArray())
                .toArray(int[][]::new);
        IntStream.range(1, string1.length() + 1).forEach(i -> IntStream.range(1, string2.length() + 1).forEach(j -> {
            final int cost = (string1.charAt(i - 1) == string2.charAt(j - 1)) ? 0 : 1;
            distanceMatrix[i][j] = Math.min(distanceMatrix[i - 1][j - 1] + cost,
                    Math.min(distanceMatrix[i][j - 1] + 1, distanceMatrix[i - 1][j] + 1));
        }));
        return distanceMatrix[string1.length()][string2.length()];
    }
    public static int optimizedLevenshteinDistance(final String string1, final String string2) {
        if (string1.isEmpty()) {
            return string2.length();
        }
        int[] previousDistance = IntStream.rangeClosed(0, string1.length()).toArray();
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
        return previousDistance[string1.length()];
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String string1 = scanner.nextLine();
        String string2 = scanner.nextLine();
        int method = scanner.nextInt();
        int distance;
        if (method == 1) {
            distance = naiveLevenshteinDistance(string1, string2);
        } else {
            distance = optimizedLevenshteinDistance(string1, string2);
        }
        System.out.println("The Levenshtein distance between the two strings is: " + distance);
    }
}
