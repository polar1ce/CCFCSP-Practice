#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int n = 0, max, mt = 0, min = 999999, i;

    time_t begin = clock();
    cin >> n;
    int *arr = new int[n];
    for(i = 0; i < n; i++)
        cin >> arr[i];
    time_t end = clock();
    printf("inputtime:%f", double(end - begin)/CLOCKS_PER_SEC);

    max = arr[0];
    for(i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];

    int *t = new int[max];
    for(i = 0; i < n; i++)
        t[arr[i]] = 0;
    for(i = 0; i < n; i++)
        t[arr[i]]++;

    for(i = 0; i < n; i++)
        if(t[arr[i]] > mt)
            mt = t[arr[i]];

    for(i = 0; i < n; i++)
        if(t[arr[i]] == mt)
            if(arr[i] < min)
                min = arr[i];
    cout << min;

    delete[] arr;
    delete[] t;
    return 0;
}
