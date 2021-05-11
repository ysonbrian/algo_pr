#include <stdio.h>


int main(void){
  int M, N;
  scanf("%d", &M);
  scanf("%d", &N);
  int total = 0;
  int min = 9999999;
  for(int i = 0; i <=N; i++){
    if(i*i >= M && i*i <= N) {
      if(min > i*i) {
        min = i*i;
      }
      total += i*i;
    }
  }
  if(!total) {
    printf("-1\n");
  } else {
    printf("%d\n%d", total, min);
  }

}
