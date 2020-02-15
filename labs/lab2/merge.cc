#include "merge.h"

void sort_array(int* arr, int l, int r) {
  // base case
  if (l >= r) {
    return;
  }

  int pivot = arr[r];
  int cnt = l;

  for (int i = l; i <= r; i++) {
    // if element is less than or equal to pivot value
    if (arr[i] <= pivot) {
      swap(&arr[cnt], &arr[i]);
      cnt++;
    }
  }

  // sort left
  sort_array(arr, l, cnt-2);
  // sort right
  sort_array(arr, cnt, r);
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void merge_2(int* a, int* b, int n, int* c) {
  // merge a and b into c
  std::copy(a, a + n, c);
  std::copy(b, b + n, c + n);
  
  // sort c
  sort_array(c, 0, 2*n);
}

void merge_1(int* a, int low, int mid, int high) {
  int* temp1;
  int* temp2;
  temp1 = new int[mid+1];
  temp2 = new int[high-mid];

  std::copy(a, a + mid, temp1);
  std::copy(a + mid + 1, a + high, temp2);
  print_array(temp1, 3);
  print_array(temp2, 3);

  merge_2(temp1, temp2, mid+1, a);

  delete [] temp1;
  delete [] temp2;
}

void print_array(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
