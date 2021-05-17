
#include <iostream>
#include <string>

using namespace std;

 bool check[1000];

int main()
{

   int num;
   cin >> num;

   int number,strike,ball;
   string compareString,myNumber;
   int strike_cnt,ball_cnt;
   int count=0;

   // 123 to 999 find number that has same position.

   for(int i =0;i<num;i++) //rotate in num
   { // ex 4

      cin >>number >>strike >>ball;

      myNumber = to_string(number);

      for(int i =123;i<=998;i++)
      {
         compareString = to_string(i); // 123 124 to string

         if(compareString[0] == compareString[1] ||
               compareString[0] == compareString[2] ||
                  compareString[1] == compareString[2])
         {
            check[i]=true;
            continue;
         }

         if (compareString[0] - '0' == 0 ||
               compareString[1] - '0' == 0 ||
                   compareString[2] - '0' == 0)
               {
                  check[i] = true;
                  continue;
               }

         strike_cnt =0;
         ball_cnt =0;

         for(int x =0;x<3;x++)
            for(int y=0;y<3;y++)
            {
               if(x == y && compareString[y]== myNumber[x])
                  strike_cnt++;
               if(x != y && compareString[y] == myNumber[x])
                  ball_cnt++;
            }

         if(strike != strike_cnt || ball != ball_cnt)
            check[i]=true;


      }
   }

   for(int i =123;i<999;i++)
   {
      if(!check[i])
         count++;
   }

   cout<<count;

   return 0;
}