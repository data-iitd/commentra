
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define HEAP_FUNC_SWAP(a, b, val_size) \
  /* Swap elements based on their size (optimized for 64-bit values) */ \
  if ((val_size & 7) == 0) { \
    uint64_t *p = (uint64_t *) a; \
    uint64_t *q = (uint64_t *) b; \
    val_size /= sizeof (uint64_t); \
    while (val_size--) { \
      uint64_t tmp = *p; \
      *p++ = *q; \
      *q++ = tmp; \
    } \
  } else { \
    /* Fallback for other sizes */ \
    uint8_t *p = (uint8_t *) a; \
    uint8_t *q = (uint8_t *) b; \
    while (val_size--) { \
      uint8_t tmp = *p; \
      *p++ = *q; \
      *q++ = tmp; \
    } \
  }

#define HEAP_FUNC_COPY(dst, src, val_size) \
  /* Copy elements based on their size (optimized for 64-bit values) */ \
  if ((val_size & 7) == 0) { \
    uint64_t *p = (uint64_t *) src; \
    uint64_t *q = (uint64_t *) dst; \
    val_size /= sizeof (uint64_t); \
    while (val_size--) { \
      *q++ = *p++; \
    } \
  } else { \
    /* Fallback for other sizes */ \
    uint8_t *p = (uint8_t *) src; \
    uint8_t *q = (uint8_t *) dst; \
    while (val_size--) { \
      *q++ = *p++; \
    } \
  }

#define HEAP_FUNC_CMP(a, b) \
  /* Compare two values based on their size (optimized for 64-bit values) */ \
  if ((val_size & 7) == 0) { \
    uint64_t *p = (uint64_t *) a; \
    uint64_t *q = (uint64_t *) b; \
    val_size /= sizeof (uint64_t); \
    while (val_size--) { \
      if (*p < *q) return -1; \
      if (*p > *q) return 1; \
      p++; \
      q++; \
    } \
    return 0; \
  } else { \
    /* Fallback for other sizes */ \
    uint8_t *p = (uint8_t *) a; \
    uint8_t *q = (uint8_t *) b; \
    while (val_size--) { \
      if (*p < *q) return -1; \
      if (*p > *q) return 1; \
      p++; \
      q++; \
    } \
    return 0; \
  }

#define HEAP_FUNC_CMP_EDGE(a, b) \
  /* Compare two edges based on their cost */ \
  if (((edge *)a)->c < ((edge *)b)->c) return -1; \
  if (((edge *)a)->c > ((edge *)b)->c) return 1; \
  return 0;

#define HEAP_FUNC_CMP_INDEX_VAL(a, b) \
  /* Compare two index-value pairs based on their value */ \
  if (((index_val *)a)->val < ((index_val *)b)->val) return -1; \
  if (((index_val *)a)->val > ((index_val *)b)->val) return 1; \
  return 0;

#define HEAP_FUNC_CMP_SEGMENT_NODE(a, b) \
  /* Compare two segment nodes based on their value */ \
  if (((segment_node *)a)->val < ((segment_node *)b)->val) return -1; \
  if (((segment_node *)a)->val > ((segment_node *)b)->val) return 1; \
  return 0;

#define HEAP_FUNC_CMP_UNION_FIND(a, b) \
  /* Compare two Union-Find structures based on their size */ \
  if (((UnionFind *)a)->size < ((UnionFind *)b)->size) return -1; \
  if (((UnionFind *)a)->size > ((UnionFind *)b)->size) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID(a, b) \
  /* Compare two void pointers based on their value */ \
  if (((void **)a)[0] < ((void **)b)[0]) return -1; \
  if (((void **)a)[0] > ((void **)b)[0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_I32(a, b) \
  /* Compare two i32 values */ \
  if (*((i32 *)a) < *((i32 *)b)) return -1; \
  if (*((i32 *)a) > *((i32 *)b)) return 1; \
  return 0;

#define HEAP_FUNC_CMP_I64(a, b) \
  /* Compare two i64 values */ \
  if (*((i64 *)a) < *((i64 *)b)) return -1; \
  if (*((i64 *)a) > *((i64 *)b)) return 1; \
  return 0;

#define HEAP_FUNC_CMP_SIZE_T(a, b) \
  /* Compare two size_t values */ \
  if (*((size_t *)a) < *((size_t *)b)) return -1; \
  if (*((size_t *)a) > *((size_t *)b)) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR(a, b) \
  /* Compare two void pointers based on their value */ \
  if (((void **)a)[0] < ((void **)b)[0]) return -1; \
  if (((void **)a)[0] > ((void **)b)[0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR_PTR(a, b) \
  /* Compare two void pointer pointers based on their value */ \
  if (((void ***)a)[0][0] < ((void ***)b)[0][0]) return -1; \
  if (((void ***)a)[0][0] > ((void ***)b)[0][0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR_PTR_PTR(a, b) \
  /* Compare two void pointer pointers based on their value */ \
  if (((void ****)a)[0][0][0] < ((void ****)b)[0][0][0]) return -1; \
  if (((void ****)a)[0][0][0] > ((void ****)b)[0][0][0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR_PTR_PTR_PTR(a, b) \
  /* Compare two void pointer pointers based on their value */ \
  if (((void *****)a)[0][0][0][0] < ((void *****)b)[0][0][0][0]) return -1; \
  if (((void *****)a)[0][0][0][0] > ((void *****)b)[0][0][0][0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR_PTR_PTR_PTR_PTR(a, b) \
  /* Compare two void pointer pointers based on their value */ \
  if (((void ******)a)[0][0][0][0][0] < ((void ******)b)[0][0][0][0][0]) return -1; \
  if (((void ******)a)[0][0][0][0][0] > ((void ******)b)[0][0][0][0][0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR_PTR_PTR_PTR_PTR_PTR(a, b) \
  /* Compare two void pointer pointers based on their value */ \
  if (((void *******)a)[0][0][0][0][0][0] < ((void *******)b)[0][0][0][0][0][0]) return -1; \
  if (((void *******)a)[0][0][0][0][0][0] > ((void *******)b)[0][0][0][0][0][0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR_PTR_PTR_PTR_PTR_PTR_PTR(a, b) \
  /* Compare two void pointer pointers based on their value */ \
  if (((void ********)a)[0][0][0][0][0][0][0] < ((void ********)b)[0][0][0][0][0][0][0]) return -1; \
  if (((void ********)a)[0][0][0][0][0][0][0] > ((void ********)b)[0][0][0][0][0][0][0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR_PTR_PTR_PTR_PTR_PTR_PTR_PTR(a, b) \
  /* Compare two void pointer pointers based on their value */ \
  if (((void *********)a)[0][0][0][0][0][0][0][0] < ((void *********)b)[0][0][0][0][0][0][0][0]) return -1; \
  if (((void *********)a)[0][0][0][0][0][0][0][0] > ((void *********)b)[0][0][0][0][0][0][0][0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR_PTR_PTR_PTR_PTR_PTR_PTR_PTR_PTR(a, b) \
  /* Compare two void pointer pointers based on their value */ \
  if (((void **********)a)[0][0][0][0][0][0][0][0][0] < ((void **********)b)[0][0][0][0][0][0][0][0][0]) return -1; \
  if (((void **********)a)[0][0][0][0][0][0][0][0][0] > ((void **********)b)[0][0][0][0][0][0][0][0][0]) return 1; \
  return 0;

#define HEAP_FUNC_CMP_VOID_PTR_PTR_PTR_PTR_PTR_PTR_PTR_PTR_PTR_PTR(a, b) \
  /* Compare two void pointer pointers based on their value */ \
  if (((void ***********)a)[0