#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100000] ={};

void print_at_depth_d(int root, int par,int d) {

    if(d==0) {
        cout<<root<<' ';
        return  ;
    }

    for(int nb:adj[root] ) {

        if(nb!=par) {
            print_at_depth_d(nb,root,d-1) ;
        }
    }
}

void dfs(int root, int par) {

    cout<<root<<' ';
    for(int nb:adj[root]) {
        if(nb!=par) {
            dfs(nb,root) ;
        }
    }

}

void bfs(int root){

    queue<int> q ;
    q.push(root) ;
    q.push(-1 ) ;
    while(q.size()) {
        if(q.front()==-1) {
            cout<<endl;
            continue ;
        }   

        cout<<q.front()<<' ';
        for(int i : adj[q.front()]) {
            q.push(i) ;
        }
        q.pop() ;
        q.push(-1) ;
    }

}

int main() {

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++) {
        int a,b; cin>>a>>b;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }

    // root -> 1
    bfs(1) ;
    dfs(1,-1) ;

}

