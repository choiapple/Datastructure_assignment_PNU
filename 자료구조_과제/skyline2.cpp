#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int O[1000000] = {0, };
typedef pair<int, int> pii;
vector<pair<int, pii> > vc;
int main()
{
    int n;
    int x,v,h;
    int cnt=0;
    cin>>n;
    vector<int> K;
    for(int i=0; i<n; i++)
    {
        cin>>x>>v>>h;
        vc.push_back(make_pair(x,make_pair(v,h))); //세개 다받음
        if(cnt<x+h)
        {
            cnt = x+h;
        }
    }
    sort(vc.begin(),vc.end()); // x좌표를 기준으로 정렬
    for(int i=0; i<n; i++)
    {
        for(int j=vc[i].first; j<vc[i].first+vc[i].second.second; j++)
        {
            if(O[j]<vc[i].second.first)
            {
                O[j] = vc[i].second.first; // O배열을 x좌표로 생각하고 높이를 저장
            }
        }
    }
    K.push_back(vc[0].first);
    K.push_back(O[vc[0].first]);
    int cnt_2 = 1;
    for(int i=vc[0].first; i<cnt; i++)
    {
        if(O[i] == O[i+1])
        {
            cnt_2++; // 같은높이면 길이를 더함
        }
        else
        {
            K.push_back(cnt_2); // 달라지면 길이 저장하고
            K.push_back(O[i+1]-O[i]); // 달라지는 값을 넣음 -,+든
            cnt_2 = 1; // 그리고 초기화
        }
    }
    for(int i=0; i<K.size(); i++)
    {
        cout<<K[i]<<" "; // 하나씩 출력
    }
    cout<<endl;
    return 0;
}