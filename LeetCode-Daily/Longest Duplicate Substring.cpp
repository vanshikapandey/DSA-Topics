//Problem Link:https://leetcode.com/problems/longest-duplicate-substring/
//QUES
/*Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
*/


 


/******************************CODE**********************/

class Solution {
public:
    
    int mod = 10000000+7;
    bool match(string s , int len, int curr_len,string &ans,vector<int> hash){
        
        map<int,vector<int>> mp;
        int val = 0;
        for(int i=0;i<curr_len;i++){
             val= ((val*26) + (s[i]-'a'))%mod;
        }
        
        mp[val].push_back(0);
        
        for(int j=curr_len;j<len;j++){
            val = ((val-hash[curr_len-1]*(s[j-curr_len]-'a'))%mod +mod)%mod;
            val= ((val*26) + (s[j]-'a'))%mod;
            
            if(mp.find(val)!=mp.end()){
                for(auto start:mp[val]){
                    string str = s.substr(start,curr_len);
                    string curr = s.substr(j-curr_len+1,curr_len);
                    
                    if(str.compare(curr)==0){
                        ans = curr;
                        return true;
                    }
                }
            }
            else{
                mp[val].push_back(j-curr_len+1);
            }
        }
        
        return false;
    }
    string longestDupSubstring(string s) {
        
        int n = s.length();
        // hash.resize(n);
        
        vector<int> hash(n);
        hash[0]=1;
        for(int i=1;i<n;i++){
            hash[i] = (26*hash[i-1])%mod;
        }
    
        int low = 1 , high = n;
        string ans="",temp;
        
        while(low<=high){
            
            int mid =  low + (high-low)/2;
            temp="";
           
            bool present = match(s,n,mid,temp,hash);
            // cout<<present<<endl;
            if(present){
                  if(temp.length()>ans.length()){
                      ans = temp;
                  }
                 low = mid + 1;  
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};