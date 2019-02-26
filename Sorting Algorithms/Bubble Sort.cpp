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
// Time complexity is O(N^2). Algorithm is stable.
vector<int>& bubble_sort(vector<int> &vec){
    int size = static_cast<int>(vec.size());
    for(int i=size-1;i>0;i--){
        bool flag = false;  // Flag variable to check whether is already sorted
        for(int j=0;j<i;j++){   // Using double for loops, O(N^2)
            if(vec[j]>vec[j+1]){
                swap(vec[j], vec[j+1]);
                flag = true;
            }
        }
        if(!flag)   break;  // If is already sorted, break the Loop
    }
    return vec;
}

int main(int argc, const char * argv[]) {
    vector<int> vec = {-5,3,4,0,6,9,-2};
    vec = bubble_sort(vec);
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << '\t';
    }
    cout << endl;
    return 0;
}
