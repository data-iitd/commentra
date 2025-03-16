// Read the number of operations (t) and the size of the array (m)
int t = Integer.parseInt(input());
int m = Integer.parseInt(input());
// Initialize an array to keep track of allocated memory blocks, initially all set to 0
int[] alocuente = new int[m];
// Initialize an index to keep track of the next allocation identifier
int ind = 1;

// Process each operation
for (int i = 0; i < t; i++) {
    // Read the operation and its parameters
    String[] op = input().split();
    
    // Handle the 'alloc' operation
    if (op[0].equals("alloc")) {
        int pos = 0;  // Position counter to find free blocks
        for (int j = 0; j < m; j++) {
            // Check if the current block is free (0)
            if (alocuente[j] == 0) {
                pos++;  // Increment the position counter
                // If we have found enough consecutive free blocks
                if (pos == Integer.parseInt(op[1])) {
                    // Allocate the blocks and set them to the current identifier
                    for (int k = j - Integer.parseInt(op[1]) + 1; k <= j; k++) {
                        alocuente[k] = ind;
                    }
                    System.out.println(ind);  // Output the identifier of the allocated blocks
                    ind++;  // Increment the identifier for the next allocation
                    break;
                }
            } else {
                pos = 0;  // Reset position counter if a block is occupied
        } else {
            // If no sufficient space was found, output NULL
            System.out.println("NULL");
    
    // Handle the 'erase' operation
    if (op[0].equals("erase")) {
        int pos = 0;  // Position counter for finding the block to erase
        // Check if the identifier to erase is valid
        if (Integer.parseInt(op[1]) < 1 || Integer.parseInt(op[1]) > ind) {
            System.out.println("ILLEGAL_ERASE_ARGUMENT");  // Output error for illegal erase
        } else {
            // Iterate through the array to find and erase the specified block
            for (int j = 0; j < m; j++) {
                if (Integer.parseInt(op[1]) > 0 && alocuente[j] == Integer.parseInt(op[1])) {
                    alocuente[j] = 0;  // Set the block to 0 to indicate it is free
    
    // Handle the 'defragment' operation
    if (op[0].equals("defragment")) {
        int cnt = 0;  // Counter for the number of free blocks
        cnt = Arrays.stream(alocuente).filter(j -> j == 0).count();  // Count how many blocks are free
        // Create a new list with only the allocated blocks (non-zero)
        List<Integer> alocuenteList = new ArrayList<>();
        for (int j = 0; j < m; j++) {
            if (alocuente[j]!= 0) {
                alocuenteList.add(alocuente[j]);
            }
        }
        // Append the free blocks (0) back to the end of the list
        for (int j = 0; j < cnt; j++) {
            alocuenteList.add(0);
        }
        // Convert the list to an array
        alocuente = alocuenteList.stream().mapToInt(Integer::intValue).toArray();

