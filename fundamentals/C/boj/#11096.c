#include <stdio.h>
#include <string.h>

char player[1000000];
char name[1000000];

int main(void){
  int T, num;
  int salary;
  int max;
  scanf("%d", &T);

 for(int i = 0; i < T; i++) {
   salary = 0;
   max = -99999999;
   scanf("%d", &num);
   for(int j = 0; j < num; j++){
      scanf("%d %s", &salary, name);
      if(max < salary){
        max = salary;
        strcpy(player, name);
      }
   }
   printf("%s\n", player);
 }


}
