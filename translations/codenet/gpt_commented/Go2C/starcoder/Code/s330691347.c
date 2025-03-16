

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	Data *data;
	int len;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas p) {
	return p.len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas p, int i, int j) {
	Data tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
int Less(Datas p, int i, int j) {
	return strcmp(p.data[i].X, p.data[j].X) < 0;
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	Datas s = {malloc(sizeof(Data) * N), N};
	for (int i = 0; i < N; i++) {
		s.data[i].X = malloc(100);
		scanf("%s", s.data[i].X);
	}
	printf("%d %d\n", N, L);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	qsort(s.data, N, sizeof(Data), (int (*)(const void *, const void *))Less);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	char *ans = "";
	for (int i = 0; i < N; i++) {
		ans = strcat(ans, s.data[i].X);
	}
	printf("%s\n", ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	Data *data;
	int len;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas p) {
	return p.len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas p, int i, int j) {
	Data tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
int Less(Datas p, int i, int j) {
	return strcmp(p.data[i].X, p.data[j].X) < 0;
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	Datas s = {malloc(sizeof(Data) * N), N};
	for (int i = 0; i < N; i++) {
		s.data[i].X = malloc(100);
		scanf("%s", s.data[i].X);
	}
	printf("%d %d\n", N, L);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	qsort(s.data, N, sizeof(Data), (int (*)(const void *, const void *))Less);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	char *ans = "";
	for (int i = 0; i < N; i++) {
		ans = strcat(ans, s.data[i].X);
	}
	printf("%s\n", ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	Data *data;
	int len;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas p) {
	return p.len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas p, int i, int j) {
	Data tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
int Less(Datas p, int i, int j) {
	return strcmp(p.data[i].X, p.data[j].X) < 0;
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	Datas s = {malloc(sizeof(Data) * N), N};
	for (int i = 0; i < N; i++) {
		s.data[i].X = malloc(100);
		scanf("%s", s.data[i].X);
	}
	printf("%d %d\n", N, L);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	qsort(s.data, N, sizeof(Data), (int (*)(const void *, const void *))Less);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	char *ans = "";
	for (int i = 0; i < N; i++) {
		ans = strcat(ans, s.data[i].X);
	}
	printf("%s\n", ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	Data *data;
	int len;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas p) {
	return p.len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas p, int i, int j) {
	Data tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
int Less(Datas p, int i, int j) {
	return strcmp(p.data[i].X, p.data[j].X) < 0;
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	Datas s = {malloc(sizeof(Data) * N), N};
	for (int i = 0; i < N; i++) {
		s.data[i].X = malloc(100);
		scanf("%s", s.data[i].X);
	}
	printf("%d %d\n", N, L);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	qsort(s.data, N, sizeof(Data), (int (*)(const void *, const void *))Less);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	char *ans = "";
	for (int i = 0; i < N; i++) {
		ans = strcat(ans, s.data[i].X);
	}
	printf("%s\n", ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	Data *data;
	int len;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas p) {
	return p.len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas p, int i, int j) {
	Data tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
int Less(Datas p, int i, int j) {
	return strcmp(p.data[i].X, p.data[j].X) < 0;
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	Datas s = {malloc(sizeof(Data) * N), N};
	for (int i = 0; i < N; i++) {
		s.data[i].X = malloc(100);
		scanf("%s", s.data[i].X);
	}
	printf("%d %d\n", N, L);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	qsort(s.data, N, sizeof(Data), (int (*)(const void *, const void *))Less);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	char *ans = "";
	for (int i = 0; i < N; i++) {
		ans = strcat(ans, s.data[i].X);
	}
	printf("%s\n", ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	Data *data;
	int len;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas p) {
	return p.len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas p, int i, int j) {
	Data tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
int Less(Datas p, int i, int j) {
	return strcmp(p.data[i].X, p.data[j].X) < 0;
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	Datas s = {malloc(sizeof(Data) * N), N};
	for (int i = 0; i < N; i++) {
		s.data[i].X = malloc(100);
		scanf("%s", s.data[i].X);
	}
	printf("%d %d\n", N, L);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	qsort(s.data, N, sizeof(Data), (int (*)(const void *, const void *))Less);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	char *ans = "";
	for (int i = 0; i < N; i++) {
		ans = strcat(ans, s.data[i].X);
	}
	printf("%s\n", ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	Data *data;
	int len;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas p) {
	return p.len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas p, int i, int j) {
	Data tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
int Less(Datas p, int i, int j) {
	return strcmp(p.data[i].X, p.data[j].X) < 0;
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	Datas s = {malloc(sizeof(Data) * N), N};
	for (int i = 0; i < N; i++) {
		s.data[i].X = malloc(100);
		scanf("%s", s.data[i].X);
	}
	printf("%d %d\n", N, L);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	qsort(s.data, N, sizeof(Data), (int (*)(const void *, const void *))Less);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	char *ans = "";
	for (int i = 0; i < N; i++) {
		ans = strcat(ans, s.data[i].X);
	}
	printf("%s\n", ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	Data *data;
	int len;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas p) {
	return p.len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas p, int i, int j) {
	Data tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
int Less(Datas p, int i, int j) {
	return strcmp(p.data[i].X, p.data[j].X) < 0;
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	Datas s = {malloc(sizeof(Data) * N), N};
	for (int i = 0; i < N; i++) {
		s.data[i].X = malloc(100);
		scanf("%s", s.data[i].X);
	}
	printf("%d %d\n", N, L);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	qsort(s.data, N, sizeof(Data), (int (*)(const void *, const void *))Less);
	printf("%p\n", s.data);
	printf("%d\n", s.len);
	char *ans = "";
	for (int i = 0; i < N; i++) {
		ans = strcat(ans, s.data[i].X);
	}
	printf("%s\n", ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a single data entry with a string field.
typedef struct {
	char *X;
} Data;

// Datas is a slice of Data, implementing sort.Interface.
typedef struct {
	Data *data;
	int len;
} Datas;

// Len returns the number of elements in the slice.
int Len(Datas p) {
	return p.len;
}

// Swap exchanges the elements with indexes i and j.
void Swap(Datas p, int i, int j) {
	Data tmp = p.data[i];
	p.data[i] = p.data[j]