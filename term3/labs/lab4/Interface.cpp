#include "Interface.h"

void Interface() {

    while (1) {

        system("cls");
        setlocale(LC_ALL, "rus");
        std::cout << "�������� ��� ����������� Ring" << std::endl;

        int choice;
        std::cout << "1. int" << std::endl
                << "2. ����� String" << std::endl
                << "3. ����� Educator" << std::endl
                << "0. �����" << std::endl;

        std::cout << "��� �����: ";
        std::cin >> choice;

        switch (choice) {

        case INT: {

            Ring<int> ring;
            menu(ring);
            break;
        }
        case STRING: {

            Ring<String> ring;
            menu(ring);
            break;
        }
        case EDUCATOR: {

            Ring<Educator> ring;
            menu(ring);
            break;
        }
        case EXIT:

            return;

        default:

            std::cout << "������!" << std::endl;
            break;
        }
    }
}

template<typename T>
void menu(Ring<T>& ring) {

    system("cls");
    setlocale(LC_ALL, "rus");

    int choice;
    std::cout << "1. �������� ��������" << std::endl
        << "2. ������� �������" << std::endl
        << "3. ��������� Ring �� ������� ���������� ��������" << std::endl
        << "4. ���������� Ring" << std::endl
        << "0. �����" << std::endl;

    std::cout << "��� �����: ";
    std::cin >> choice;

    do {

        switch (choice) {

        case ADD:

            system("cls");
            addElements(ring);
            break;

        case DELETE: {

            system("cls");

            T element;
            std::cout << "������� �������, ������� �� ������ �������" << std::endl;
            std::cin.ignore();
            std::cin >> element;
            deleteElement(ring, element);
            break;
        }

        case CHECK: {

            system("cls");

            T element;
            std::cout << "������� �������, ������� �� ������ ���������" << std::endl;
            std::cin.ignore();
            std::cin >> element;
            checkValue(ring, element);
            break;
        }

        case SHOW:

            system("cls");
            ring.print();
            break;

        case EXIT:

            return;

        default:
            break;
        }

        system("pause");
        system("cls");

        std::cout << "1. �������� ��������" << std::endl
            << "2. ������� �������" << std::endl
            << "3. ��������� Ring �� ������� ���������� ��������" << std::endl
            << "4. ���������� Ring" << std::endl
            << "0. �����" << std::endl;

        std::cout << "��� �����: ";
        std::cin >> choice;

    } while (choice);

    return;
}

template <class T>
void addElements(Ring<T>& ring) {

    int count;
    T inserted;
    std::cout << "������� ��������� �� ������ ��������?" << std::endl;
    std::cin >> count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 1; i <= count; i++) {
        std::cout << i << ": ";
        std::cin >> inserted;
        ring.push(inserted);
    }
}

template <class T>
void deleteElement(Ring<T>& ring, T dataToDelete) {

    if (ring.isEmpty()) {
        std::cout << "Ring is empty!" << std::endl;
        return;
    }

    ring.deleteElement(dataToDelete);
}

template <class T>
void checkValue(Ring<T>& ring, T dataToCheck) {

    if (ring.isEmpty()) {
        std::cout << "Ring is empty!" << std::endl;
        return;
    }

    if (ring.contains(dataToCheck))
        std::cout << "Ring contains your value" << std::endl;
    else 
        std::cout << "Ring doesn't contain your value" << std::endl;
}
