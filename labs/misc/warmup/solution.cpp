
#include "solution.h"

int solution(int *arr, int N) {

#if 0
  int res = 0;
  for (int i = 0; i < N; i++) {
    res += arr[i];
  }
  return res;
#endif
  return (N * (N +1))/2 ;
}
