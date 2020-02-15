#include "merge.h"

using namespace std;

int main() {

  cout << "Part A\n" << endl;

  // Case 1
  int* result = new int[10];
  int in1[] = {23, 18, 23, 59, 10};
  int in2[] = {32, 78, 12, 1, 95};
  merge_2(in1, in2, 5, result);
  print_array(result, 10);
  delete [] result;

  // Case 2
  result = new int[6];
  int in3[] = {3, 6, 134};
  int in4[] = {-2, 99, 2};
  merge_2(in3, in4, 3, result);
  print_array(result, 6);
  delete [] result;


  cout << "\n Part B\n" << endl;
  int in5[] = {1, 4, 6, 2, 5, 9};
  merge_1(in5, 0, 2, 5);
  print_array(in5, 6);

  return 0;
}
