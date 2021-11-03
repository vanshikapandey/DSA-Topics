//Pronlem link:https://leetcode.com/problems/longest-turbulent-subarray/

//QUES:

/*Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.
 */


/*****************************CODE******************************/

class Solution {
public:
    bool isTurbulent(vector<int>& arr,int j){
        
        if((j-1)>=0 && (j+1)<arr.size() && ((arr[j-1]>arr[j] && arr[j+1]>arr[j]) 
        || (arr[j-1]<arr[j] && arr[j+1]<arr[j]))){
            return true;
        }
           
           return false;
    }
    
   
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();
        
        if(n==1){
            return 1;
        }
        
        if(count(arr.begin(),arr.end(),arr[0])==n){
            return 1;
        }
        
        int i,j,maxLen = 1;
        for(i=0,j=i+1;j<n;){
            if(arr[i]==arr[i+1]){
                i++;
                j=i+1;
            }
            
            if(isTurbulent(arr,j)){
                j++;
                maxLen = max(maxLen,j-i+1);
            }
            else{
                i = j;
                j=i+1;
            }
        }
        return maxLen;
    }
};

// max = 2
//      i              
// [37,199,60,296,257,248,115,31,273,176]