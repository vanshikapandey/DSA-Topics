//Problem Link: https://leetcode.com/problems/multiply-strings/

//QUES

/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.*/

/***************CODE***************/

class Solution {
public:
    string multiply(string num1, string num2) {
        
        vector<int> ans(num1.length()+num2.length(),0);
        if(num1=="0" || num2=="0"){
            return "0";
        }
        
        int n=num1.length()-1;
        int m=num2.length()-1;
        
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                ans[i+j+1]+= (num1[i]-'0')*(num2[j]-'0');
                ans[i+j]+= ans[i+j+1]/10;
                ans[i+j+1] = ans[i+j+1]%10;
            }
        }
        
        int i=0;
        
        while(i<ans.size() && ans[i]==0){
            i++;
        }
        
        string res="";
        while(i<ans.size()){
            res.push_back(ans[i]+'0');
            i++;
        }
        
        return res;
               
        
    }
};