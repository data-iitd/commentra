
import sys

appleNum = int(sys.stdin.readline())
pieceNum = int(sys.stdin.readline())
pieceNumMadeFromApples = appleNum * 3
totalPiece = pieceNumMadeFromApples + pieceNum
print(totalPiece // 2)

