//
//  main.cpp
//  Bubble Sort
//
//  Created by 刘佳杰 on 2/25/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
// Time complexity is O(N^2)
vector<int>& bubble_sort(vector<int> &vec){
    int size = static_cast<int>(vec.size());
    for(int i=size-1;i>=0;i--){
        for(int j=0;j<i;j++){   // Using double for loops
            if(vec[j]>vec[j+1]) swap(vec[j], vec[j+1]);
        }
    }
    return vec;
}

int main(int argc, const char * argv[]) {
    vector<int> vec = {-5,3,4,0,6,9,-2};
    vec = bubble_sort(vec);
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << endl;
    }
    return 0;
}
