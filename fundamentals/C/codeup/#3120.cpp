#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

	int a=0, b=0;
	scanf("%d%d", &a, &b);

	int result = 0;
	result += abs(a-b)/10;

	int c = abs(a-b)%10;
	if(c==1||c==5) result+=1;
	else if(c==2||c==4||c==6||c==9) result+=2;
	else if(c==3||c==7||c==8) result+=3;

	printf("%d", result);

	return 0;
}