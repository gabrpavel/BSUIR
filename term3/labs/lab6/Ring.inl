template <class T>
Ring<T>::Ring() {

    Head = nullptr;
    length = 0;
}

template <class T>
Ring<T>::Ring(T element) {

    Head = nullptr;
    length = 0;
    push(element);                  // добавляем в кольцо элемент с данными, переданными в конструктор 
}

template <class T>
Ring<T>::Ring(const Ring<T>& other)          // реализация конструктора копирования	
{
    this->Head = nullptr;
    this->length = 0;

    Element<T>* temp = other.Head;	             // сохраняем указатель на текущий элемент кольца 
    for (int i = 0; i < other.length; i++)       // цикл на количество элементов 
    {
        push(temp->data);                        // добавляем в кольцо текущий элемент
        temp = temp->next;                       // переходим к следующему элементу кольца
    }
}

template <class T>
Ring<T>::Ring(Ring<T>&& other) noexcept : Head(other.Head), length(other.length) {
    other.Head = nullptr; 
    other.length = 0;
}

template <class T>
Ring<T>::~Ring() {
    clear();                                // очистить кольцо
}

template <class T>
int Ring<T>::getLength() {
    return this->length;
}

template <class T>
T& Ring<T>::getAt(int index) {
    if (isEmpty() || index < 0 || index >= this->length) {
        throw std::out_of_range("Index out of range");
    }
    Iterator it = begin();
    for (int i = 0; i < index; ++i) {
        it++;
    }

    return *it;
}

template <class T>
bool Ring<T>::isEmpty() {
    return (Head == nullptr); // Возвращаем true, если указатель на головной элемент равен nullptr, иначе false
}

template<class T>
bool Ring<T>::exist(T data) {
    Iterator it = begin();

    // Проходим по всем элементам кольца
    for (int i = 0; i < length; ++i) {
        if (*it == data) { // Если нашли элемент, равный переданному data, возвращаем true
            return true;
        }
        it++;
    }

    return false; // Если элемент не найден, возвращаем false
}

template <class T> void Ring<T>::push(T data)	// реализация добавления элемента
{
    Element<T>* inserted;                       // создать новый указатель на элемент
    inserted = new Element<T>;	                // выделить память под элемент
    inserted->data = data;                      // установить входной параметр в поле данных элемента
    if (isEmpty()) {

        Head = inserted;
        Head->next = inserted;
        Head->prev = inserted;
    } else {
        inserted->next = Head->next;
        inserted->next->prev = inserted;
        Head->next = inserted;
        inserted->prev = Head;
        Head = inserted;
        Head->prev = inserted->prev; // Update Head's prev to the last inserted element
    }
    length++;                     // увеличиваем количество элементов в кольце
}

template <class T>
T Ring<T>::pop() {

    if (isEmpty()) {

        std::cerr << "Error: Cannot pop from an empty ring.\n";
        return T(); // Возвращаем значение по умолчанию для типа T
    }

    Element<T>* temp = Head->next;
    T tag = temp->data;

    if (length == 1) {
        Head = nullptr;
    }
    else {
        temp->next->prev = Head;
        Head->next = temp->next;
    }

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
        Element<T>* temp = Head->next;	// Сохраняем указатель на элемент для удаления
        Head->next = temp->next;	// Перемещаем указатель на следующий элемент
        temp->next->prev = Head;	// Обновляем указатель prev следующего элемента
        delete temp;	// Удаляем текущий элемент
        length--;	// Уменьшаем счетчик количества элементов

        if (length == 0) {
            Head = nullptr;
        }
    }
}
    
template<typename U>
std::ostream& operator<<(std::ostream& os, Ring<U>& ring) {
    if (ring.isEmpty()) {
        os << "Ring is empty" << std::endl;
    }
    else {
        typename Ring<U>::Iterator it = ring.begin();
        do {
            it++;
            os << *it << std::endl; 
        } while (it != ring.begin());
    }
    return os;
}

template<class T>
bool Ring<T>::operator==(const Ring<T>& other) const {
    if (length != other.length) {
        return false; // Если длины списков не равны, списки точно не равны
    }

    if (isEmpty() && const_cast<Ring<T>&>(other).isEmpty()) {
        return true; // Если оба списка пусты, они считаются равными
    }

    Iterator it1 = const_cast<Ring<T>&>(*this).begin();
    Iterator it2 = const_cast<Ring<T>&>(other).begin();

    do {
        if (*it1 != *it2) {
            return false; // Если хотя бы один элемент не равен, списки не равны
        }
        it1++;
        it2++;
    } while (it1 != const_cast<Ring<T>&>(*this).begin() && it2 != const_cast<Ring<T>&>(other).begin());

    return true; // Если все элементы равны, списки равны
}

template<class T>
bool Ring<T>::operator!=(const Ring<T>& other) const {
    return !(*this == other);
}

template <class T> void Ring<T>::deleteElement(T dataToDelete) {

    Iterator found = find(dataToDelete);

    if (*found == dataToDelete) {
        pop(found);
        std::cout << "Element deleted: " << std::endl;
    }
    else {
        std::cout << "Element not found\n";
    }
}

template<class T>
typename Ring<T>::Iterator Ring<T>::find(T data) {

    if (!isEmpty()) {
        Iterator it = begin();

        do {
            if (*it == data) {
                return it;
            }
            it++;
        } while (it != begin());

        return begin();
    }
}

template<class T>
Ring<T>& Ring<T>::operator=(const Ring<T>& other) {
    if (this != &other) { // Проверка на присваивание самому себе
        clear(); // Очищаем текущий список перед копированием другого списка

        Element<T>* temp = other.Head; // Указатель на начало списка other
        for (int i = 0; i < other.length; i++) {
            push(temp->data); // Добавляем элементы из списка other в текущий список
            temp = temp->next; // Переходим к следующему элементу списка other
        }
    }
    return *this;
}
template<class T>
Ring<T>& Ring<T>::operator=(Ring<T>&& other) noexcept {
    if (this != &other) { // Проверка на присваивание самому себе
        clear(); // Очищаем текущий список перед перемещением другого списка

        // Переносим указатель на начало списка и длину из объекта other в текущий объект
        Head = other.Head;
        length = other.length;
        other.Head = nullptr; // Указатель на начало списка в other делаем nullptr
        other.length = 0; // Длина списка в other обнуляется
    }
    return *this;
}