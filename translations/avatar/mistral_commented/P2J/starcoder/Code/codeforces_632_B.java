// This function is the entry point of the program
public static void main(String[] args) {
    // Read input from standard input
    Scanner scanner = new Scanner(System.in);
    scanner.nextLine();

    // Parse input into a tuple of pairs, where each pair contains the score and the player of a piece
    Pair[] pieces = new Pair[scanner.nextInt()];
    for (int i = 0; i < pieces.length; i++) {
        pieces[i] = new Pair(scanner.nextInt(), scanner.next());
    }

    // Call the function to find Bob's maximum strength
    int result = Bob_sMaxStrength(pieces);

    // Print the result
    System.out.println(result);
}

// This function calculates Bob's maximum strength based on the given pieces
public static int Bob_sMaxStrength(Pair[] pieces) {
    // Initialize variables to store the scores for players A and B
    int p_score = 0, s_score = 0, p_max_score = 0, s_max_score = 0;

    // Iterate through each piece and update the scores accordingly
    for (Pair piece : pieces) {
        // If the piece belongs to player A, add its score to p_score
        if (piece.player.equals("A")) {
            p_score += piece.score;
            // Update p_max_score if the current p_score is greater
            if (p_score > p_max_score) {
                p_max_score = p_score;
            }
        }
        // If the piece belongs to player B, subtract its score from p_score
        else {
            p_score -= piece.score;
        }
    }

    // Iterate through the pieces in reverse order and update the scores for player S
    for (int i = pieces.length - 1; i >= 0; i--) {
        // If the current piece belongs to player A, add its score to s_score
        if (pieces[i].player.equals("A")) {
            s_score += pieces[i].score;
            // Update s_max_score if the current s_score is greater
            if (s_score > s_max_score) {
                s_max_score = s_score;
            }
        }
        // If the current piece belongs to player B, subtract its score from s_score
        else {
            s_score -= pieces[i].score;
        }
    }

    // Return the maximum score between Bob's and Sally's scores
    if (p_max_score > s_max_score) {
        return p_max_score;
    }
    return s_max_score;
}

// This class represents a pair of an integer and a string
class Pair {
    int score;
    String player;

    public Pair(int score, String player) {
        this.score = score;
        this.player = player;
    }
}

