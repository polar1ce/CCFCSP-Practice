#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

int main()
{
    int i, j = 0, last = 0;
    char isbn[13];

    time_t begin = clock();
    cin >> isbn;
    time_t end = clock();
    printf("inputtime:%f", double(end - begin)/CLOCKS_PER_SEC);

    int num[10];
    for(i = 0; i < 13; i++)
        if(isbn[i] != '-')
            num[j++] = isbn[i] - '0';
    for(i = 0; i < 9; i++)
        last += num[i] * (i + 1);
    last = last % 11;
    if(last == num[9])
        cout << "Right" << endl;
    else {
        isbn[12] = (char)('0' + last);
        cout << isbn[12] << endl;
        cout << (string)isbn << endl;
    }
    return 0;
}
