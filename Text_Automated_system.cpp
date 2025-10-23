#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


class TrieNode {
public:
    bool isEnd;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEnd = false;
    }
};


class Trie {
private:
    TrieNode* root;

    
    void dfs(TrieNode* node, string prefix, vector<string>& results) {
        if (node->isEnd)
            results.push_back(prefix);

        for (auto& child : node->children) {
            dfs(child.second, prefix + child.first, results);
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c])
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }

    vector<string> getSuggestions(string prefix) {
        TrieNode* curr = root;
        vector<string> results;

       
        for (char c : prefix) {
            if (!curr->children[c])
                return {}; 
            curr = curr->children[c];
        }

       
        dfs(curr, prefix, results);
        return results;
    }
};


int main() {
    Trie trie;

    
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("apply");
    trie.insert("banana");
    trie.insert("band");
    trie.insert("bat");
    trie.insert("battle");
    trie.insert("javascript");
    trie.insert("json");
    trie.insert("java");
    trie.insert("jquery");
    trie.insert("python");
    trie.insert("pytorch");
    trie.insert("pune");
    trie.insert("poco");
    string prefix;
    cout << "Enter a prefix to get suggestions: ";
    cin >> prefix;

    vector<string> suggestions = trie.getSuggestions(prefix);

    if (suggestions.empty())
        cout << "No suggestions found for prefix '" << prefix << "'." << endl;
    else {
        cout << "Suggestions for '" << prefix << "':\n";
        for (string word : suggestions)
            cout << " - " << word << endl;
    }

    return 0;
}
