#include<bits/stdc++.h>
using namespace std;

class node{

    public: 
    int data;
    node* left;
    node* right;

    node(int d) {
        data= d;
        left=NULL, right=NULL ;
    }

};

node* input_level_order() {

    int d; cin>>d;
    if(d==-1) return NULL ;

    node* root = new node(d) ;
    queue<node*> q ;
    q.push(root) ;

    while(q.size()) {

        node* front = q.front() ;
        


    }


}

int main() {




}
