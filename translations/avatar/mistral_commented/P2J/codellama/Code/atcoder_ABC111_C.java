
// Take the number of elements in the list from user input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize an empty list 'x' to store the input elements
List<Integer> x = new ArrayList<>();

// Initialize two empty lists 'a' and 'b' to store even and odd elements respectively
List<Integer> a = new ArrayList<>();
List<Integer> b = new ArrayList<>();

// Iterate through the list 'x' and append even and odd elements to their respective lists
for (int i = 0; i < n; i++) {
    x.add(sc.nextInt());
    if (i % 2 == 0) {
        a.add(x.get(i));
    } else {
        b.add(x.get(i));
    }
}

// Initialize two lists 'cnta' and 'cntb' of size 100002+1 to store the count of each element in lists 'a' and 'b' respectively
int[] cnta = new int[100002 + 1];
int[] cntb = new int[100002 + 1];

// Initialize two variables 'vala' and 'valb' to store the elements with maximum count in lists 'a' and 'b' respectively
int vala = 0;
int valb = 0;

// Initialize two variables 'maxCnta' and 'maxCntb' to store the maximum count of an element in lists 'a' and 'b' respectively
int maxCnta = 0;
int maxCntb = 0;

// Iterate through list 'a' and update the count of each element in 'cnta'
for (int i = 0; i < a.size(); i++) {
    cnta[a.get(i)] += 1;
}

// Find the element with maximum count in list 'a' and update 'vala' and 'maxCnta'
for (int i = 0; i < a.size(); i++) {
    if (maxCnta < cnta[a.get(i)]) {
        vala = a.get(i);
        maxCnta = cnta[a.get(i)];
    }
}

// Find the second element with maximum count in list 'a' (different from 'vala') and update 'vala1' and 'maxCnta1'
int vala1 = 0;
int maxCnta1 = 0;
for (int i = 0; i < a.size(); i++) {
    if (maxCnta1 < cnta[a.get(i)] && a.get(i) != vala) {
        maxCnta1 = cnta[a.get(i)];
        vala1 = a.get(i);
    }
}

// Similar logic for list 'b'
for (int i = 0; i < b.size(); i++) {
    cntb[b.get(i)] += 1;
}

// Find the element with maximum count in list 'b' and update 'valb' and 'maxCntb'
for (int i = 0; i < b.size(); i++) {
    if (maxCntb < cntb[b.get(i)]) {
        valb = b.get(i);
        maxCntb = cntb[b.get(i)];
    }
}

// Find the second element with maximum count in list 'b' (different from 'valb') and update 'valb1' and 'maxCntb1'
int valb1 = 0;
int maxCntb1 = 0;
for (int i = 0; i < b.size(); i++) {
    if (maxCntb1 < cntb[b.get(i)] && b.get(i) != valb) {
        maxCntb1 = cntb[b.get(i)];
        valb1 = b.get(i);
    }
}

// Check if 'vala' and 'valb' are same or not
if (valb != vala) {
    // If they are not same, calculate the sum of counts of all elements except 'vala' and 'valb' and print the result
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a.get(i) != vala) {
            res += 1;
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (b.get(i) != valb) {
            res += 1;
        }
    }
    System.out.println(res);
} else {
    // If 'vala' and 'valb' are same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count in list 'a' and list 'b' respectively
    // and print the minimum of these two sums
    int resa = 0;
    int resb = 0;
    int resa1 = 0;
    int resb1 = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a.get(i) != vala) {
            resa += 1;
        }
        if (a.get(i) != vala1) {
            resa1 += 1;
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (b.get(i) != valb) {
            resb += 1;
        }
        if (b.get(i) != valb1) {
            resb1 += 1;
        }
    }
    System.out.println(Math.min(resa + resb1, resa1 + resb));
}

