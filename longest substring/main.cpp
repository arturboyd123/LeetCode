//
//  2.cpp
//  LeetCode
//
//  Created by artur boyd on 11/10/2022.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int len = str.length();
        int current_len=0 , max=0;
        vector<char> v1;
        vector<char> :: iterator it,it1;
        for(int i=0; i<len ; i++){
            it = find(v1.begin(),v1.end(),str[i]);
            if(it!=v1.end()){
                int count=1;
                it1=v1.begin();
                while(it1!=it){
                    it1++;
                    count++;
                }
                v1.erase(v1.begin(),++it);
                v1.push_back(str[i]);
                current_len++;
                current_len=current_len-count;
                
            }
            else{
                v1.push_back(str[i]);
                current_len++;
                if(current_len>max){
                    max=current_len;
                }
            }
        }
        return max;
    }
};
/*
int main(){
    Solution s;
    std::cout<<s.lengthOfLongestSubstring("Artur")<<std::endl;
}
*/

