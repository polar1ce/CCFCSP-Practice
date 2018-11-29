#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int n, i, j, s, maxS = 0, h0;

    time_t begin = clock();
    cin >> n;
    int *h = new int[n];
    for(i = 0; i < n; i++)
        cin >> h[i];
    time_t end = clock();
    printf("inputtime:%f", double(end - begin)/CLOCKS_PER_SEC);

    for(i = 0; i < n; i++) {
        h0 = h[i];
        for(j = i; j < n; j++) {
            if(h[j] < h0)
                h0 = h[j];
            s = h0 * (j - i + 1);
            if(s > maxS)
                maxS = s;
        }
    }
    cout << maxS;

    delete[] h;
    return 0;
}
