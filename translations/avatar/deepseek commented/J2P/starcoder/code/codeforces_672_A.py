
import java.util.Scanner ; 

def generateString():
    sb = []
    for i in range(1, 1001):
        sb.append(i)
    return sb.toString().toCharArray()

def main():
    sc = Scanner(System.in)
    n = sc.nextInt()
    print(generateString()[n-1])

if __name__ == "__main__":
    main()

