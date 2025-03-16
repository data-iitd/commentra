public class Main {
    public static void main(String[] args) {
        // Read input (the first input is ignored)
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        
        // Read the second line of input, split it into integers and corresponding characters,
        // and create a tuple of pieces where each piece is a tuple of (score, character)
        String[] input = scanner.nextLine().split(" ");
        int[] scores = new int[input.length / 2];
        char[] characters = new char[input.length / 2];
        for (int i = 0; i < input.length / 2; i++) {
            scores[i] = Integer.parseInt(input[i]);
            characters[i] = input[i + input.length / 2].charAt(0);
        }
        
        // Call the function to calculate Bob's maximum strength and return the result
        System.out.println(Bob_sMaxStrength(scores, characters));
    }
    
    public static int Bob_sMaxStrength(int[] scores, char[] characters) {
        // Initialize scores for player A and player B, and their maximum scores
        int pScore = sScore = pMaxScore = sMaxScore = 0;
        for (int i = 0; i < characters.length; i++) {
            if (characters[i] == 'B') {
                pScore += scores[i];
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            }
        }
        
        // Calculate maximum score for player A by iterating through pieces from the start
        for (int i = 0; i < characters.length; i++) {
            if (characters[i] == 'A') {
                pScore += scores[i];
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } else {
                pScore -= scores[i];
            }
        }
        
        // Calculate maximum score for player B by iterating through pieces from the end
        for (int i = characters.length - 1; i >= 0; i--) {
            if (characters[i] == 'A') {
                sScore += scores[i];
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            } else {
                sScore -= scores[i];
            }
        }
        
        // Return the maximum score between player A and player B
        if (pMaxScore > sMaxScore) {
            return pMaxScore;
        }
        return sMaxScore;
    }
}
