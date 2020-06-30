/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/


class Trie {
public:
    Trie* children[26];
    bool endOfWord;
    
    Trie():endOfWord(false) {
        for (int i=0; i<26; ++i)
            children[i] = nullptr;
    }
    
    ~Trie() {
        for (int i=0; i<26; ++i) delete children[i];
    }
    
    void insert(string s) {
        Trie* curr = this;
        for (char ch : s) {
            if (! curr->children[ch-'a']) curr->children[ch-'a'] = new Trie();
            curr = curr->children[ch-'a'];
        }
        curr->endOfWord = true;
    }
};

class Solution {
private:
    void dfs(vector<vector<char>>& b, int i, int j, Trie* trie, unordered_set<string>& res, string str) {
        char ch = b[i][j];
        if (ch == '$') return;
        b[i][j] = '$';
        Trie* t = trie->children[ch-'a'];
        if (t) {
            string ss = str + ch;
            if (t->endOfWord) res.insert(ss);
            if (i > 0) dfs(b, i-1, j, t, res, ss);
            if (j > 0) dfs(b, i, j-1, t, res, ss);
            if (i < b.size()-1) dfs(b, i+1, j, t, res, ss);
            if (j < b[0].size()-1) dfs(b, i, j+1, t, res, ss);
        }
        b[i][j] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (!words.size()) return {};
        Trie trie;
        for (string word : words) 
            trie.insert(word);
        unordered_set<string> res_set;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j)
                dfs(board, i, j, &trie, res_set, "");
        }
        vector<string> res(res_set.begin(), res_set.end());
        return res;
    }
};