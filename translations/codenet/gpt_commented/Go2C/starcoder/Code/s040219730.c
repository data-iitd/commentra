

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	int *C = malloc(sizeof(int) * n);
	REP(i, n) scanf("%d", C + i);
	int *P = malloc(sizeof(int) * (n + 50));
	REP(i, n + 50) P[i] = -1;
	int *Answers = malloc(sizeof(int) * q);
	struct Query {
		int idx, l, r;
	};
	struct Query *Q = malloc(sizeof(struct Query) * q);
	REP(i, q) {
		scanf("%d %d", &Q[i].l, &Q[i].r);
		Q[i].idx = i;
	}
	qsort(Q, q, sizeof(struct Query), [](const void *a, const void *b) {
		return ((struct Query *)a)->r < ((struct Query *)b)->r;
	});
	int k = 0;
	struct FenwickTree {
		int *dat;
		int n, minPow2;
		void init(int n) {
			this->n = n;
			this->dat = malloc(sizeof(int) * (n + 50));
			REP(i, n + 50) this->dat[i] = 0;
			this->minPow2 = 1;
			while ((this->minPow2 << 1) <= n) this->minPow2 <<= 1;
		}
		int sum(int i) {
			int s = 0;
			while (i > 0) {
				s += this->dat[i];
				i -= i & (-i);
			}
			return s;
		}
		void add(int i, int x) {
			while (i <= this->n) {
				this->dat[i] += x;
				i += i & (-i);
			}
		}
		int lowerBound(int w) {
			if (w <= 0) return 0;
			int x = 0;
			while (this->minPow2 > 0) {
				if (x + this->minPow2 <= this->n && this->dat[x + this->minPow2] < w) {
					w -= this->dat[x + this->minPow2];
					x += this->minPow2;
				}
				this->minPow2 >>= 1;
			}
			return x + 1;
		}
	};
	struct FenwickTree ft;
	ft.init(500000 + 50);
	REP(i, q) {
		while (k < Q[i].r) {
			if (P[C[k]]!= -1) ft.add(P[C[k]] + 1, -1);
			P[C[k]] = k;
			ft.add(k + 1, 1);
			k++;
		}
		Answers[Q[i].idx] = ft.sum(Q[i].r) - ft.sum(Q[i].l - 1);
	}
	REP(i, q) printf("%d\n", Answers[i]);
	return 0;
}

/*
# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.c"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main.c"
# 33 "main.c"
# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 369 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 313 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 314 "/usr/include/sys/cdefs.h" 2 3 4
# 370 "/usr/include/features.h" 2 3 4
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 10 "/usr/include/gnu/stubs.h" 3 4
# 1 "/usr/include/gnu/stubs-32.h" 1 3 4
# 11 "/usr/include/gnu/stubs.h" 2 3 4
# 393 "/usr/include/features.h" 2 3 4
# 28 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 1 3 4
# 214 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types.h" 1 3 4
# 27 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/types.h" 2 3 4
# 1 "/usr/include/bits/timesize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4
# 35 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE FILE;
# 1 "/usr/include/bits/types/__fpos_t.h" 1 3 4
# 13 "/usr/include/bits/types/__fpos_t.h" 3 4
__extension__ typedef long long _off_t;
# 26 "/usr/include/bits/types/__fpos_t.h" 3 4
# 1 "/usr/include/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/bits/types/__mbstate_t.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 27 "/usr/include/bits/types/__fpos_t.h" 2 3 4

typedef struct _IO_FILE __FILE;



# 1 "/usr/include/bits/types/__fpos64_t.h" 1 3 4
# 12 "/usr/include/bits/types/__fpos64_t.h" 3 4
__extension__ typedef long long _off64_t;
# 26 "/usr/include/bits/types/__fpos64_t.h" 3 4
# 1 "/usr/include/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/bits/types/__mbstate_t.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 27 "/usr/include/bits/types/__fpos64_t.h" 2 3 4

typedef struct _IO_FILE __FILE;
# 45 "/usr/include/stdio.h" 2 3 4
# 146 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/types/FILE.h" 1 3 4
# 15 "/usr/include/bits/types/FILE.h" 3 4
typedef struct _IO_FILE FILE;
# 147 "/usr/include/stdio.h" 2 3 4
# 159 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/libio.h" 1 3 4
# 31 "/usr/include/bits/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4
# 1 "/usr/include/bits/types/__fpos_t.h" 1 3 4
# 13 "/usr/include/bits/types/__fpos_t.h" 3 4
__extension__ typedef long long _off_t;
# 26 "/usr/include/bits/types/__fpos_t.h" 3 4
# 1 "/usr/include/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/bits/types/__mbstate_t.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 27 "/usr/include/bits/types/__fpos_t.h" 2 3 4

typedef struct _IO_FILE __FILE;
# 32 "/usr/include/bits/libio.h" 2 3 4
# 14 "/usr/include/bits/types/struct_IO_FILE.h" 1 3 4
# 31 "/usr/include/bits/types/struct_IO_FILE.h" 3 4
struct _IO_FILE
{
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct __mbstate_t *_IO_state;
  struct __mbstate_t *_IO_last_state;
  struct __FILE *_IO_stdin;
  struct __FILE *_IO_stdout;
  struct __FILE *_IO_stderr;
  int _IO_column_no;
  int _IO_line_no;
  int _IO_file_flags;
  int _IO_magic;
  struct _IO_marker *_IO_marker;
  struct _IO_codecvt *_IO_codecvt;
  struct _IO_wide_data *_IO_wide_data;
  struct _IO_jump_t *_IO_jump_table;
  void *_IO_freeres_list;
  void *_IO_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
# 160 "/usr/include/stdio.h" 2 3 4
# 176 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;
# 236 "/usr/include/stdio.h" 3 4
extern int remove (const char *__filename) __attribute__ ((__nothrow__, __leaf__));
# 249 "/usr/include/stdio.h" 3 4
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__, __leaf__));
# 264 "/usr/include/stdio.h" 3 4
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__, __leaf__));
# 280 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile (void) ;
# 300 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__, __leaf__)) ;
# 310 "/usr/include/stdio.h" 3 4
extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__, __leaf__)) ;
# 325 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__prefix)
     __attribute__ ((__nothrow__, __leaf__)) __attribute__ ((__malloc__)) ;
# 341 "/usr/include/stdio.h" 3 4
extern int fclose (FILE *__stream);
# 352 "/usr/include/stdio.h" 3 4
extern int fflush (FILE *__stream);
# 363 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 374 "/usr/include/stdio.h" 3 4
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;
# 385 "/usr/include/stdio.h" 3 4
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 403 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__, __leaf__)) ;
# 416 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes) __attribute__ ((__nothrow__, __leaf__)) ;
# 433 "/usr/include/stdio.h" 3 4
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__, __leaf__)) ;
# 446 "/usr/include/stdio.h" 3 4
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__, __leaf__));
# 457 "/usr/include/stdio.h" 3 4
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__, __leaf__));
# 473 "/usr/include/stdio.h" 3 4
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__, __leaf__));
# 484 "/usr/include/stdio.h" 3 4
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__, __leaf__));
# 500 "/usr/include/stdio.h" 3 4
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format,...);
# 515 "/usr/include/stdio.h" 3 4
extern int printf (const char *__restrict __format,...);
# 526 "/usr/include/stdio.h" 3 4
extern int sprintf (char *__restrict __s,
      const char *__restrict __format,...) __attribute__ ((__nothrow__));
# 540 "/usr/include/stdio.h" 3 4
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
# 555 "/usr/include/stdio.h" 3 4
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
# 566 "/usr/include/stdio.h" 3 4
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));
# 582 "/usr/include/stdio.h" 3 4
extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format,...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
# 598 "/usr/include/stdio.h" 3 4
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0