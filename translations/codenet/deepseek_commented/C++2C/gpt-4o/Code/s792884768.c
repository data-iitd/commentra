// Define the TSize structure
struct TSize
{
    int r;
    int c;
};

// Default constructor equivalent in C
void TSize_init(struct TSize* size) {
    size->r = 0;
    size->c = 0;
}

// Parameterized constructor equivalent in C
void TSize_init_param(struct TSize* size, int Ar, int Ac) {
    size->r = Ar;
    size->c = Ac;
}

// Example usage
/*
struct TSize mySize;
<<<<<<< HEAD
TSize_init(&mySize); // Default initialization
TSize_init_param(&mySize, 5, 10); // Parameterized initialization
=======
TSize_init(&mySize); // Default constructor
TSize_init_param(&mySize, 5, 10); // Parameterized constructor
>>>>>>> 98c87cb78a (data updated)
*/

