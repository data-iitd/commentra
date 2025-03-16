#include <stdio.h>
#include <stdlib.h>

// Function to read input as a list of integers
int *_input()
{
    int n, m, *arr, i;
    scanf("%d %d", &n, &m);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to print the list 'arr' of size 'n'
void _print(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the list 'arr' of size 'n'
void _sort(int *arr, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to find the frequency of each element in the list 'arr' of size 'n'
int *_freq(int *arr, int n)
{
    int i, j, *freq, count;
    freq = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        freq[i] = count;
    }
    return freq;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
        count++;
    }
    return count;
}

// Function to find the number of elements that have a smaller frequency than the current element
int _smaller(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (freq[j] < freq[i])
        {
            count++;
        }
    }
    return count;
}

// Function to find the number of elements that have not been processed yet
int _unprocessed(int *freq, int n, int i)
{
    int j, count = 0;
    for (j = i + 1; j < n; j++)
    {
       