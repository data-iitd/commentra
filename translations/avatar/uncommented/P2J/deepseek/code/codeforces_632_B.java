import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first line (discard it)
        String[] input = scanner.nextLine().split(" ");
        String[] types = scanner.nextLine().split(" ");
        
        int[] strengths = new int[input.length];
        char[] typesArray = new char[types.length];
        
        for (int i = 0; i < input.length; i++) {
            strengths[i] = Integer.parseInt(input[i]);
            typesArray[i] = types[i].charAt(0);
        }
        
        System.out.println(Bob_sMaxStrength(strengths, typesArray));
    }
    
    public static int Bob_sMaxStrength(int[] strengths, char[] types) {
        int pScore = 0, sScore = 0;
        int pMaxScore = 0, sMaxScore = 0;
        
        for (int i = 0; i < strengths.length; i++) {
            if (types[i] == 'B') {
                pScore += strengths[i];
                sScore += strengths[i];
            } else if (types[i] == 'A') {
                pScore += strengths[i];
                if (pScore > pMaxScore) {
                    pMaxScore = pScore;
                }
            } else { // 'D'
                pScore -= strengths[i];
                sScore -= strengths[i];
            }
        }
        
        for (int i = strengths.length - 1; i >= 0; i--) {
            if (types[i] == 'A') {
                sScore += strengths[i];
                if (sScore > sMaxScore) {
                    sMaxScore = sScore;
                }
            }
        }
        
        return Math.max(pMaxScore, sMaxScore);
    }
}
