#include <iostream>

using namespace std;

int srch(int blk[m][n], int i, int j, int dir, bool end)
{
    if(blk[i][j] == 'T')
        end = true;

    //up
    if((blk[i][j] == '+' || blk[i][j] == '|') && i > 0)
        srch(blk, i - 1, j, 0, end);
    else dir++;

    //down
    if((blk[i][j] == '+' || blk[i][j] == '|' || blk[i][j] == '.') && i < m - 1)
        srch(blk, i + 1, j, 0, end);
    else dir++;

    //left
    if((blk[i][j] == '+' || blk[i][j] == '-') && j > 0)
        srch(blk, i, j - 1, 0, end);
    else dir++;

     //right
    if((blk[i][j] == '+' || blk[i][j] == '-') && j < n - 1)
        srch(blk, i, j + 1, 0, end);
    else dir++;

    if(blk[i][j] == 'S' && dir >= 4)
        cout << "I'm stuck!" << endl;

    if(blk[i][j] == '#' && dir >= 4 && end == false)
        t++;
}

int main()
{
    static int m = 0, n = 0, t = 0;
    int i, j;
    //输入地图行列数
    cin >> m;
    cin >> n;
    //创建地图数组
    char *blk = new char[m][n];
    //输入地图信息
    for(i = 0; i < m; i++)
    for(j = 0; j < n; j++) {
        cin >> blk[i][j];
    }

    for(i = 0; i < m; i++)
    for(j = 0; j < n; j++) {
        //查找初始位置
        if(blk[i][j] == 'S') {
            srch(blk, i, j, 0, false);
        }
    }
    cout << t << endl;

    return 0;
}
