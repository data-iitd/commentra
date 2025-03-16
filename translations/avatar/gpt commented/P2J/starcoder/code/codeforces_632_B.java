public class Bob_sMaxStrength {
    public static void main(String[] args) {
        // Read input (the first input is ignored)
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        
        // Read the second line of input, split it into integers and corresponding characters,
        // and create a tuple of pieces where each piece is a tuple of (score, character)
        Tuple pieces = Tuple.of(Arrays.stream(sc.nextLine().split()).mapToInt(Integer::parseInt).boxed().toArray(Integer[]::new), sc.nextLine().split());
        
        // Call the function to calculate Bob's maximum strength and return the result
        System.out.println(Bob_sMaxStrength(pieces));
    }
    
    public static int Bob_sMaxStrength(Tuple pieces) {
        // Initialize scores for player A and player B, and their maximum scores
        int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
        for (int i = 0; i < pieces.size(); i++) {
            if (pieces.get(i).get(1).equals("B")) {  // If the piece belongs to player B
                pScore += pieces.get(i).get(0);  // Add the score of the piece to player A's score
            } else {  // If the piece belongs to player A
                sScore += pieces.get(i).get(0);  // Add the score of the piece to player B's score
            }
        }
        pMaxScore = pScore;
        sMaxScore = sScore;
        
        // Calculate maximum score for player A by iterating through pieces from the start
        for (int i = 0; i < pieces.size(); i++) {
            if (pieces.get(i).get(1).equals("A")) {  // If the piece belongs to player A
                pScore += pieces.get(i).get(0);  // Add the score of the piece to player A's score
                if (pScore > pMaxScore) {  // Update maximum score if current score exceeds it
                    pMaxScore = pScore;
                }
            } else {  // If the piece belongs to player B
                pScore -= pieces.get(i).get(0);  // Subtract the score of the piece from player A's score
            }
        }
        
        // Calculate maximum score for player B by iterating through pieces from the end
        for (int i = pieces.size() - 1; i >= 0; i--) {
            if (pieces.get(i).get(1).equals("A")) {  // If the piece belongs to player A
                sScore += pieces.get(i).get(0);  // Add the score of the piece to player B's score
                if (sScore > sMaxScore) {  // Update maximum score if current score exceeds it
                    sMaxScore = sScore;
                }
            } else {  // If the piece belongs to player B
                sScore -= pieces.get(i).get(0);  // Subtract the score of the piece from player B's score
            }
        }
        
        // Return the maximum score between player A and player B
        if (pMaxScore > sMaxScore) {
            return pMaxScore;
        }
        return sMaxScore;
    }
}

