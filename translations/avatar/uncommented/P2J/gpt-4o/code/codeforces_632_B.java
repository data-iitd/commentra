import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first line of input
        List<Piece> pieces = new ArrayList<>();
        
        String[] values = scanner.nextLine().split(" ");
        String types = scanner.nextLine();
        
        for (int i = 0; i < values.length; i++) {
            int value = Integer.parseInt(values[i]);
            char type = types.charAt(i);
            pieces.add(new Piece(value, type));
        }
        
        System.out.println(BobsMaxStrength(pieces));
    }

    public static int BobsMaxStrength(List<Piece> pieces) {
        int pScore = 0, sScore = 0;
        int pMaxScore = 0, sMaxScore = 0;

        for (Piece piece : pieces) {
            if (piece.type == 'B') {
                pScore += piece.value;
            }
        }
        pMaxScore = pScore;

        for (Piece piece : pieces) {
            if (piece.type == 'A') {
                pScore += piece.value;
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } else {
                pScore -= piece.value;
            }
        }

        for (int i = pieces.size() - 1; i >= 0; i--) {
            Piece piece = pieces.get(i);
            if (piece.type == 'A') {
                sScore += piece.value;
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            } else {
                sScore -= piece.value;
            }
        }

        return Math.max(pMaxScore, sMaxScore);
    }

    static class Piece {
        int value;
        char type;

        Piece(int value, char type) {
            this.value = value;
            this.type = type;
        }
    }
}

// <END-OF-CODE>
