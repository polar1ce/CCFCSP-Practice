#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

int main()
{
    int n = 0, now, nt[4], j, k;
    long i, t = 0;

    time_t begin = clock();
    cin >> n;
    time_t end = clock();
    printf("inputtime:%f\n", double(end - begin)/CLOCKS_PER_SEC);

    //n不符合要求
    if(n < 4 || n > 1000) return 0;

    int *num = new int[n];
    for(i = 2013; i < pow(10, n); i++) {
        //分离各位数字
        for(j = 0, now = i; j < n; j++) {
            num[j] = now % 10;
            now = now / 10;
        }

        //首位不为0
        if(num[n - 1] == 0) continue;
        //nt记录0,1,2,3四个数出现次数，初始为0
        for(j = 0; j < 4; j++) nt[j] = 0;
        for(j = 0; j < n; j++) {
            if(num[j] < 0 || num[j] > 3) {
                nt[0] = 0;
                break;
            }
            nt[num[j]]++;
        }
        if(nt[0] < 1 || nt[1] < 1 || nt[2] < 1 || nt[3] < 1) continue;
        //0在1之前，2在3之前
        for(j = 0; j < n; j++)
            for(k = j + 1; k < n; k++) {
                if(num[j] == 0 && num[k] == 1 && k > j) nt[0] = 0;
                if(num[j] == 2 && num[k] == 3 && k > j) nt[0] = 0;
            }
        if(nt[0] == 0) continue;
        //满足条件
        cout << i << endl;
        t++;
        if(t > 1000000007) t -= 1000000007;
    }
    cout << t << endl;
    return 0;
}
