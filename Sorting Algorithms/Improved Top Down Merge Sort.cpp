//
//  main.cpp
//  Improved Top Down Merge Sort
//
//  Created by 刘佳杰 on 2/26/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
// Improvement 1: Use insertion sort for small subarrays.
// Merge Sort has too much complicated for tiny subarrays.

// Improvement 2: Stop if already sorted
// Is the biggest item in first half <= the smallest item in second half
// Helps for partially- ordered array.
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

template<class T>
void insert_sort(vector<T> &vec,int low,int high){
    for(int i=low+1;i<=high;i++){
        // vec[low],vec[low+1]...vec[i-1] are already sorted
        // Now we need to insert vec[i] into the sorted array
        if(vec[i]<vec[i-1]){
            // Only when vec[i] is less than vec[i-1], we need to insert
            T temp = vec[i];    // Creat a temporary variable to store vec[i]
            vec[i] = vec[i-1];  // vec[i] store value of vec[i-1]
            int j;
            // Find right place to insert vec[i]
            for(j=i-2;j>=low&&temp<vec[j];j--){
                vec[j+1] = vec[j];  // vec[j+1] store value of vec[j]
            }
            vec[j+1] = temp;    // here is the place to insert temp
        }
    }
}

template <class T>
void my_sort(vector<T> &vec,vector<T> &aux,int low,int high){
    // Improvement 1:
    // When array size is tiny, Use Insertion Sort instead
    if(high<=low+7){
        insert_sort(vec,low,high); return;
    }
    int mid = low+(high-low)/2; // set mid
    my_sort(vec,aux,low,mid);   // sort the first half, recursion
    my_sort(vec,aux,mid+1,high);    // sort the second half, recursion
    // Improvement 2:
    // If the biggest item in first half <= the smallest item in second half, there is no need to merge
    if(vec[mid]<=vec[mid+1])    return;
    my_merge(vec, aux, low, mid, high); // merge these two halves together
}

template <class T>
void my_sort(vector<T> &vec){   // Overloading my_sort
    vector<T> aux;
    for(int i=0;i<vec.size();i++){
        aux.push_back(vec[i]);  // aux is vec's copy
    }
    my_sort(vec,aux,0,static_cast<int>(vec.size()-1));  // Using my_sort recursively
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
