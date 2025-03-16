// Read the values of N and M from input
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int M = sc.nextInt();

// Read the strings S and T from input
String S = sc.next();
String T = sc.next();

// Convert strings S and T into lists for easier indexing
List<Character> list_S = new ArrayList<>();
for (int i = 0; i < S.length(); i++) {
    list_S.add(S.charAt(i));
}
List<Character> list_T = new ArrayList<>();
for (int i = 0; i < T.length(); i++) {
    list_T.add(T.charAt(i));
}

// Create a list of indices from 0 to N-1
List<Integer> Number_i = new ArrayList<>();
for (int i = 0; i < N; i++) {
    Number_i.add(i);
}

// Initialize an empty list to store calculated indices
List<Integer> Number_iMN = new ArrayList<>();

// Calculate the scaled indices based on the ratio of M to N
for (int i = 0; i < Number_i.size(); i++) {
    Number_iMN.add(Number_i.get(i) * M / N);
}

// Create a list of indices from 0 to M-1
List<Integer> Number_j = new ArrayList<>();
for (int j = 0; j < M; j++) {
    Number_j.add(j);
}

// Find the common indices between the scaled Number_iMN and Number_j
List<Integer> Kaburi_j = new ArrayList<>(Number_iMN);
Kaburi_j.retainAll(Number_j);

// Initialize an empty list to store the corresponding indices in the original range
List<Integer> Kaburi_i = new ArrayList<>();

// Calculate the corresponding indices in the original range based on Kaburi_j
for (int j = 0; j < Kaburi_j.size(); j++) {
    Kaburi_i.add(Kaburi_j.get(j) * N / M);
}

// Initialize a counter for iteration and a flag for mismatch detection
int counter = 0;
int Flag = 0;

// Get the size of the Kaburi_i list
int Kaburi_Size = Kaburi_i.size();

// Check if the characters at the calculated indices in S and T match
while (counter <= Kaburi_Size - 1) {
    if (list_S.get(Kaburi_i.get(counter)) == list_T.get(Kaburi_j.get(counter))) {
        // Characters match, continue checking
        counter++;
    } else {
        // Set flag if a mismatch is found
        Flag = 1;
        break;
    }
}

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Output the result based on the flag indicating if a mismatch was found
if (Flag == 1) {
    System.out.println(-1); // Print -1 if there was a mismatch
} else {
    // Print the least common multiple (LCM) of N and M
    System.out.println(N * M / gcd(N, M));
}

