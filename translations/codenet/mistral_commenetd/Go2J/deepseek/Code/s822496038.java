import java.util.Scanner;

public class ApplePieces {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int appleNum = scanner.nextInt();
        int pieceNum = scanner.nextInt();
        int pieceNumMadeFromApples = appleNum * 3;
        int totalPiece = pieceNumMadeFromApples + pieceNum;
        System.out.println(totalPiece / 2);
    }
}

