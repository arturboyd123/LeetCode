//
//  main.cpp
//  c++
//
//  Created by artur boyd on 14/09/2022.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
//sadsadasd
class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        float median;
        int length=nums1.size()+nums2.size();//for the main for loop
        /* Below Part is for case of empty vector.
         */
        if(nums1.size()==0){
            median=fill_remaining(num,nums2,length);
            return median;
        }
        else if(nums2.size()==0){
            median=fill_remaining(num,nums1,length);
            return median;
        }
        /*
         The Part below is for the case that each of the vectors has at least one element.
         */
         
        median=push_in_order(nums1, num, nums2, length);
        return median;
    }
    
    float push_in_order(vector<int>& nums1,vector<int>& num,vector<int>& nums2, int length){
        float median;
        int counter1=0,counter2=0;//Used to keep track of the number of elements that already inserted to num from nums1 and nums2
        for(int i=0;i<length;i++){
            if(nums1[counter1]<nums2[counter2]){
                    num.push_back(nums1[counter1]);
                    counter1++;
                
            }
            else{
                    num.push_back(nums2[counter2]);
                    counter2++;
            }
            if(counter1==nums1.size()){//Pushed all the elements of nums1, lets push the elements that remain in nums2
                median=fill_vector(num,nums2,counter2,length);
                return median;
                
            }
            else if(counter2==nums2.size()){//Pushed all the elements of nums2, lets push the elements that remain in nums1
                median=fill_vector(num,nums1,counter1,length);
                return median;
            }
        }
        return median;
    }
    
    float fill_remaining(vector<int>& num,vector<int>& nums,int length){//Fills the num vector with the second vector that is not empty.
        for(int i=0;i<nums.size();i++){
            num.push_back(nums[i]);
        }
        if(num.size()%2!=0){
            int n=(length+1)/2;
            return num[n-1];
        }
        else{
            int n=(length)/2;
            float median=(float(num[n-1])+num[n])/2;
            return median;
        }
    }
    
    float fill_vector(vector<int>& num, vector<int>& nums, int counter, int length){//Fills the vector num with the elements of second vector that his elements we didnt push yet and returns the median value of num.
            for(int i=0;i<nums.size()-counter;i++){
                num.push_back(nums[counter+i]);
            }
            if(length%2!=0){
                int n=(length+1)/2;
                return num[n-1];
            }
            else{
                int n=(length)/2;
                float median;
                median=(float(num[n-1])+num[n])/2;
                return median;
            }
            
        }
    
    
};
/*
int main(){
    vector<int> nums1={1,2},nums2={3,4};
    Solution s;
    cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;
    
}
*/
