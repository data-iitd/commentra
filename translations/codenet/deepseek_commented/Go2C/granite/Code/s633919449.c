
#include <stdio.h>
#include <stdlib.h>

#define initialBufSize 10000
#define maxBufSize 10000000
#define mod 1e9 + 7

int getInt();
int* getIntArray(int n);
char* getString();
char** getStringArray(int n);
int abs(int a);
int pow(int p, int q);
int powMod(int n, int p);
int min(int...);
int max(int...);
int strSearch(char** a, char* b);
void printIntArray(int* array);
int calcMod(int x);
char* reverse(char* s);
int isPrime(int n);
int contains(int* s, int e);
int* makeRange(int min, int max);
int** powerset2(int* nums);
int* copyAndAppend(int* nums, int n);
int calcGcd(int x, int y);
int* getDivisor(int n);

typedef struct {
    int n;
    int** edges;
} Graph;

Graph* NewGraph(int n);
void dfs(int c, int** edges, int* visited);
void bfs(int c, Graph* graph);

int main() {
    int N = getInt();

    switch (N % 10) {
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
            printf("hon\n");
            break;
        case 0:
        case 1:
        case 6:
        case 8:
            printf("pon\n");
            break;
        case 3:
            printf("bon\n");
            break;
    }

    return 0;
}

int getInt() {
    int c;
    while ((c = getchar())!= EOF) {
        if (c >= '0' && c <= '9') {
            ungetchar(c);
            break;
        }
    }

    int n;
    scanf("%d", &n);
    return n;
}

int* getIntArray(int n) {
    int* array = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        array[i] = getInt();
    }
    return array;
}

char* getString() {
    int c;
    while ((c = getchar())!= EOF) {
        if (c!='' && c!= '\n') {
            ungetchar(c);
            break;
        }
    }

    int size = 0;
    char* str = (char*)malloc(sizeof(char) * (size + 1));
    while ((c = getchar())!= EOF) {
        if (c =='' || c == '\n') {
            ungetchar(c);
            break;
        }
        str[size] = c;
        size++;
        str = (char*)realloc(str, sizeof(char) * (size + 1));
    }
    str[size] = '\0';
    return str;
}

char** getStringArray(int n) {
    char** array = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        array[i] = getString();
    }
    return array;
}

int abs(int a) {
    return (a >= 0)? a : -a;
}

int pow(int p, int q) {
    int res = 1;
    for (int i = 0; i < q; i++) {
        res *= p;
    }
    return res;
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return calcMod(t * t);
    } else {
        return calcMod(n * powMod(n, p - 1));
    }
}

int min(int...nums) {
    if (sizeof...(nums) == 0) {
        printf("funciton min() requires at least one argument.\n");
        exit(1);
    }
    int res = nums[0];
    for (int i = 0; i < sizeof...(nums); i++) {
        res = (res < nums[i])? res : nums[i];
    }
    return res;
}

int max(int...nums) {
    if (sizeof...(nums) == 0) {
        printf("funciton max() requires at least one argument.\n");
        exit(1);
    }
    int res = nums[0];
    for (int i = 0; i < sizeof...(nums); i++) {
        res = (res > nums[i])? res : nums[i];
    }
    return res;
}

int strSearch(char** a, char* b) {
    for (int i = 0; i < sizeof(a) / sizeof(char*); i++) {
        if (strcmp(a[i], b) == 0) {
            return 1;
        }
    }
    return 0;
}

void printIntArray(int* array) {
    int size = 0;
    for (int i = 0; array[i]!= 0; i++) {
        size++;
    }
    char* str = (char*)malloc(sizeof(char) * (size + 1));
    for (int i = 0; array[i]!= 0; i++) {
        sprintf(str + i * 2, "%d", array[i]);
    }
    str[size * 2] = '\0';
    printf("%s\n", str);
    free(str);
}

int calcMod(int x) {
    return x % mod;
}

char* reverse(char* s) {
    int size = 0;
    while (s[size]!= '\0') {
        size++;
    }
    char* res = (char*)malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++) {
        res[i] = s[size - 1 - i];
    }
    res[size] = '\0';
    return res;
}

int isPrime(int n) {
    if (n < 2) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }

    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int contains(int* s, int e) {
    for (int i = 0; s[i]!= 0; i++) {
        if (s[i] == e) {
            return 1;
        }
    }
    return 0;
}

int* makeRange(int min, int max) {
    int size = max - min + 1;
    int* res = (int*)malloc(sizeof(int) * (size + 1));
    for (int i = 0; i < size; i++) {
        res[i] = min + i;
    }
    res[size] = 0;
    return res;
}

int** powerset2(int* nums) {
    int size = 1 << sizeof(nums) / sizeof(int);
    int** res = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        res[i] = (int*)malloc(sizeof(int) * (sizeof(nums) / sizeof(int) + 1));
    }

    int index = 0;
    res[index] = (int*)malloc(sizeof(int));
    res[index][0] = 0;
    index++;

    for (int i = 0; nums[i]!= 0; i++) {
        int max = index;
        for (int j = 0; j < max; j++) {
            res[index] = copyAndAppend(res[j], nums[i]);
            index++;
        }
    }

    return res;
}

int* copyAndAppend(int* nums, int n) {
    int size = 0;
    for (int i = 0; nums[i]!= 0; i++) {
        size++;
    }
    size++;
    int* res = (int*)malloc(sizeof(int) * (size + 1));
    for (int i = 0; nums[i]!= 0; i++) {
        res[i] = nums[i];
    }
    res[size] = n;
    return res;
}

int calcGcd(int x, int y) {
    if (y == 0) {
        return x;
    } else if (x >= y) {
        return calcGcd(y, x % y);
    } else {
        return calcGcd(x, y % x);
    }
}

int* getDivisor(int n) {
    int size = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            size++;
        }
    }
    int* res = (int*)malloc(sizeof(int) * (size + 1));
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            res[size] = i;
            size++;
        }
    }
    return res;
}

type intHeap []int

func (h intHeap) Len() int {
    return len(h)
}

func (h intHeap) Less(i, j int) bool {
    return h[i] > h[j]
}

func (h intHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *intHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *intHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[:n-1]
    return x
}

func initHeap() *intHeap {
    ih := &intHeap{}
    heap.Init(ih)
    return ih
}

func (h *intHeap) pushHeap(n int) {
    heap.Push(h, n)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func factMod(n int) int {
    value := 1
    for ; n > 1; n-- {
        value = calcMod(value * n)
    }
    return value
}

func combinationMod(n, k int) int {
    factN := factMod(n)
    factK := factMod(k)
    factNK := factMod(n-k)
    factKR := powMod(factK, mod - 2)
    factNKR := powMod(factN, factKR)
    factNKR := powMod(factN, factKR)
    return calcMod(factN * factK * factNK)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    heap.Push(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap(h, n int) {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) popHeap() int {
    return heap.Pop(h).(*intHeap)
}

func (h *intHeap) pushHeap() int {
    r