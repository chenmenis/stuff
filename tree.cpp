#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

#include <iostream>
#include <algorithm>
using namespace std;

class binaryTree;

class binaryTree{
  public:
  int x;
  binaryTree *left;
  binaryTree *right;

  binaryTree(int X) { x = X; left = NULL; right = NULL;}
  void addLeft(binaryTree *Left){ left= Left; }
  void addRight(binaryTree *Right){ right= Right; }

};


class breadthFirstInverseIterator{
public:
    breadthFirstInverseIterator(binaryTree *t){
        a_queue.push(t);
        while(hasNextinorder()){
            next_inorder();
        }

    }
    int next(){
        if(hasNext()){
           binaryTree *t = a_stack.top();
           a_stack.pop();
           return t->x;
        }
    }
    int next_inorder(){
        if(!hasNextinorder()){
            cout << " Error " << endl;
            return -1;

        }
        binaryTree *t = a_queue.front();
        a_queue.pop();
        a_stack.push(t);
        if(t->left) a_queue.push(t->left);
        if(t->right) a_queue.push(t->right);
        return t->x;
    }
    bool hasNextinorder(){
        return !a_queue.empty();
    }

    bool hasNext(){
        return !a_stack.empty();
    }
    queue<binaryTree *> a_queue;
    stack<binaryTree *> a_stack;


};


class breadthFirstVerticalIterator{
public:
    breadthFirstVerticalIterator(binaryTree *t){
        a_queue.push(t);

    }
    int next(){
        if(!hasNext()){
            cout << " Error " << endl;
            return -1;

        }
        binaryTree *t = a_queue.front();
        a_queue.pop();
        if(t->left) a_queue.push(t->left);
        if(t->right) a_queue.push(t->right);
        return t->x;
    }
    bool hasNext(){
        return !a_queue.empty();
    }
    queue<binaryTree *> a_queue;
    unordered_map< int,vector<binaryTree> > level_node;
};



class breadthVerticalIterator{
public:
    breadthVerticalIterator(binaryTree *t){
        minLevel=0;
        maxLevel=0;
        a_queue.push(t);
        a_level.push(0);

        construct();
    }
    int construct(){
        while(hasNext()){
            binaryTree *t = a_queue.front();
            int curLevel = a_level.front();
            cout << " t-> x" << t->x << endl;
            if(curLevel > maxLevel){
                cout << " pushing higher " << t->x << " level " << curLevel << endl;

                vector<int> newlevel(1,t->x);
                result.push_back(newlevel);
                maxLevel = curLevel;
            } else if(curLevel < minLevel){
                            cout << " pushing lower " << t->x << " level " << curLevel << endl;

                vector<int> newlevel(1,t->x);
                result.push_front(newlevel);
                minLevel = curLevel;
            } else {
                cout << " else " << t->x << " level " << curLevel << endl;
                if(!result.size()) {
                    vector<int> newlevel(1,t->x);
                    result.push_back(newlevel);
                } else {
                    result[curLevel-minLevel].push_back(t->x);
                }
            }


            a_queue.pop();
            a_level.pop();
            if(t->left) {
                a_queue.push(t->left);
                a_level.push(curLevel-1);
            }
            if(t->right){
                a_queue.push(t->right);
                a_level.push(curLevel+1);
            }
        }
    }
    void print(){
        for(auto x:result) {
            cout << "["  ;
            for(auto k:x){
                cout << k << ",";
            }
            cout << "]";
            cout << endl;
        }
    }
    bool hasNext(){
        return !a_queue.empty() && !a_level.empty() ;
    }
    int minLevel;
    int maxLevel;
    deque< vector<int> >result;
    queue<binaryTree *> a_queue;
    queue<int> a_level;

};


class breadthFirstZitZagIterator{
public:
    breadthFirstZitZagIterator(binaryTree *t){

        a_queue.push(t);
        construct();
    }
    void construct(){
        int reversed = 0;
        while(!a_queue.empty()){
            int curSize = a_queue.size();
            deque<int> row;//(curSize);
            for(int i = 0 ; i < curSize;i++){

                binaryTree *t = a_queue.front();
                //int index = (reversed)? curSize - i - 1:i;
                //row[index] = t->x;
                reversed ? row.push_back(t->x):row.push_front(t->x);
                a_queue.pop();
                if(t->left) a_queue.push(t->left);
                if(t->right) a_queue.push(t->right);
            }
            reversed^=1;
            result.push_back(row);
        }
        return;
    }
    void print(){
        for(auto row:result) {
            cout << "[";
            for(auto r: row)
                cout << r << ",";
            cout << "]";
        }
    }
            vector< deque<int>> result;

    queue<binaryTree *> a_queue;
};


class breadthFirstIterator{
public:
    breadthFirstIterator(binaryTree *t){
        a_queue.push(t);

    }
    int next(){
        if(!hasNext()){
            cout << " Error " << endl;
            return -1;

        }
        binaryTree *t = a_queue.front();
        a_queue.pop();
        if(t->left) a_queue.push(t->left);
        if(t->right) a_queue.push(t->right);
        return t->x;
    }
    bool hasNext(){
        return !a_queue.empty();
    }
    queue<binaryTree *> a_queue;
};

class preOrderIterator{
    public:
    preOrderIterator(binaryTree *t){
        stak.push(t);
        }

    int next(){
        if(stak.empty()) { cout << " empty stack " << endl; return -1;}
        cout << " stak size () " << stak.size() << endl;
        binaryTree *n = stak.top();
        stak.pop();
        if(n->right) {stak.push(n->right);  cout << " push right " << n->right->x << endl;}
        if(n->left) {stak.push(n->left); cout << " push left " << n->left->x << endl;}
        return n->x;
    }

    bool hasNext(){ return !stak.empty();  }
    stack < binaryTree *> stak;

};

class inOrderIterator{
    public:
    inOrderIterator(binaryTree *t){
        //stak.push(t);
        curr = t;
    }

    int next(){
        while(curr){
            stak.push(curr);
            curr = curr->left;
        }
        binaryTree *n = stak.top();
        stak.pop();
        curr = n;
        curr = curr->right;
        return n->x;
    }
    bool hasNext(){ return !stak.empty() || curr != NULL; }
    stack < binaryTree *> stak;
    binaryTree *curr;


};

class postOrderIterator{
    public:
    postOrderIterator(binaryTree *t){
       stak.push(t);
        curr = NULL;
        prev = NULL;
    }

    int  next(){
        binaryTree *ret = NULL;
        while( hasNext()){
            curr = stak.top();


            /*

                         prev
                (left)  /    \ (right)
                    current_ptr
                      /    \
                    (right) (left)

            */
            if(!prev||curr == prev->left ||curr == prev->right){
                if(curr->left) { stak.push(curr->left); }
                else if(curr->right) { stak.push(curr->right); }
                else if(!curr->right && !curr->left) {
                   ret = curr;
                   curr = stak.top();
                   prev = curr;
                   stak.pop();
            //       cout << " stack size " << stak.size() << endl;
                   return ret->x;
                }
            }

            /*

                         current_ptr (we have seen left substree, push _right if it exists else do current itself  )
                (left)  /    \ (right)  (we have seen right substree,  do current itself now that everyone has gone through it  )
                       prev
                      /    \
                    (right) (left)

            */


            else if(prev == curr->left){
                if(curr->right) {
                    stak.push(curr->right);
                } else {
                    ret = curr;
                    curr = stak.top();
                    prev = curr;
                    stak.pop();

                   //cout << " stack size " << stak.size() <<   " return " << ret-> x  <<endl;
                    return ret->x;
                }
            }

            else if(prev == curr->right){
                  ret = curr;
                    curr = stak.top();
                    stak.pop();

                    //cout << " stack size " << stak.size() << " return " << ret-> x << endl;
                    prev = curr;
                    return ret->x;

            }

            prev = curr;
         }
    }
    bool hasNext(){ return !stak.empty(); }
    stack < binaryTree *> stak;
    binaryTree *curr;
    binaryTree *prev;

};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    binaryTree one(1);
    binaryTree two(2);
    binaryTree three(3);
    binaryTree four(4);
    binaryTree five(5);
    one.left   = &two;
    one.right  = &three;
    one.left->left= &four;
    one.left->right= &five;
    /*
                     1
                    / \
                   2   3
                  / \
                 4   5
    */

    preOrderIterator  pre(&one);
/*
    while(pre.hasNext()){
        cout << " pre order " << pre.next() << endl;
    }
*/
    inOrderIterator in(&one);
/*
    while(in.hasNext()){
        cout << " in order " << in.next() << endl;
    }
*/
    postOrderIterator post(&one);
/*
    while(post.hasNext()){
        cout << " post order " << post.next() << endl;
    }
*/
    breadthFirstIterator  breadthFirstIt(&one);

   /* while(breadthFirstIt.hasNext()){
        cout << " breadth order " << breadthFirstIt.next() << endl;
    }*/
    breadthFirstInverseIterator  breathInvIt(&one);

    /*while(breathInvIt.hasNext()){
        cout << " breadth order " << breathInvIt.next() << endl;
    }*/

    breadthVerticalIterator vert(&one);
    //vert.print();

    breadthFirstZitZagIterator zigzag(&one);
    zigzag.print();
    return 0;
}

