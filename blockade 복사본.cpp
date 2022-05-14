#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
int sum_second=0;
int all_N = 0;
void sum_av(vector<int> av_second){
    sum_second = 0;
    for(int i=0; i<N; i++){
        sum_second = sum_second + av_second[i];
    }
}
int main(){
    string a;
    int p;
    int m;
    vector<pair<string, vector<int> > > av;
    cin>>N;
    vector<int> tmp;
    while(true){
        cin>>a;
        if(a == "-1"){
            break;
        }
        tmp.resize(0);
        for(int j=0; j<N; j++){
            cin>>p;
            tmp.push_back(p);
        }
        av.push_back(make_pair(a, tmp));

    }
    int cnt=0;
    vector<int> one_cnt(101, 0);
    for(int i=0; i<N; i++){
        cnt = 0;
        for(int j=0; j<N; j++){
            if(av[i].second[j] == 0){
                cnt++;
            }
        }
        if(cnt == N-1){
            one_cnt[i] = 1;
        }
        if(cnt == N-2){
            one_cnt[i] = 2;
        }
    }
    cnt = 0;
    for(int i=0; i<N; i++){
        if(one_cnt[i] > 1){
            cnt++;
        }
    }
    if(cnt == N){
        cout<<"None"<<endl;
        return 0;
    }
    int max = 0;
    string first_av;
    int sum_second_av = 0;
    for(int i=0; i<N; i++){
        if(one_cnt[i] == 1){
            for(int j=0; j<N; j++){
                if(av[i].second[j] > 0){
                    sum_av(av[j].second);
                    sum_second_av = sum_second;
                }
                if(sum_second_av > max){
                    max = sum_second_av;
                    first_av = av[j].first;
                }
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        if(one_cnt[i] == 2)
        {
            vector<pair<string, vector<int> > > tmp = av;
            for(int j=0; j<N; j++)
            {
                int ch[101] = {0};
                if(tmp[i].second[j]>0)
                {
                    tmp[i].second[j] = 0;
                }
                queue<int> Q;
                Q.push(i);
                ch[i] = 1;
                while(!Q.empty())
                {
                    int I = Q.front();
                    Q.pop();
                    for(int j=0; j<N; j++)
                    {
                        if(tmp[I].second[j]>0 && ch[j] == 0)
                        {
                            Q.push(j);
                            ch[j] = 1;
                            all_N++;
                        }
                    }
                }
                if(all_N != N-1)
                {
                    sum_av(av[j].second);
                    sum_second_av = sum_second;
                }
                if(sum_second_av > max){
                    max = sum_second_av;
                    first_av = av[j].first;
                }
                all_N=0;
                tmp[i].second[j] = av[i].second[j];
            }
        }
    }
    cout<<first_av<<endl;
    return 0;
}