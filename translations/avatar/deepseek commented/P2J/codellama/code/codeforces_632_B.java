
public class BobsMaxStrength {
    public static void main(String[] args) {
        // Take input from the user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] values = new int[n];
        char[] types = new char[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
            types[i] = scanner.next().charAt(0);
        }
        // Call the Bob_sMaxStrength function with the processed pieces and return its result
        System.out.println(Bob_sMaxStrength(values, types));
    }

    public static int Bob_sMaxStrength(int[] values, char[] types) {
        // Initialize scores for both ends and their maximum scores
        int pScore = sScore = pMaxScore = sMaxScore = 0;
        for (int i = 0; i < values.length; i++) {
            if (types[i] == 'B') {
                pScore += values[i];
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            }
        }
        for (int i = values.length - 1; i >= 0; i--) {
            if (types[i] == 'A') {
                sScore += values[i];
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            }
        }
        for (int i = 0; i < values.length; i++) {
            if (types[i] == 'A') {
                pScore += values[i];
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } else {
                pScore -= values[i];
            }
        }
        for (int i = values.length - 1; i >= 0; i--) {
            if (types[i] == 'B') {
                sScore += values[i];
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            } else {
                sScore -= values[i];
            }
        }
        // Return the maximum score between the two ends
        if (pMaxScore > sMaxScore) {
            return pMaxScore;
        }
        return sMaxScore;
    }
}

