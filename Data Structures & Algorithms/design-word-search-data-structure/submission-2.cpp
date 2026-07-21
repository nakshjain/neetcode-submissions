class WordDictionary {
private:
    class TrieNode {
    public:
        vector<TrieNode*> children;
        bool isEnd;

        TrieNode(){
            children = vector<TrieNode*>(26, nullptr);
            isEnd = false;
        }

        ~TrieNode(){
            for(auto child : children){
                if(child) delete child;
            }
        }
    };

    TrieNode* node;
public:
    WordDictionary() {
        node = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* tmp = node;
        for(char c: word){
            if(!tmp->children[c-'a']) tmp->children[c-'a'] = new TrieNode();
            tmp= tmp->children[c-'a'];
        }
        tmp->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* tmp = node;
        return searchHelper(word, 0, tmp);
    }

    bool searchHelper(const string& word, int index, TrieNode* currNode){
        if(index==word.size()) return currNode->isEnd;
        char c = word[index];
        if(c=='.'){
            bool found=false;
            for(auto child: currNode->children){
                if(child){
                    found=found || searchHelper(word, index+1, child);
                }
                if(found) return found;
            }
            return found;
        } else {
            if(!currNode->children[c-'a']) return false;
            return searchHelper(word, index+1, currNode->children[c-'a']);
        }
    }
};
