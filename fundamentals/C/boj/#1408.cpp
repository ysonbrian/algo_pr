#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int h;
    int m;
    int s;
}Time;

int getSum(Time t) {
    int sum = t.h * 3600 + t.m * 60 + t.s;
    return sum;
}

int main() {

    Time current, mission;

    scanf("%d:%d:%d", &current.h, &current.m, &current.s);
    scanf("%d:%d:%d", &mission.h, &mission.m, &mission.s);

    int curSum = getSum(current);
    int misSum = getSum(mission);
    int temp = misSum - curSum;
    if(curSum < misSum) {
        printf("%02d:%02d:%02d", temp / 3600, temp % 3600 / 60, temp % 60);
    }
    else {
        temp = 24 * 3600 - curSum + misSum;
        printf("%02d:%02d:%02d", temp / 3600, temp % 3600 / 60, temp % 60);
    }

    return 0;
}
