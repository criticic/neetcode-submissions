class PrefixTreeNode {
public:
    unordered_map<char, PrefixTreeNode*> children;
    bool endOfWord = false;
};

class PrefixTree {
    PrefixTreeNode* root;
public:
    PrefixTree() {
        root = new PrefixTreeNode();
    }
    
    void insert(string word) {
        PrefixTreeNode* cur = root;
        for (char c: word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new PrefixTreeNode;
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        PrefixTreeNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        PrefixTreeNode* cur = root;
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};
