//
//  main.cpp
//  Quick Find
//
//  Created by 刘佳杰 on 2/18/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

class quick_find{
public:
    quick_find(unsigned int n);
    void my_union(int,int);
    bool connected(int,int);
private:
    vector<int> my_id;
};

quick_find::quick_find(unsigned int n){
    for(int i=0;i<n;i++){
        my_id.push_back(i); // The tree is Flat, initialize roots
    }
}

void quick_find::my_union(int a, int b){
    if(my_id[a] != my_id[b]){   // determine whether have same root
        int temp = my_id[a];
        for(int i=0;i<my_id.size();i++){    // go through whole vector, Time complexity is O(N)
            if(my_id[i] == temp)
                my_id[i] = my_id[b];    // change root
        }
    }
}

bool quick_find::connected(int a, int b){   // implement the function
    return my_id[a] == my_id[b];    // Time complexity is O(1)
}

int main(int argc, const char * argv[]) {
    time_t start,end;
    start = clock();
    quick_find my_obj(8192);  // Initialize vector size of 8192
    fstream infile;
    infile.open("8192pair.txt"); // Open file
    if(!infile){
        cout << "File failed to open\n\n";  // check whether the file is openned successfully
        return 0;   // if not, exit program
    }
        
    else
        cout << "Succeed to open\n\n";
    while(infile.get()!=EOF){
        int a,b;
        infile >> a >> b;   // From file to input data
        if(!my_obj.connected(a, b)){
            my_obj.my_union(a, b);
            cout << a << " and " << b << " are now connected\n";
        }
        else{
            cout << a << " and " << b << " were already connected\n";
        }
    }
    end = clock();
    cout << "\nRunning time is: " << static_cast<double>(end - start)*1000/CLOCKS_PER_SEC << "ms\n\n";  // Running Time
    return 0;
}
