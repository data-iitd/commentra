
public class Bob_sMaxStrength {
    public static void main(String[] args) {
        // Take input from the user
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        // Process the input to get a tuple of (value, type) pairs for each piece
        int[] pieces = new int[sc.nextInt()];
        for (int i = 0; i < pieces.length; i++) {
            pieces[i] = sc.nextInt();
        }
        // Call the Bob_sMaxStrength function with the processed pieces and return its result
        System.out.println(Bob_sMaxStrength(pieces));
    }
    
    public static int Bob_sMaxStrength(int[] pieces) {
        // Initialize scores for both ends and their maximum scores
        int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
        for (int piece : pieces) {
            if (piece > 0) {
                pScore += piece;
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } else {
                sScore += piece;
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            }
        }
        // Return the maximum score between the two ends
        if (pMaxScore > sMaxScore) {
            return pMaxScore;
        }
        return sMaxScore;
    }
}

