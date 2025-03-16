
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int appleNum = sc.nextInt();
        int pieceNum = sc.nextInt();
        int pieceNumMadeFromApples = appleNum * 3;
        int totalPiece = pieceNumMadeFromApples + pieceNum;
        System.out.println(totalPiece / 2);
    }
}

