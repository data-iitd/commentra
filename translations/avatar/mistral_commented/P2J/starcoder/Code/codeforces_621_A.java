// Take an integer 'n' as input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Create a list 'lst' of 'n' integers taken as input
List<Integer> lst = new ArrayList<>();
for (int i = 0; i < n; i++) {
    lst.add(sc.nextInt());
}

// Sort the list 'lst' in ascending order
Collections.sort(lst);

// Reverse the sorted list 'lst'
Collections.reverse(lst);

// Initialize odd_digits counter 'od' to 0
int od = 0;

// Iterate through each integer 'i' in the list 'lst'
for (int i : lst) {
    // If the integer 'i' has an odd number of bits (1 in binary representation), increment 'od' counter
    if ((i & 1) == 1) {
        od++;
    }
}

// Initialize sum and ok variables
int sum = 0;
boolean ok = false;

// Iterate through each index 'i' in the range of 'n'
for (int i = 0; i < n; i++) {
    // If the integer at index 'i' in the list 'lst' is even, add it to the sum'sum'
    if ((lst.get(i) & 1) == 0) {
        sum += lst.get(i);
    }
    // If the integer at index 'i' in the list 'lst' is odd and either 'ok' is True or 'od' is greater than 1, add it to the sum'sum' and toggle 'ok'
    else {
        if (ok || od > 1) {
            sum += lst.get(i);
            od--;
            ok =!ok;
        }
    }
}

// Print the final sum
System.out.println(sum);

