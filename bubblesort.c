/* To compile this program: gcc 321_bubble_sort.c -o 321_bubble_sort */
//test
#include  <stdio.h>
 
/* This one-function version of bubble sort is provided for reference. *
 * You are not required to implement this function.                    */
void bubble_sort_orig(int *a, int n)
{
  int done;
  int i, t;

  do {
    for (done = 1, i = 1; i < n; i++) {
      if (a[i - 1] > a[i]) {
        done = 0;
        t = a[i];
        a[i] = a[i - 1];
        a[i - 1] = t;
      }
    }
  } while (!done);
}

/* fill fills an array of length n with decreasing values from n - 1 to *
 * zero (reverse sorted order).                                         */
void fill(int *a, int n) {
  int i;
  
  for (i = 0; i < n; i++) {
    a[i] = n - i - 1;
  }
}

/* swap swaps the values at addresses p and q */
void swap(int *p, int *q)
{
  int tmp;

  tmp = *p;
  *p = *q;
  *q = tmp;
}

/* bs_swap_pass implements the inner loop of bubble sort.  It iterates *
 * over a, swapping any out-of-order pairs of neighboring elements.    *
 * This function returns the count of the number of swaps that         *
 * occurred.  Uses the swap function (above) to do the swaps.          */
int bs_swap_pass(int *a, int n)
{
  int num_swaps = 0;
  int i;
  
  for (i = 1; i < n; i++) {
    if (a[i - 1] > a[i]) {
      swap(&a[i - 1], &a[i]);
      num_swaps++;
    }
  }

  return num_swaps;
}

/* bubble_sort takes an array, a, and the number of elements in that *
 * array, n, and sorts them into non-decreasing order.  This version *
 * function implements only the outer loop of the standard bubble    *
 * sort algorithm (see bubble_sort_orig, above), calling             *
 * bs_swap_pass repeatedly until that function returns zero swaps.   */
void bubble_sort(int *a, int n)
{
  while (bs_swap_pass(a, n));
}

/* binary_search is an implementation of the standard recursive *
 * binary search algorithm.  It searches the array a between    *
 * the values of start (inclusive) and end (exclusive) for      *
 * value.  If value is found, its index is returned; otherwise  *
 * the function returns -1 to indicate failure.                 */
int binary_search(int *a, int start, int end, int value)
{
  int index;

  if (end < start) {
    return -1;
  }

  index = (start + end) / 2;

  if (a[index] == value) {
    return index;
  }
  if (a[index] > value) {
    return binary_search(a, start, index - 1, value);
  }
  return binary_search(a, index + 1, end, value);
}

/* Your main function should allocate space for an array, call fill to *
 * fill it with decreasing numbers, and then call bubble_sort to sort  *
 * it.  Use the HALT emulator instruction to see the memory contents   *
 * and confirm that your functions work.  You may choose any array     *
 * size you like (up to the default limit of memory, 4096 bytes or 512 *
 * 8-byte integers); the choice of 10000 here is arbitrary.            *
 *                                                                     * 
 * After sorting, call binary search with 4 values: the smallest,      *
 * largest, and middle items in your array, followed by a value not in *
 * the array.  After each call PRNT X0 to display the return value.    *
 *                                                                     *
 * After completing all of the above, HALT the emulator to force a     *
 * code dump so that you (and the TAs) can examing the contents of     *
 * memory.                                                             */
int main(int argc, char *argv[])
{
  int a[10000];

  fill(a, sizeof (a) / sizeof (a[0]));
  bubble_sort(a, sizeof (a) / sizeof (a[0]));
  /* Returns 0 */
  binary_search(a, 0, (sizeof (a) / sizeof (a[0])) - 1, 0);
  /* Returns 9999 */
  binary_search(a, 0, (sizeof (a) / sizeof (a[0])) - 1,
                sizeof (a) / sizeof (a[0]) - 1);
  /* Returns 5000 */
  binary_search(a, 0, (sizeof (a) / sizeof (a[0])) - 1,
                (sizeof (a) / sizeof (a[0])) / 2);
  /* Returns -1 */
  binary_search(a, 0, (sizeof (a) / sizeof (a[0])) - 1,
                sizeof (a) / sizeof (a[0]));
  
  return 0;
}