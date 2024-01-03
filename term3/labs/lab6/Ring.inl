template <class T>
Ring<T>::Ring() {

    Head = nullptr;
    length = 0;
}

template <class T>
Ring<T>::Ring(T element) {

    Head = nullptr;
    length = 0;
    push(element);                  // ��������� � ������ ������� � �������, ����������� � ����������� 
}

template <class T>
Ring<T>::Ring(const Ring<T>& other)          // ���������� ������������ �����������	
{
    this->Head = nullptr;
    this->length = 0;

    Element<T>* temp = other.Head;	             // ��������� ��������� �� ������� ������� ������ 
    for (int i = 0; i < other.length; i++)       // ���� �� ���������� ��������� 
    {
        push(temp->data);                        // ��������� � ������ ������� �������
        temp = temp->next;                       // ��������� � ���������� �������� ������
    }
}

template <class T>
Ring<T>::Ring(Ring<T>&& other) noexcept : Head(other.Head), length(other.length) {
    other.Head = nullptr; 
    other.length = 0;
}

template <class T>
Ring<T>::~Ring() {
    clear();                                // �������� ������
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
    return (Head == nullptr); // ���������� true, ���� ��������� �� �������� ������� ����� nullptr, ����� false
}

template<class T>
bool Ring<T>::exist(T data) {
    Iterator it = begin();

    // �������� �� ���� ��������� ������
    for (int i = 0; i < length; ++i) {
        if (*it == data) { // ���� ����� �������, ������ ����������� data, ���������� true
            return true;
        }
        it++;
    }

    return false; // ���� ������� �� ������, ���������� false
}

template <class T> void Ring<T>::push(T data)	// ���������� ���������� ��������
{
    Element<T>* inserted;                       // ������� ����� ��������� �� �������
    inserted = new Element<T>;	                // �������� ������ ��� �������
    inserted->data = data;                      // ���������� ������� �������� � ���� ������ ��������
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
    length++;                     // ����������� ���������� ��������� � ������
}

template <class T>
T Ring<T>::pop() {

    if (isEmpty()) {

        std::cerr << "Error: Cannot pop from an empty ring.\n";
        return T(); // ���������� �������� �� ��������� ��� ���� T
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
        Element<T>* temp = Head->next;	// ��������� ��������� �� ������� ��� ��������
        Head->next = temp->next;	// ���������� ��������� �� ��������� �������
        temp->next->prev = Head;	// ��������� ��������� prev ���������� ��������
        delete temp;	// ������� ������� �������
        length--;	// ��������� ������� ���������� ���������

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
        return false; // ���� ����� ������� �� �����, ������ ����� �� �����
    }

    if (isEmpty() && const_cast<Ring<T>&>(other).isEmpty()) {
        return true; // ���� ��� ������ �����, ��� ��������� �������
    }

    Iterator it1 = const_cast<Ring<T>&>(*this).begin();
    Iterator it2 = const_cast<Ring<T>&>(other).begin();

    do {
        if (*it1 != *it2) {
            return false; // ���� ���� �� ���� ������� �� �����, ������ �� �����
        }
        it1++;
        it2++;
    } while (it1 != const_cast<Ring<T>&>(*this).begin() && it2 != const_cast<Ring<T>&>(other).begin());

    return true; // ���� ��� �������� �����, ������ �����
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
    if (this != &other) { // �������� �� ������������ ������ ����
        clear(); // ������� ������� ������ ����� ������������ ������� ������

        Element<T>* temp = other.Head; // ��������� �� ������ ������ other
        for (int i = 0; i < other.length; i++) {
            push(temp->data); // ��������� �������� �� ������ other � ������� ������
            temp = temp->next; // ��������� � ���������� �������� ������ other
        }
    }
    return *this;
}
template<class T>
Ring<T>& Ring<T>::operator=(Ring<T>&& other) noexcept {
    if (this != &other) { // �������� �� ������������ ������ ����
        clear(); // ������� ������� ������ ����� ������������ ������� ������

        // ��������� ��������� �� ������ ������ � ����� �� ������� other � ������� ������
        Head = other.Head;
        length = other.length;
        other.Head = nullptr; // ��������� �� ������ ������ � other ������ nullptr
        other.length = 0; // ����� ������ � other ����������
    }
    return *this;
}