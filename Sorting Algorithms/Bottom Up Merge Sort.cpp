//
//  main.cpp
//  Bottom Up Merge Sort
//
//  Created by 刘佳杰 on 2/26/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
// Bottom Up Merge Sort has no Recursion. Time Complexity is also O(NlogN), and Memory Complexity is O(N)
// Logarithmic passes (over the input array) bottom-up mergesort makes in the worst case.
template <class T>
bool IsSorted(vector<T> vec,int low,int high){
    bool flag = true;
    for(int i=low;i<high;i++){
        if(vec[i]>vec[i+1]){
            flag = false; break;
        }
    }
    return flag;
}

template <class T>
T my_min(const T &a,const T &b){
    return a<b?a:b;
}

template <class T>
void my_merge(vector<T> &vec,vector<T> &aux,int low,int mid,int high){
    assert(IsSorted(vec,low,mid));  // pre-condition: vec[low...mid] is already sorted
    assert(IsSorted(vec,mid+1,high)); // pre-condition: vec[mid+1...high] is already sorted
    for(int i=low;i<=high;i++){
        aux[i] = vec[i];    // Copy
    }
    int i = low, j = mid+1;
    for(int k=low;k<=high;k++){ // merge
        if(i>mid)   vec[k] = aux[j++];
        else if(j>high) vec[k] = aux[i++];
        else if(aux[j]<aux[i]) vec[k] = aux[j++];
        else vec[k] = aux[i++];
    }
    assert(IsSorted(vec,low,high)); // post-condition: vec[low...high] is sorted
}

template <class T>
void my_sort(vector<T> &vec){
    int N = static_cast<int>(vec.size());
    vector<T> aux;
    for(int i=0;i<vec.size();i++){
        aux.push_back(vec[i]);
    }
    for(int sz=1;sz<N;sz*=2){
        for(int low=0;low<N-sz;low+=sz+sz){
            my_merge(vec, aux, low, low+sz-1, my_min(low+2*sz-1,N-1));
        }
    }
}

template <class T>
void print(vector<T> vec){
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << '\t';
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    fstream file;
    file.open("data1_8192.txt");
    assert(file);   // Assert file is opened successfully
    vector<int> my_vec;
    while(file.get()!=EOF){
        int temp;
        file >> temp;
        my_vec.push_back(temp);
    }
    time_t start,end;
    start = clock();
    my_sort(my_vec);
    end = clock();
    print(my_vec);
    cout << "Running time is: " << static_cast<double>(end-start)*1000/CLOCKS_PER_SEC << "ms\n";
    return 0;
}
