/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* nodoAnterior = nullptr;
        ListNode* nodoActual = head;

        while (nodoActual != nullptr) {

            // Guardamos por dónde continuar.
            ListNode* nodoSiguiente = nodoActual->next;

            // El nodo actual pasa a apuntar al anterior.
            nodoActual->next = nodoAnterior;

            // Avanzamos los punteros para la próxima vuelta.
            nodoAnterior = nodoActual;
            nodoActual = nodoSiguiente;
        }

        // El último nodo procesado es el nuevo inicio.
        return nodoAnterior;
    }
};
