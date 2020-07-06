#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sum = 0;
  int c;
  for(c = 0; c < n; c++){
    sum += A[c]/x;
  }
  return sum < k;//最後に0になるxが求める答え
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 100000000;
  if(p(1000000000) != 0){//全部0なら右端を取ればよい
    while(ub - lb > 1){
      int mid = (lb + ub)/2;
      if(p(mid)){
        ub = mid;
      }
      else{
        lb = mid;
      }
    }
    ub -= 1;
  }
  printf("%d\n",ub);

  return 0;
}
