#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int map[800][800], ch[800][800];
int dx[4] = {-1, 0, 1, 0}; // 이방법 유용함
int dy[4] = {0, 1, 0, -1};
int m, n;
int main()
{
    cin>>m>>n;
    string k;
    int num;
    int xxx=0;
    int yyy=0;
    int cnt = 0;
    vector<string> vk;
    while(true)
    {
        cin>>k;
        if(k == "-1")
        {
            break;
        }
        else
        {
            vk.push_back(k);
        }
    }
    for(int i=0; i<vk.size(); i++)
    {
        for(int j=0; j<vk[i].size(); j++)
        {
            num = vk[i][j] - 48;
            map[xxx][yyy] = num;
            yyy++;
            if(yyy == m)
            {
                xxx++;
                yyy = 0;
            }
        }
    }
    queue<pair<int, int> > Q;
    Q.push(make_pair(0,0));
    map[0][0] = 2;
    while(!Q.empty())
    {
        pair<int, int> tmp = Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int x = tmp.first +dx[i];
            int y = tmp.second+dy[i];
            if(x >=0 && x<m && y>=0 && y<n && map[x][y] == 0)
            {
                Q.push(make_pair(x, y));
                map[x][y] = 2;
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j]==2)
            {
                cnt++;
            }
        }
    }
    cout<<m*n-cnt<<endl;
    return 0;
}
// bfs를 사용해서 품
// bfs는 넓은곳을 향해 가고 dfs는 깊이를 깊게 들어감
// 문자열을 숫자로 바꿀때 아스키코드 사용하면 됨
// queue를 사용함 queue는 들어온순서대로 사용할 수 있음 스택은 들어갔다 나갔다지만
// 뒤로 넣고 앞으로 빼고 가능