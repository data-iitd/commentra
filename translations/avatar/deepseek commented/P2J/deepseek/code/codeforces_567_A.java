import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int inp = scanner.nextInt();  // Taking an integer input from the user
        List<Integer> lista = new ArrayList<>();
        scanner.nextLine();  // Consume the newline character
        String[] input = scanner.nextLine().split(" ");  // Reading the input string
        for (String s : input) {
            lista.add(Integer.parseInt(s));  // Converting the input string into a list of integers
        }

        // Iterating through the list of integers
        for (int i = 0; i < lista.size(); i++) {
            // For the first element in the list
            if (i == 0) {
                System.out.println((lista.get(i + 1) - lista.get(i)) + " " + (lista.get(lista.size() - 1) - lista.get(i)));  // Printing the differences
                continue;
            }
            // For the last element in the list
            else if (i == lista.size() - 1) {
                System.out.println((lista.get(lista.size() - 1) - lista.get(lista.size() - 2)) + " " + (lista.get(lista.size() - 1) - lista.get(0)));  // Printing the differences
                continue;
            }
            // For other elements in the list
            else if (lista.get(i) - lista.get(i - 1) > lista.get(i + 1) - lista.get(i)) {
                System.out.print((lista.get(i + 1) - lista.get(i)) + " ");  // Printing the difference between the next and current integer
            } else {
                System.out.print((lista.get(i) - lista.get(i - 1)) + " ");  // Printing the difference between the current and previous integer
            }
            // Printing the difference between the last and current integer or the first and current integer
            if (lista.get(lista.size() - 1) - lista.get(i) > lista.get(i) - lista.get(0)) {
                System.out.println(lista.get(lista.size() - 1) - lista.get(i));  // Printing the difference between the last and current integer
            } else {
                System.out.println(lista.get(i) - lista.get(0));  // Printing the difference between the first and current integer
            }
        }
