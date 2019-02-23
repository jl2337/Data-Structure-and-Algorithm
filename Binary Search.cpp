//
//  main.cpp
//  Binary Search
//
//  Created by 刘佳杰 on 2/22/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int BinarySearch(vector<int>, int);
    // The vector must be sorted
    vector<int> my_vec = {6,13,14,25,33,43,51,53,64,72,84,93,95,96,97};
    cout << BinarySearch(my_vec, 33) << endl;
    return 0;
}

int BinarySearch(vector<int> vec, int key){
    int low = 0, high = static_cast<int>(vec.size() - 1);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(vec[mid] > key){
            high = mid - 1;
        }
        else if(vec[mid] < key){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
