
// Importing java.util.Scanner for taking input
import java.util.Scanner;

// Creating a Scanner object to take input
Scanner sc = new Scanner(System.in);

// Taking input for number of strings 'n' and number of problems 'q'
int n = sc.nextInt();
int q = sc.nextInt();

// Taking input for the string 's'
String s = sc.next();

// Creating a list 'problems' of lists containing start and end indices of each problem
List<List<Integer>> problems = new ArrayList<>();
for (int i = 0; i < q; i++) {
    List<Integer> problem = new ArrayList<>();
    problem.add(sc.nextInt());
    problem.add(sc.nextInt());
    problems.add(problem);
}

// Function definition for counting the number of 'AC' substrings in the given string 's'
// The function takes two arguments: 'total' which is the current sum of 'AC' substrings and 'i' which is the index of the current character
int count(int total, int i) {
    // Return the sum of 'total' and 1 if the substring from index 'i-1' to 'i+1' is 'AC'
    return total + 1 == s.substring(i-1, i+1).equals("AC") ? total + 1 : total;
}

// Using accumulate function to calculate the cumulative sum of 'AC' substrings in the string 's'
List<Integer> cumsum = new ArrayList<>();
cumsum.add(0);
for (int i = 1; i <= n; i++) {
    cumsum.add(count(cumsum.get(i-1), i));
}

// Iterating through each problem in the list 'problems' and printing the difference between the cumulative sum at the end and start of the problem
for (List<Integer> problem : problems) {
    // Print the difference between the cumulative sum at the end and start of the problem
    System.out.println(cumsum.get(problem.get(1)-1) - cumsum.get(problem.get(0)-1));
}

