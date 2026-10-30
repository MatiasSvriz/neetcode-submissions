
class PrefixTree {

private:

    struct Node {

        unordered_map<char, Node*> children;

        bool isEndOfWord = false;

    };

    Node* root;

public:

    PrefixTree() {

        root = new Node();
        
    }

    void insert(string word) {

        Node* actual = root;

        for(char c : word) {

            if(actual->children.count(c) == 0) {
                actual->children[c] = new Node();
            }

            actual = actual->children[c];
        }

        actual->isEndOfWord = true;
    }

    bool search(string word) {

        Node* actual = root;

        for(char c : word) {

            if(actual->children.count(c) == 0) {
                return false;
            }

            actual = actual->children[c];
        }

        return actual->isEndOfWord;
    }

    bool startsWith(string prefix) {

        Node* actual = root;

        for(char c : prefix) {

            if(actual->children.count(c) == 0) {
                return false;
            }

            actual = actual->children[c];
        }

        return true;
    }
};
