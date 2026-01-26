#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

int arr[10];
bool visited[10]={0};
int picked[10];
unordered_set<string> ans;
int N,K;

void recur(int len);

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    recur(0);
    cout<<ans.size();
    return 0;
}

void recur(int len){
    if(len==K){
        string tmp;

        for(int i=0;i<K;i++){
            tmp+=to_string(picked[i]);
        }

        ans.insert(tmp);

        return;
    }

    for(int i=0;i<N;i++){
        if(visited[i]) continue;

        picked[len]=arr[i];

        visited[i]=true;
        recur(len+1);
        visited[i]=false;
    }
    
    return;
}

