#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<pii> vc;
vector<pii> vec;
int main()
{
    int K, x, y;
    cin>>K;
    for(int i=0; i<K; i++)
    {
        cin>>x>>y;
        vc.push_back(make_pair(x, y));
    }
    int tmp=0;
    for(int i=0; i<5; i++)
    {
        cin>>tmp;
        x = vc[0].first;
        y = vc[0].second;
        int n = 1;
        for(int j=0; j<tmp; j++)
        {
            if(n == K)
            {
                n = 0;
            }
            if((x < vc[n].first) && (y==vc[n].second))
            {
                x++;
                if(x == vc[n].first)
                {
                    n++;
                }
            }
            else if((x == vc[n].first) && (y < vc[n].second))
            {
                y++;
                if(y == vc[n].second)
                {
                    n++;
                }
            }
            else if((x > vc[n].first) && (y==vc[n].second))
            {
                x--;
                if(x == vc[n].first)
                {
                    n++;
                }
            }
            else if((x == vc[n].first) && (y > vc[n].second))
            {
                y--;
                if(y == vc[n].second)
                {
                    n++;
                }
            }
        }
        vec.push_back(make_pair(x, y));
    }
    for(int i=0; i<5; i++)
    {
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    return 0;
}