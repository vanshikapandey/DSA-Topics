//Problem Link:https://leetcode.com/problems/stream-of-characters/

//QUES

/*************CODE************/
class Trie{
    
    Trie *children[26];
    bool flag;
    
    public:
        Trie(){
            flag = false;
            
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
        }
    void insert(string s){
        
        Trie *t = this;
        for(auto alpha:s){
            if(t->children[alpha-'a']==NULL){
                t->children[alpha-'a'] = new Trie;
            }
                t = t->children[alpha-'a'];
        }
         t->flag =  true;
    }
    
    bool search(deque<char>& stream){
        
        Trie *t = this;
        
        for(auto c:stream){
            if(t->children[c-'a']==NULL){
                return false;
            }
            t=t->children[c-'a'];
            
            if(t->flag){
                return true;
            }
        }
        
        return false;
        
    }
};

class StreamChecker {
    Trie t;
    deque<char> stream;
public:
    StreamChecker(vector<string>& words) {
        
        for(auto word:words){
            reverse(word.begin(),word.end());
            t.insert(word);
        }
    }
    
    bool query(char letter) {
        
        stream.push_front(letter);
        return t.search(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */