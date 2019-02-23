//
//  main.cpp
//  Weighted Quick Union with Path Compression
//
//  Created by 刘佳杰 on 2/18/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

class quick_union{
public:
    quick_union(unsigned int);
    int find_root(int);
    void my_union(int,int);
    bool if_connected(int,int);
    
private:
    vector<int> my_id;
    vector<int> my_size;    // record size of all trees
};

quick_union::quick_union(unsigned int n){
    for(int i=0;i<n;i++){
        my_id.push_back(i); // initialize roots
        my_size.push_back(1);   // initialize size
    }
}

int quick_union::find_root(int a){
    while(a!=my_id[a]){
        a = my_id[my_id[a]];    // Improvement 2: path compression, direct every node to its grandfather node, it halved time cost
    }
    return a;
}

void quick_union::my_union(int a, int b){
    int a_root = find_root(a), b_root = find_root(b);
    if(a_root != b_root){
        if(my_size[a_root] < my_size[b_root]){      // Improvement 1: weighted quick union
            my_id[a_root] = b_root; // if the size of a_root tree is smaller than b_root tree, b_root will be a_root's father node
            my_size[b_root] += my_size[a_root]; // cobine two trees together, root is b_root
        }
        else{                               // Improvement 1: weighted quick union
            my_id[b_root] = a_root;    // similar
            my_size[a_root] += my_size[b_root];    // similarqw
        }
        cout << a << " and " << b << " are now connected\n";
    }
}

bool quick_union::if_connected(int a, int b){
    return find_root(a) == find_root(b);
}

int main(int argc, const char * argv[]) {
    time_t start,end;
    fstream infile;
    start = clock();    // clock the time
    quick_union my_obj(8192);    // object has a size of 8192
    infile.open("8192pair.txt");   // open file
    if(!infile){
        cout << "File failed to open\n\n";  // if failed to open, exit program
        return 0;
    }
        
    else
        cout << "File succeed to open\n\n";
    while(infile.get()!=EOF){   // read data from existing file
        int a,b;
        infile >> a >> b;
        my_obj.my_union(a, b);
    }
    end = clock();  // // clock the time
    cout << "\nRunning time is: " << static_cast<double>(end - start)*1000/CLOCKS_PER_SEC << "ms\n\n";  // Running time
    
    return 0;
}
