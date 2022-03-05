#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> path;
vector<vector<int> > path2;
int n;
int ch[2000] = {0};
vector<int> map[2000];
int cnt[2000] = {0};
int max_list = 0;
int max_cnt = 0;
int max_i = 0;
int max_i_list = 0;
int max_list_i = 0;
void DFS(int x)
{
    if(ch[x] == 0)
    {
        ch[x] = 1;
        path.push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        if(x == map[i][0] && ch[i] == 0)
        {
            DFS(i);
        }
    }
    int y = map[x][0];
    if(ch[y] == 0)
    {
        DFS(y);
    }
}
int main()
{
    int a, b;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a>>b;
        map[a].push_back(b);
    }
    path.clear();
    for(int i=1; i<=n; i++)
    {
        if(ch[i] == 0)
        {
            DFS(i);
            path2.push_back(path);
            path.clear();
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == map[j][0] && j == map[i][0])
            {
                cnt[i]++;
            }
            else if(i == map[j][0] && j != map[i][0])
            {
                cnt[i]++;
                cnt[j]++;
            }
            else if(map[i][0] != j && map[j][0] == i)
            {
                cnt[j]++;
                cnt[i]++;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(max_cnt < cnt[i])
        {
            max_cnt = cnt[i];
            max_i = i;
        }
        if(max_cnt == cnt[i] && max_i != i)
        {
            max_i = 0;
        }
    }
    for(int i=0; i<path2.size(); i++)
    {
        if(max_list < path2[i].size())
        {
            max_list = path2[i].size();
            max_list_i = i;
        }
        for(int j=0; j<path2[i].size(); j++)
        {
            if(max_i == path2[i][j])
            {
                max_i_list = path2[i].size();
            }
        }
    }
    if(max_i != 0)
    {
        cout<<max_i<<" "<<max_i_list<<endl;
    }
    else
    {
        cout<<0<<" "<<0<<endl;
    }
    cout<<max_list<<endl;
    cout<<path2.size()<<endl;
    return 0;
}