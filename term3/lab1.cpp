#include "Array.h" 
#include "functions.h" 

int main() {

    std::vector<Array> arrays;                // Создание вектора для хранения объектов класса Array
    int option = menu(); 
    while (option != EXIT) {                 // Основной цикл программы, продолжается, пока пользователь не выберет опцию EXIT

        if (option == CREATE_NEW_ARRAY) {   // Если пользователь выбрал опцию CREATE_NEW_ARRAY

            system("cls");
            int length = 0; 
            std::cout << "Input size of new array:\n>> ";
            std::cin >> length; 

            Array array(length);
            std::cout << "Input array:\n>> ";
            array.input(); 

            arrays.push_back(Array(array)); // Добавление созданного массива в вектор arrays

            std::cout << "Array created!" << std::endl;

            system("pause"); 
            system("cls"); 

        }
        else if (option == SHOW_ARRAY) { // Если пользователь выбрал опцию SHOW_ARRAY

            system("cls"); 

            std::cout << "All arrays:" << std::endl;
            for (const Array& array : arrays)
                array.show(); 

            system("pause"); 
            system("cls"); 

        }
        else if (option == FIND_INTERSECTION) {        // Если пользователь выбрал опцию FIND_INTERSECTION

            system("cls"); 

            if (arrays.size() < 2)
                std::cout << "At least two arrays are required to find the intersection." << std::endl;
            else {
                int idx1, idx2;
                std::cout << "Select two arrays to find the intersection (numbers from 0 to " << arrays.size() - 1 << "): ";
                std::cin >> idx1 >> idx2; 

                if (idx1 >= 0 && idx1 < arrays.size() && idx2 >= 0 && idx2 < arrays.size()) {
                    Array intersection = Array::findIntersection(arrays[idx1], arrays[idx2]);
                    std::cout << "Array intersection " << idx1 << " and " << idx2 << ": ";
                    for (int i = 0; i < intersection.getLen(); i++) {
                        std::cout << intersection.getArr()[i] << " ";
                    }
                    std::cout << std::endl;
                }
                else std::cout << "Invalid array index." << std::endl;

            }

            system("pause"); 
            system("cls"); 
        }

        option = menu(); // Запрос следующего выбора пользователя из меню
    }

    return 0;
}
