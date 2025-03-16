import sys

# get_next_string reads the next string from the input.
def get_next_string():
	return sys.stdin.readline().strip()

# get_next_int reads the next integer from the input.
def get_next_int():
	return int(get_next_string())

# get_next_int64 reads the next 64-bit integer from the input.
def get_next_int64():
	return int(get_next_string())

# get_next_uint64 reads the next 64-bit unsigned integer from the input.
def get_next_uint64():
	return int(get_next_string())

# get_next_float64 reads the next 64-bit float from the input.
def get_next_float64():
	return float(get_next_string())

# get_next_int_array reads the next int array from the input.
def get_next_int_array():
	return [int(x) for x in get_next_string().split()]

# get_next_int64_array reads the next 64-bit int array from the input.
def get_next_int64_array():
	return [int(x) for x in get_next_string().split()]

# get_next_uint64_array reads the next 64-bit unsigned int array from the input.
def get_next_uint64_array():
	return [int(x) for x in get_next_string().split()]

# get_next_float64_array reads the next 64-bit float array from the input.
def get_next_float64_array():
	return [float(x) for x in get_next_string().split()]

# get_next_string_array reads the next string array from the input.
def get_next_string_array():
	return get_next_string().split()

# get_next_string_matrix reads the next string matrix from the input.
def get_next_string_matrix():
	return [get_next_string_array() for _ in range(get_next_int())]

# get_next_int_matrix reads the next int matrix from the input.
def get_next_int_matrix():
	return [get_next_int_array() for _ in range(get_next_int())]

# get_next_int64_matrix reads the next 64-bit int matrix from the input.
def get_next_int64_matrix():
	return [get_next_int64_array() for _ in range(get_next_int())]

# get_next_uint64_matrix reads the next 64-bit unsigned int matrix from the input.
def get_next_uint64_matrix():
	return [get_next_uint64_array() for _ in range(get_next_int())]

# get_next_float64_matrix reads the next 64-bit float matrix from the input.
def get_next_float64_matrix():
	return [get_next_float64_array() for _ in range(get_next_int())]

# get_next_int_array_matrix reads the next int array matrix from the input.
def get_next_int_array_matrix():
	return [get_next_int_array() for _ in range(get_next_int())]

# get_next_int64_array_matrix reads the next 64-bit int array matrix from the input.
def get_next_int64_array_matrix():
	return [get_next_int64_array() for _ in range(get_next_int())]

# get_next_uint64_array_matrix reads the next 64-bit unsigned int array matrix from the input.
def get_next_uint64_array_matrix():
	return [get_next_uint64_array() for _ in range(get_next_int())]

# get_next_float64_array_matrix reads the next 64-bit float array matrix from the input.
def get_next_float64_array_matrix():
	return [get_next_float64_array() for _ in range(get_next_int())]

# get_next_int_matrix_matrix reads the next int matrix matrix from the input.
def get_next_int_matrix_matrix():
	return [get_next_int_matrix() for _ in range(get_next_int())]

# get_next_int64_matrix_matrix reads the next 64-bit int matrix matrix from the input.
def get_next_int64_matrix_matrix():
	return [get_next_int64_matrix() for _ in range(get_next_int())]

# get_next_uint64_matrix_matrix reads the next 64-bit unsigned int matrix matrix from the input.
def get_next_uint64_matrix_matrix():
	return [get_next_uint64_matrix() for _ in range(get_next_int())]

# get_next_float64_matrix_matrix reads the next 64-bit float matrix matrix from the input.
def get_next_float64_matrix_matrix():
	return [get_next_float64_matrix() for _ in range(get_next_int())]

# get_next_int_matrix_array reads the next int matrix array from the input.
def get_next_int_matrix_array():
	return [get_next_int_matrix() for _ in range(get_next_int())]

# get_next_int64_matrix_array reads the next 64-bit int matrix array from the input.
def get_next_int64_matrix_array():
	return [get_next_int64_matrix() for _ in range(get_next_int())]

# get_next_uint64_matrix_array reads the next 64-bit unsigned int matrix array from the input.
def get_next_uint64_matrix_array():
	return [get_next_uint64_matrix() for _ in range(get_next_int())]

# get_next_float64_matrix_array reads the next 64-bit float matrix array from the input.
def get_next_float64_matrix_array():
	return [get_next_float64_matrix() for _ in range(get_next_int())]

# get_next_int_array_matrix_array reads the next int array matrix array from the input.
def get_next_int_array_matrix_array():
	return [get_next_int_matrix_array() for _ in range(get_next_int())]

# get_next_int64_array_matrix_array reads the next 64-bit int array matrix array from the input.
def get_next_int64_array_matrix_array():
	return [get_next_int64_matrix_array() for _ in range(get_next_int())]

# get_next_uint64_array_matrix_array reads the next 64-bit unsigned int array matrix array from the input.
def get_next_uint64_array_matrix_array():
	return [get_next_uint64_matrix_array() for _ in range(get_next_int())]

# get_next_float64_array_matrix_array reads the next 64-bit float array matrix array from the input.
def get_next_float64_array_matrix_array():
	return [get_next_float64_matrix_array() for _ in range(get_next_int())]

# get_next_int_matrix_matrix_array reads the next int matrix matrix array from the input.
def get_next_int_matrix_matrix_array():
	return [get_next_int_matrix_matrix() for _ in range(get_next_int())]

# get_next_int64_matrix_matrix_array reads the next 64-bit int matrix matrix array from the input.
def get_next_int64_matrix_matrix_array():
	return [get_next_int64_matrix_matrix() for _ in range(get_next_int())]

# get_next_uint64_matrix_matrix_array reads the next 64-bit unsigned int matrix matrix array from the input.
def get_next_uint64_matrix_matrix_array():
	return [get_next_uint64_matrix_matrix() for _ in range(get_next_int())]

# get_next_float64_matrix_matrix_array reads the next 64-bit float matrix matrix array from the input.
def get_next_float64_matrix_matrix_array():
	return [get_next_float64_matrix_matrix() for _ in range(get_next_int())]

# get_next_int_matrix_matrix_matrix reads the next int matrix matrix matrix from the input.
def get_next_int_matrix_matrix_matrix():
	return [get_next_int_matrix_matrix() for _ in range(get_next_int())]

# get_next_int64_matrix_matrix_matrix reads the next 64-bit int matrix matrix matrix from the input.
def get_next_int64_matrix_matrix_matrix():
	return [get_next_int64_matrix_matrix() for _ in range(get_next_int())]

# get_next_uint64_matrix_matrix_matrix reads the next 64-bit unsigned int matrix matrix matrix from the input.
def get_next_uint64_matrix_matrix_matrix():
	return [get_next_uint64_matrix_matrix() for _ in range(get_next_int())]

# get_next_float64_matrix_matrix_matrix reads the next 64-bit float matrix matrix matrix from the input.
def get_next_float64_matrix_matrix_matrix():
	return [get_next_float64_matrix_matrix() for _ in range(get_next_int())]

# get_next_int_matrix_matrix_matrix_array reads the next int matrix matrix matrix array from the input.
def get_next_int_matrix_matrix_matrix_array():
	return [get_next_int_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_int64_matrix_matrix_matrix_array reads the next 64-bit int matrix matrix matrix array from the input.
def get_next_int64_matrix_matrix_matrix_array():
	return [get_next_int64_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_uint64_matrix_matrix_matrix_array reads the next 64-bit unsigned int matrix matrix matrix array from the input.
def get_next_uint64_matrix_matrix_matrix_array():
	return [get_next_uint64_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_float64_matrix_matrix_matrix_array reads the next 64-bit float matrix matrix matrix array from the input.
def get_next_float64_matrix_matrix_matrix_array():
	return [get_next_float64_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_int_matrix_matrix_matrix_matrix reads the next int matrix matrix matrix matrix from the input.
def get_next_int_matrix_matrix_matrix_matrix():
	return [get_next_int_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_int64_matrix_matrix_matrix_matrix reads the next 64-bit int matrix matrix matrix matrix from the input.
def get_next_int64_matrix_matrix_matrix_matrix():
	return [get_next_int64_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_uint64_matrix_matrix_matrix_matrix reads the next 64-bit unsigned int matrix matrix matrix matrix from the input.
def get_next_uint64_matrix_matrix_matrix_matrix():
	return [get_next_uint64_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_float64_matrix_matrix_matrix_matrix reads the next 64-bit float matrix matrix matrix matrix from the input.
def get_next_float64_matrix_matrix_matrix_matrix():
	return [get_next_float64_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_int_matrix_matrix_matrix_matrix_array reads the next int matrix matrix matrix matrix array from the input.
def get_next_int_matrix_matrix_matrix_matrix_array():
	return [get_next_int_matrix_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_int64_matrix_matrix_matrix_matrix_array reads the next 64-bit int matrix matrix matrix matrix array from the input.
def get_next_int64_matrix_matrix_matrix_matrix_array():
	return [get_next_int64_matrix_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_uint64_matrix_matrix_matrix_matrix_array reads the next 64-bit unsigned int matrix matrix matrix matrix array from the input.
def get_next_uint64_matrix_matrix_matrix_matrix_array():
	return [get_next_uint64_matrix_matrix_matrix_matrix() for _ in range(get_next_int())]

# get_next_float64_matrix_matrix_matrix_matrix_array reads the next 64-bit float matrix matrix matrix matrix array from the input.
def get_next_float64_matrix_matrix_matrix_matrix_array():
	ret