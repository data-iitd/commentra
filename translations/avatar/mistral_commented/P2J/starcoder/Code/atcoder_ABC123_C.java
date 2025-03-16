// Import necessary libraries
import java.util.*;

// Define a constant variable N, which is the input number
final int N = Integer.parseInt(sc.nextLine());

// Define a list A, which consists of five integers, each input as a separate line
final List<Integer> A = new ArrayList<>();
for (int i = 0; i < 5; i++) {
    A.add(Integer.parseInt(sc.nextLine()));
}

// Calculate the minimum value in the list A
final int min_value = Collections.min(A);

// Calculate the ceiling value of N divided by the minimum value in the list A
final int ceiling_value = (int) Math.ceil(N / min_value);

// Add 4 to the ceiling value to get the final answer
final int final_answer = ceiling_value + 4;

// Print the final answer
System.out.println(final_answer);

