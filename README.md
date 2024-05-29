# Sorting Algorithms
#### 0. Shell sort - Knuth Sequence
Write a function that sorts an array of integers in ascending order using the [Shell sort](https://en.wikipedia.org/wiki/Shellsort) algorithm, using the `Knuth sequence`
- Prototype: `void shell_sort(int *array, size_t size);`
- You must use the following sequence of intervals (a.k.a the Knuth sequence):
    - `n+1 = n * 3 + 1`
    - `1, 4, 13, 40, 121, ...`
- You’re expected to print the `array` each time you decrease the interval (See example below).

**No big O notations of the time complexity of the Shell sort (Knuth sequence) algorithm needed - as the complexity is dependent on the size of array and gap**
```
alex@/tmp/sort$ cat 100-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic 100-main.c 100-shell_sort.c print_array.c -o shell
alex@/tmp/sort$ ./shell
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

13, 7, 96, 71, 19, 48, 99, 73, 86, 52
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```
#
#### Repo:
- GitHub repository: `atlas-sorting_algorithms`
- File: `100-shell_sort.c`
#
#### 1. Counting sort
Write a function that sorts an array of integers in ascending order using the [Counting sort](https://en.wikipedia.org/wiki/Counting_sort) algorithm
- Prototype: `void counting_sort(int *array, size_t size);`
- You can assume that `array` will contain only numbers `>= 0`
- You are allowed to use `malloc` and `free` for this task
- You’re expected to print your counting array once it is set up (See example below)
    - This array is of size `k + 1` where `k` is the largest number in `array`

Write in the file `102-O`, the big O notations of the time complexity of the Counting sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```
alex@/tmp/sort$ cat 102-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    counting_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic 102-main.c 102-counting_sort.c print_array.c -o counting
alex@/tmp/sort$ ./counting
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 10

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```
#
#### Repo:
- GitHub repository: `atlas-sorting_algorithms`
- File: `102-counting_sort.c, 102-O`
#
#### 2. Merge sort
Write a function that sorts an array of integers in ascending order using the [Merge sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm
- Prototype: `void merge_sort(int *array, size_t size);`
- You must implement the `top-down` merge sort algorithm
    - When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. `{1, 2, 3, 4, 5}` -> `{1, 2}, {3, 4, 5}`
    - Sort the left array before the right array
- You are allowed to use `printf`
- You are allowed to use `malloc` and `free` only once (only **one** call)
- Output: see example

Write in the file `103-O`, the big O notations of the time complexity of the Merge sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```
alex@/tmp/sort$ cat 103-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic 103-main.c 103-merge_sort.c print_array.c -o merge
alex@/tmp/sort$ ./merge
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
Merging...
[left]: 99
[right]: 13, 71
[Done]: 13, 71, 99
Merging...
[left]: 19, 48
[right]: 13, 71, 99
[Done]: 13, 19, 48, 71, 99
Merging...
[left]: 52
[right]: 96
[Done]: 52, 96
Merging...
[left]: 86
[right]: 7
[Done]: 7, 86
Merging...
[left]: 73
[right]: 7, 86
[Done]: 7, 73, 86
Merging...
[left]: 52, 96
[right]: 7, 73, 86
[Done]: 7, 52, 73, 86, 96
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```
#
#### Repo:
- GitHub repository: `atlas-sorting_algorithms`
- File: `103-merge_sort.c, 103-O`
#
#### 3. Heap sort [ADVANCED]
Write a function that sorts an array of integers in ascending order using the [Heap sort](https://en.wikipedia.org/wiki/Heapsort) algorithm
- Prototype: `void heap_sort(int *array, size_t size);`
- You must implement the `sift-down` heap sort algorithm
- You’re expected to print the `array` after each time you swap two elements (See example below)

Write in the file `104-O`, the big O notations of the time complexity of the Heap sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```
alex@/tmp/sort$ cat 104-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    heap_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic 104-main.c 104-heap_sort.c print_array.c -o heap
alex@/tmp/sort$ ./heap
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 99, 86, 13, 52, 96, 73, 71, 7
19, 86, 99, 48, 13, 52, 96, 73, 71, 7
19, 86, 99, 73, 13, 52, 96, 48, 71, 7
99, 86, 19, 73, 13, 52, 96, 48, 71, 7
99, 86, 96, 73, 13, 52, 19, 48, 71, 7
7, 86, 96, 73, 13, 52, 19, 48, 71, 99
96, 86, 7, 73, 13, 52, 19, 48, 71, 99
96, 86, 52, 73, 13, 7, 19, 48, 71, 99
71, 86, 52, 73, 13, 7, 19, 48, 96, 99
86, 71, 52, 73, 13, 7, 19, 48, 96, 99
86, 73, 52, 71, 13, 7, 19, 48, 96, 99
48, 73, 52, 71, 13, 7, 19, 86, 96, 99
73, 48, 52, 71, 13, 7, 19, 86, 96, 99
73, 71, 52, 48, 13, 7, 19, 86, 96, 99
19, 71, 52, 48, 13, 7, 73, 86, 96, 99
71, 19, 52, 48, 13, 7, 73, 86, 96, 99
71, 48, 52, 19, 13, 7, 73, 86, 96, 99
7, 48, 52, 19, 13, 71, 73, 86, 96, 99
52, 48, 7, 19, 13, 71, 73, 86, 96, 99
13, 48, 7, 19, 52, 71, 73, 86, 96, 99
48, 13, 7, 19, 52, 71, 73, 86, 96, 99
48, 19, 7, 13, 52, 71, 73, 86, 96, 99
13, 19, 7, 48, 52, 71, 73, 86, 96, 99
19, 13, 7, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
13, 7, 19, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```
#
#### Repo:
- GitHub repository: `atlas-sorting_algorithms`
- File: `104-heap_sort.c, 104-O`
#
#### 4. Radix sort [ADVANCED]
Write a function that sorts an array of integers in ascending order using the Radix sort algorithm
- Prototype: `void radix_sort(int *array, size_t size);`
- You must implement the `LSD` radix sort algorithm
- You can assume that `array` will contain only numbers `>= 0`
- You are allowed to use `malloc` and `free` for this task
- You’re expected to print the `array` each time you increase your `significant digit` (See example below)
```
alex@/tmp/sort$ cat 105-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic 105-main.c 105-radix_sort.c print_array.c -o radix
alex@/tmp/sort$ ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```
#
#### Repo:
- GitHub repository: `atlas-sorting_algorithms`
- File: `105-radix_sort.c`
#
#### 5. Bitonic sort [ADVANCED]
Write a function that sorts an array of integers in ascending order using the [Bitonic sort](https://en.wikipedia.org/wiki/Bitonic_sorter) algorithm
- Prototype: `void bitonic_sort(int *array, size_t size);`
- You can assume that `size` will be equal to `2^k`, where `k >= 0` (when `array` is not `NULL` …)
- You are allowed to use `printf`
- You’re expected to print the `array` each time you swap two elements (See example below)
- Output: see example

Write in the file `106-O`, the big O notations of the time complexity of the Bitonic sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```
alex@/tmp/sort$ cat 106-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bitonic_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic 106-main.c 106-bitonic_sort.c print_array.c -o bitonic
alex@/tmp/sort$ ./bitonic
100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13

Merging [16/16] (UP):
100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13
Merging [8/16] (UP):
100, 93, 40, 57, 14, 58, 85, 54
Merging [4/16] (UP):
100, 93, 40, 57
Merging [2/16] (UP):
100, 93
Result [2/16] (UP):
93, 100
Merging [2/16] (DOWN):
40, 57
Result [2/16] (DOWN):
57, 40
Result [4/16] (UP):
40, 57, 93, 100
Merging [4/16] (DOWN):
14, 58, 85, 54
Merging [2/16] (UP):
14, 58
Result [2/16] (UP):
14, 58
Merging [2/16] (DOWN):
85, 54
Result [2/16] (DOWN):
85, 54
Result [4/16] (DOWN):
85, 58, 54, 14
Result [8/16] (UP):
14, 40, 54, 57, 58, 85, 93, 100
Merging [8/16] (DOWN):
31, 56, 46, 39, 15, 26, 78, 13
Merging [4/16] (UP):
31, 56, 46, 39
Merging [2/16] (UP):
31, 56
Result [2/16] (UP):
31, 56
Merging [2/16] (DOWN):
46, 39
Result [2/16] (DOWN):
46, 39
Result [4/16] (UP):
31, 39, 46, 56
Merging [4/16] (DOWN):
15, 26, 78, 13
Merging [2/16] (UP):
15, 26
Result [2/16] (UP):
15, 26
Merging [2/16] (DOWN):
78, 13
Result [2/16] (DOWN):
78, 13
Result [4/16] (DOWN):
78, 26, 15, 13
Result [8/16] (DOWN):
78, 56, 46, 39, 31, 26, 15, 13
Result [16/16] (UP):
13, 14, 15, 26, 31, 39, 40, 46, 54, 56, 57, 58, 78, 85, 93, 100

13, 14, 15, 26, 31, 39, 40, 46, 54, 56, 57, 58, 78, 85, 93, 100
alex@/tmp/sort$
```
#
#### Repo:
- GitHub repository: `atlas-sorting_algorithms`
- File: `106-bitonic_sort.c, 106-O`
#
#### 6. Quick Sort - Hoare Partition scheme [ADVANCED]
Write a function that sorts an array of integers in ascending order using the [Quick sort](https://en.wikipedia.org/wiki/Quicksort) algorithm
- Prototype: `void quick_sort_hoare(int *array, size_t size);`
- You must implement the `Hoare` partition scheme.
- The pivot should always be the last element of the partition being sorted.
- You’re expected to print the `array` after each time you swap two elements (See example below)

Write in the file `107-O`, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
```
alex@/tmp/sort$ cat 107-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort_hoare(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic 107-main.c 107-quick_sort_hoare.c print_array.c -o quick
alex@/tmp/sort$ ./quick
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

7, 48, 99, 71, 13, 52, 96, 73, 86, 19
7, 19, 99, 71, 13, 52, 96, 73, 86, 48
7, 19, 13, 71, 99, 52, 96, 73, 86, 48
7, 13, 19, 71, 99, 52, 96, 73, 86, 48
7, 13, 19, 48, 99, 52, 96, 73, 86, 71
7, 13, 19, 48, 71, 52, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 86, 73, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```
Another example of output:
```
alex@/tmp/sort$ ./quick_2
87, 65, 28, 63, 93, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 36, 71, 8, 45, 38

38, 65, 28, 63, 93, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 36, 71, 8, 45, 87
38, 8, 28, 63, 93, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 36, 71, 65, 45, 87
38, 8, 28, 36, 93, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 52, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 16, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 39, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 11, 52, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 11, 59, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 26, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 11, 26, 27, 30, 24, 83, 69, 62, 13, 6, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 11, 26, 27, 30, 24, 6, 69, 62, 13, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
38, 8, 28, 36, 21, 16, 11, 26, 27, 30, 24, 6, 13, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
13, 8, 28, 36, 21, 16, 11, 26, 27, 30, 24, 6, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
13, 8, 6, 36, 21, 16, 11, 26, 27, 30, 24, 28, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
13, 8, 6, 11, 21, 16, 36, 26, 27, 30, 24, 28, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
11, 8, 6, 13, 21, 16, 36, 26, 27, 30, 24, 28, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 21, 16, 36, 26, 27, 30, 24, 28, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 21, 16, 28, 26, 27, 30, 24, 36, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 21, 16, 28, 26, 27, 24, 30, 36, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 21, 16, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 88, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 87
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 87, 58, 92, 59, 42, 39, 52, 93, 75, 63, 71, 65, 45, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 87, 58, 45, 59, 42, 39, 52, 93, 75, 63, 71, 65, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 83, 87, 58, 45, 59, 42, 39, 52, 65, 75, 63, 71, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 71, 87, 58, 45, 59, 42, 39, 52, 65, 75, 63, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 69, 71, 63, 58, 45, 59, 42, 39, 52, 65, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 65, 71, 63, 58, 45, 59, 42, 39, 52, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 62, 65, 52, 63, 58, 45, 59, 42, 39, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 65, 52, 63, 58, 45, 59, 42, 62, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 62, 52, 63, 58, 45, 59, 42, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 62, 52, 42, 58, 45, 59, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 59, 52, 42, 58, 45, 62, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 45, 52, 42, 58, 59, 62, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 45, 42, 52, 58, 59, 62, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 71, 69, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 69, 71, 75, 87, 83, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 69, 71, 75, 83, 87, 93, 92, 88
6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 69, 71, 75, 83, 87, 88, 92, 93

6, 8, 11, 13, 16, 21, 24, 26, 27, 28, 30, 36, 38, 39, 42, 45, 52, 58, 59, 62, 63, 65, 69, 71, 75, 83, 87, 88, 92, 93
alex@/tmp/sort$ 
```
#
#### Repo:
- GitHub repository: `atlas-sorting_algorithms`
- File: `107-quick_sort_hoare.c, 107-O`
#
