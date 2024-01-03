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
    push(element);                  // добавляем в кольцо элемент с данными, переданными в конструктор 
}

template <class T>
Ring<T>::Ring(const Ring<T>& other)          // реализация конструктора копирования	
{
    this->Head = nullptr;
    this->Current = nullptr;
    this->length = 0;

    Element<T>* temp = other.Head;	             // сохраняем указатель на текущий элемент кольца 
    for (int i = 0; i < other.length; i++)       // цикл на количество элементов 
    {
        push(temp->data);                        // добавляем в кольцо текущий элемент
        temp = temp->next;                       // переходим к следующему элементу кольца
    }
}

template <class T>
Ring<T>::~Ring() {
    clear();                                // очистить кольцо
}

template <class T>
void Ring<T>::init() {
    Current = Head;                         // устанавливаем текущий элемент на первый
}

template <class T> void Ring<T>::next()     // реализация перехода к следующему элементу
{
    if (!isEmpty())                        // если список не пуст
        Current = Current->next;            // установить текущую позицию на следующую
}

template <class T> void Ring<T>::prev()     // реализация перехода к предыдущему элементу
{
    if (!isEmpty())                       // если список не пуст
        Current = Current->prev;            // установить текущую позицию на предыдущую
}

template <class T> int Ring<T>::isEmpty() // реализация проверки списка на наличие элементов
{
    if (Current == nullptr) return 1;          // если текущая позиция имеет нулевое значение           
    else return 0;
}

template <class T> void Ring<T>::push(T data)	// реализация добавления элемента
{
    Element<T>* inserted;                       // создать новый указатель на элемент
    inserted = new Element<T>;	                // выделить память под элемент
    inserted->data = data;                      // установить входной параметр в поле данных элемента
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
    length++;                               // увеличиваем количество элементов в кольце
    Current = inserted;                     // устанавливаем текущий указатель на добавленный элемент
}

template <class T>
T Ring<T>::pop() {

    if (isEmpty()) {

        std::cerr << "Error: Cannot pop from an empty ring.\n";
        return T(); // Возвращаем значение по умолчанию для типа T
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

template <class T> void Ring<T>::print()    // реализация вывода всех элементов
{
    if (!isEmpty()) {

        Element<T>* tempCurr = Head;
        for (int i = 0; i < length; i++) {
            std::cout << tempCurr->data << "\n";   // выводим данные текущего элемента
            tempCurr = tempCurr->next;                              // переходим к следующему элементу
        }
        std::cout << "\n";
    }
    else // если список пуст
        std::cout << "Ring is empty\n";          // вывести предупреждение 
}

template <class T>
void Ring<T>::clear() {
    while (!isEmpty()) {
        pop();                  // Извлекаем текущий элемент, пока список не станет пустым
    }
}

template <class T>
bool Ring<T>::contains(T dataToFind) {

    if (!isEmpty()) {
        Element<T>* tempCurr = Head;
        for (int i = 0; i < length; i++) {
            if (tempCurr->data == dataToFind) {
                return true; // Найдено значение в кольце
            }
            tempCurr = tempCurr->next;
        }
    }
    return false; // Значение не найдено или кольцо пустое
}


template <class T>
void Ring<T>::deleteElement(T dataToDelete) {

    if (!isEmpty()) {
        if (contains(dataToDelete)) { // Проверяем, содержится ли значение в кольце
            Element<T>* tempCurr = Head;
            Element<T>* toDelete = nullptr;
            for (int i = 0; i < length; i++) {
                if (tempCurr->data == dataToDelete) { // Найден элемент для удаления
                    toDelete = tempCurr;
                    break;
                }
                tempCurr = tempCurr->next;
            }

            if (toDelete != nullptr) {
                if (toDelete == Head) { // Если элемент для удаления является головой
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
