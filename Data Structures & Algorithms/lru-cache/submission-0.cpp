class LRUCache {

private:

    struct Nodo{

        int clave;
        int valor;

        Nodo* anterior;
        Nodo* siguiente;

        Nodo(int key, int value){

            clave = key;
            valor = value;

            anterior = nullptr;
            siguiente = nullptr;

        }

    };

    int capacidad;

    unordered_map<int, Nodo*> posiciones;

    Nodo* inicio;
    Nodo* final;

    // Desconectamos el nodo.
    void quitar(Nodo* nodo) {
        Nodo* anterior = nodo->anterior;
        Nodo* posterior = nodo->siguiente;

        anterior->siguiente = posterior;
        posterior->anterior = anterior;
    }

    // Colocamos nodo como mas recientemente utilizado.
    void ponerAlPrincipio(Nodo* nodo){

        Nodo* primerNodoReal = inicio->siguiente;

        nodo->anterior = inicio;
        nodo->siguiente = primerNodoReal;

        inicio->siguiente = nodo;
        primerNodoReal->anterior = nodo;

    }


public:
    LRUCache(int capacity) {

        capacidad = capacity;

        inicio = new Nodo(0,0);
        final = new Nodo(0,0);

        inicio->siguiente = final;
        final->anterior = inicio;

    }
    
    int get(int key) {
        
        if(posiciones.count(key) == 0){
            return -1;
        }

        Nodo* nodo = posiciones[key];

        quitar(nodo);
        ponerAlPrincipio(nodo);

        return nodo->valor;

    }
    
    void put(int key, int value) {

        if(posiciones.count(key) > 0){

            Nodo* nodo = posiciones[key];

            nodo->valor = value;

            quitar(nodo);
            ponerAlPrincipio(nodo);

        }else{

            Nodo* nuevoNodo = new Nodo(key, value);

            if(posiciones.size() + 1 > capacidad){

                Nodo* antiguo = final->anterior;

                quitar(antiguo);
                posiciones.erase(antiguo->clave);

                delete antiguo;

            }

            posiciones[key] = nuevoNodo;
            ponerAlPrincipio(nuevoNodo);

        }
        
    }
};
