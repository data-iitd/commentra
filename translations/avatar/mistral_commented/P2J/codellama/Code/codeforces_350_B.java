// Take the number of test cases as input
int n = Integer.parseInt(sc.nextLine());

// Initialize a list 't' with 0 as the first element and followed by the given input list
int[] t = new int[n+1];
t[0] = 0;
for (int i = 1; i <= n; i++) {
    t[i] = Integer.parseInt(sc.next());
}

// Initialize a list 'a' with 0 as the first element and followed by the given input list
int[] a = new int[n+1];
a[0] = 0;
for (int i = 1; i <= n; i++) {
    a[i] = Integer.parseInt(sc.next());
}

// Initialize empty lists 'ans' and 'cnt'
ArrayList<Integer> ans = new ArrayList<Integer>();
int[] cnt = new int[n+1];

// Iterate through each element in list 'a' and increment the count of its corresponding index in list 'cnt'
for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
}

// Iterate through each index from 1 to n
for (int i = 1; i <= n; i++) {
    // If the current index in list 't' is 1
    if (t[i] == 1) {
        // Initialize an empty list 'crt' to store the current sequence
        ArrayList<Integer> crt = new ArrayList<Integer>();
        crt.add(i);
        // Get the current element in list 'a'
        int x = a[i];
        // Continue adding elements to 'crt' as long as the corresponding index in 'cnt' has a count of 1
        while (cnt[x] == 1) {
            crt.add(x);
            x = a[x];
        }
        // If the length of the current sequence is greater than the length of the current answer sequence
        if (crt.size() > ans.size()) {
            // Update the answer sequence with the current sequence
            ans = crt;
        }
    }
}

// Reverse the order of elements in the answer sequence
Collections.reverse(ans);

// Print the length of the answer sequence
System.out.println(ans.size());
// Print the answer sequence with each element separated by a space
for (int i = 0; i < ans.size(); i++) {
    System.out.print(ans.get(i) + " ");
}

