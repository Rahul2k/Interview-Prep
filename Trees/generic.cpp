#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Treenode {

    public :
    T data;
    vector<Treenode<T>*> children ;

    Treenode(T data) {
        this->data=  data ;
    }

    ~Treenode() {

        for(int i=0;i<children.size();i++) {
            delete children[i] ;
        }
    }

};

void delete_tree(Treenode<int>* root) {

    if(root==NULL) return ;

    for(auto i : root->children) {

        delete_tree(i) ;
    }
    delete root ;

}

void print_at_depth_d(Treenode<int>* root,int d) {

    if(d==0) {cout<<root->data<<' '; return ;}
    for(auto i:root->children) {
        print_at_depth_d(i,d-1) ;
    }
}

int count_leaf_nodes(Treenode<int>* root) {

    if(root->children.size()==0) {
        return 1;
    }

    int cnt = 0 ;
    for(auto i: root->children) {
        cnt += count_leaf_nodes(i) ; 
    }

    return cnt ;
}

int count_nodes(Treenode<int>* root) {

    int cnt = 1;
    int n = root->children.size() ;

    for(int i=0;i<n;i++) {
        cnt+=count_nodes(root->children[i]) ;
    }    

    return cnt ;
}

int height(Treenode<int>* root) {

    if(root==NULL) return 0;
    int h = 0;

    for(auto i: root->children) {

        h = max(h,height(i)) ;
    }

    return h + 1;
}

Treenode<int>* input_level_order() {

    int d; cin>>d;
    Treenode<int>* root = new Treenode<int>(d) ;

    queue<Treenode<int>*> q ;
    q.push(root) ;

    while(q.size()) {

        Treenode<int>* curr = q.front() ;
        q.pop() ;
        cout<<"Enter no. of children for "<<curr->data<<"th node\n" ;
        
        int n; cin>>n;
        for(int i=0;i<n;i++) {
            cout<<"Enter "<<i<<"th child of "<<curr->data<<endl;
            int c; cin>>c;
            Treenode<int>* child  = new Treenode<int>(c) ;
            q.push(child) ;
            curr->children.push_back(child) ;
        }
    }

    return root;
}

void level_order_traversal(Treenode<int>* root) {

    queue<Treenode<int>*> q ;

    q.push(root) ;
    q.push(NULL) ;
    while(q.size()) {

        if(q.front()==NULL) {
            cout<<endl;
            q.pop() ;
            continue ;
        }
        cout<<q.front()->data<<' ';
        for(auto i:q.front()->children) {
            q.push(i) ;
        }
        q.push(NULL) ;
        q.pop() ;
    }

}

int main() {

    Treenode<int>* root = input_level_order() ;
    level_order_traversal(root) ;
    cout<<count_nodes(root)<<endl ;
    cout<<height(root)<<endl ;
    cout<<count_leaf_nodes(root)<<endl ;
    print_at_depth_d(root,2) ;

    // delete_tree(root) ; -> separate function
    // delete root ;  -> overloaded destructor used -> recursion used, as delete keyword calls the destructor of an object. 

    return 0;
}

