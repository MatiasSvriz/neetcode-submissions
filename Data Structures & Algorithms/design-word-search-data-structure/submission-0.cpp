
class WordDictionary {

private:

    struct Node {

        unordered_map<char, Node*> children;

        bool isEndOfWord = false;

    };

    Node* root;

    // Buscamos recursivamente desde el nodo actual.
    bool dfs(string& word, int posicion, Node* actual) {

        // Hemos recorrido toda la palabra.
        if(posicion == word.size()) {
            return actual->isEndOfWord;
        }

        char c = word[posicion];

        // Es una letra normal.
        if(c != '.') {

            // Si no existe el hijo, devolvemos false.
            if(actual->children.count(c) == 0) {
                return false;
            }

            // Avanzamos al siguiente nodo.
            return dfs(word, posicion + 1, actual->children[c]);
        }

        // Es un punto, entonces probamos todos los hijos posibles.
        for(auto& [letra, hijo] : actual->children) {

            if(dfs(word, posicion + 1, hijo)) {
                return true;
            }
        }

        // Ninguna rama ha encontrado la palabra.
        return false;
    }

public:

    WordDictionary() {
        root = new Node();
    }

    // Añadimos una palabra al Trie.
    void addWord(string word) {

        Node* actual = root;

        for(char c : word) {

            if(actual->children.count(c) == 0) {
                actual->children[c] = new Node();
            }

            actual = actual->children[c];
        }

        actual->isEndOfWord = true;
    }

    // Iniciamos la búsqueda desde root.
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
