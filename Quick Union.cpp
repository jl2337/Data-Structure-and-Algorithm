//
//  main.cpp
//  Quick Union
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
};

quick_union::quick_union(unsigned int n){
    for(int i=0;i<n;i++){
        my_id.push_back(i); // initialize roots
    }
}

int quick_union::find_root(int a){
    while(a!=my_id[a]){
        a = my_id[a];   // using recursion to fins root, point to father node every time
    }
    return a;
}

void quick_union::my_union(int a, int b){
    int a_root = find_root(a), b_root = find_root(b);
    if(a_root != b_root){
        my_id[a_root] = b_root; // b_root is now a_root's father node
        cout << a << " and " << b << " are now connected\n";
    }
}

bool quick_union::if_connected(int a, int b){
    return find_root(a) == find_root(b);    // find whether connected
}

int main(int argc, const char * argv[]) {
    time_t start,end;
    fstream infile;
    start = clock();
    quick_union my_obj(8192);   // object has a size of 8192
    infile.open("8192pair.txt");   // open file
    if(!infile){
        cout << "File failed to open\n\n";  // if failed to open, exit program
        return 0;
    }
       
    else
        cout << "File succeed to open\n\n";
    while(infile.get()!=EOF){
        int a,b;
        infile >> a >> b;   // read data from existing file
        my_obj.my_union(a, b);
    }
    end = clock();  // // clock the time
    cout << "\nRunning time is: " << static_cast<double>(end - start)*1000/CLOCKS_PER_SEC << "ms\n\n";  // Running time
    
    return 0;
}
