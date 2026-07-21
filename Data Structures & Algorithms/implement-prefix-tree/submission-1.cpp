class PrefixTree {
private:
    class TrieNode {
        public:
        vector<TrieNode*> children;
        bool isEnd;
        
        TrieNode(){
            children = vector<TrieNode*>(26, nullptr);
            isEnd=false; 
        }
    };

    TrieNode* node;
public:
    PrefixTree() {
        node = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp = node;
        for(char c: word){
            if(!tmp->children[c-'a']) tmp->children[c-'a']=new TrieNode();
            tmp=tmp->children[c-'a'];
        }
        tmp->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* tmp = node;
        for(char c: word){
            if(!tmp->children[c-'a']) return false;
            tmp=tmp->children[c-'a'];
        }
        return tmp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* tmp = node;
        for(char c: prefix){
            if(!tmp->children[c-'a']) return false;
            tmp=tmp->children[c-'a'];
        }
        return true;
        
    }
};
