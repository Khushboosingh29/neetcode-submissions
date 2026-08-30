#include <string>
#include <vector>

using namespace std;

class Node {
    Node* link[26] = {nullptr};
    bool flag = false;

public:
    bool containsKey(char ch) {
        return link[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* n) {
        link[ch - 'a'] = n;
    }

    Node* get(char ch) {
        return link[ch - 'a'];
    }

    Node* getByIndex(int idx) {
        return link[idx];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
    Node* root;

    bool searchUtil(Node* curr, const string& word, int idx) {
        if (curr == nullptr) return false;
        
        // Base case: reached the end of the word
        if (idx == word.size()) {
            return curr->isEnd();
        }

        char ch = word[idx];

        // Handle wildcard '.'
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                Node* nextNode = curr->getByIndex(i);
                if (nextNode != nullptr) {
                    if (searchUtil(nextNode, word, idx + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }

        // Handle regular character
        if (!curr->containsKey(ch)) {
            return false;
        }

        return searchUtil(curr->get(ch), word, idx + 1);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* n = root;
        for (char ch : word) {
            if (!n->containsKey(ch)) {
                n->put(ch, new Node());
            }
            n = n->get(ch);
        }
        n->setEnd();
    }

    bool search(string word) {
        return searchUtil(root, word, 0);
    }
};