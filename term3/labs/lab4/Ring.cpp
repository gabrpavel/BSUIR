#include "Ring.h"

template <class T>
Ring<T>::Ring() {

    Head = nullptr;
    Current = nullptr;
    length = 0;
}

template <class T>
Ring<T>::Ring(T element) {

    Head = nullptr;
    Current = nullptr;
    length = 0;
    push(element);                  // ��������� � ������ ������� � �������, ����������� � ����������� 
}

template <class T>
Ring<T>::Ring(const Ring<T>& other)          // ���������� ������������ �����������	
{
    this->Head = nullptr;
    this->Current = nullptr;
    this->length = 0;

    Element<T>* temp = other.Head;	             // ��������� ��������� �� ������� ������� ������ 
    for (int i = 0; i < other.length; i++)       // ���� �� ���������� ��������� 
    {
        push(temp->data);                        // ��������� � ������ ������� �������
        temp = temp->next;                       // ��������� � ���������� �������� ������
    }
}

template <class T>
Ring<T>::~Ring() {
    clear();                                // �������� ������
}

template <class T>
void Ring<T>::init() {
    Current = Head;                         // ������������� ������� ������� �� ������
}

template <class T> void Ring<T>::next()     // ���������� �������� � ���������� ��������
{
    if (!isEmpty())                        // ���� ������ �� ����
        Current = Current->next;            // ���������� ������� ������� �� ���������
}

template <class T> void Ring<T>::prev()     // ���������� �������� � ����������� ��������
{
    if (!isEmpty())                       // ���� ������ �� ����
        Current = Current->prev;            // ���������� ������� ������� �� ����������
}

template <class T> int Ring<T>::isEmpty() // ���������� �������� ������ �� ������� ���������
{
    if (Current == nullptr) return 1;          // ���� ������� ������� ����� ������� ��������           
    else return 0;
}

template <class T> void Ring<T>::push(T data)	// ���������� ���������� ��������
{
    Element<T>* inserted;                       // ������� ����� ��������� �� �������
    inserted = new Element<T>;	                // �������� ������ ��� �������
    inserted->data = data;                      // ���������� ������� �������� � ���� ������ ��������
    if (isEmpty()) {

        Head = inserted;
        Current = inserted;
        Current->next = inserted;
        Current->prev = inserted;
    }
    else {

        inserted->next = Current->next;
        inserted->next->prev = inserted;
        Current->next = inserted;
        inserted->prev = Current;
    }
    length++;                               // ����������� ���������� ��������� � ������
    Current = inserted;                     // ������������� ������� ��������� �� ����������� �������
}

template <class T>
T Ring<T>::pop() {

    if (isEmpty()) {

        std::cerr << "Error: Cannot pop from an empty ring.\n";
        return T(); // ���������� �������� �� ��������� ��� ���� T
    }

    Element<T>* temp = Current;
    T tag = temp->data;

    if (length == 1) {
        Head = nullptr;
        Current = nullptr;
    }
    else {
        Current->next->prev = Current->prev;
        Current->prev->next = Current->next;
        Current = Current->next;
    }

    if (temp == Head)
        Head = Head->next;

    length--;
    delete temp;

    return tag;
}

template <class T> void Ring<T>::print()    // ���������� ������ ���� ���������
{
    if (!isEmpty()) {

        Element<T>* tempCurr = Head;
        for (int i = 0; i < length; i++) {
            std::cout << tempCurr->data << "\n";   // ������� ������ �������� ��������
            tempCurr = tempCurr->next;                              // ��������� � ���������� ��������
        }
        std::cout << "\n";
    }
    else // ���� ������ ����
        std::cout << "Ring is empty\n";          // ������� �������������� 
}

template <class T>
void Ring<T>::clear() {
    while (!isEmpty()) {
        pop();                  // ��������� ������� �������, ���� ������ �� ������ ������
    }
}

template <class T>
bool Ring<T>::contains(T dataToFind) {

    if (!isEmpty()) {
        Element<T>* tempCurr = Head;
        for (int i = 0; i < length; i++) {
            if (tempCurr->data == dataToFind) {
                return true; // ������� �������� � ������
            }
            tempCurr = tempCurr->next;
        }
    }
    return false; // �������� �� ������� ��� ������ ������
}


template <class T>
void Ring<T>::deleteElement(T dataToDelete) {

    if (!isEmpty()) {
        if (contains(dataToDelete)) { // ���������, ���������� �� �������� � ������
            Element<T>* tempCurr = Head;
            Element<T>* toDelete = nullptr;
            for (int i = 0; i < length; i++) {
                if (tempCurr->data == dataToDelete) { // ������ ������� ��� ��������
                    toDelete = tempCurr;
                    break;
                }
                tempCurr = tempCurr->next;
            }

            if (toDelete != nullptr) {
                if (toDelete == Head) { // ���� ������� ��� �������� �������� �������
                    if (length == 1) {
                        Head = nullptr;
                        Current = nullptr;
                    }
                    else {
                        Head = Head->next;
                        Current = Head;
                    }
                }

                toDelete->prev->next = toDelete->next;
                toDelete->next->prev = toDelete->prev;

                delete toDelete;
                length--;
            }
        }
        else {
            std::cout << "Element with data " << dataToDelete << " not found in the ring." << std::endl;
        }
    }
    else {
        std::cout << "Ring is empty." << std::endl;
    }
}
