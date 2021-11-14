//Problem Link:https://leetcode.com/problems/iterator-for-combination/

//QUES

/*
Design the CombinationIterator class:

CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
next() Returns the next combination of length combinationLength in lexicographical order.
hasNext() Returns true if and only if there exists a next combination.

*/

/*******************CODE*************************/

class CombinationIterator {
    
    vector<string> combi;
    int ptr = 0;
    
    void generate(string characters,int pos, int combinationLength, string temp){
        
        if(combinationLength==0){
            combi.push_back(temp);
            return;
        }
        
        if(pos>=characters.length()){
            return ;
        }
        
        temp+=characters[pos];
        generate(characters,pos+1,combinationLength-1,temp);
        temp.pop_back();
        generate(characters,pos+1,combinationLength,temp);
        
    }
    
public:
    CombinationIterator(string characters, int combinationLength) {
        
        generate(characters,0,combinationLength,"");
         ptr = 0;
    }
    
    string next() {
            return combi[ptr++];
    }
    
    bool hasNext() {
        if(ptr<combi.size())
            return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */