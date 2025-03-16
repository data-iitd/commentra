import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] inputList = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(inputList);
        String result = "NO";
        for (int i = 1; i < inputList.length; i++) {
            int currentElement = inputList[i];
            int previousElement = inputList[i - 1];
            if (currentElement < previousElement * 2 && currentElement != previousElement) {
                result = "YES";
                break;
            }
        }
        System.out.println(result);
    }
}

