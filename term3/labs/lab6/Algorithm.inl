template<class T>
int Algorithm<T>::partition(Ring<T>& ring, int low, int high, std::function<bool(const T&, const T&)> compare) {
    T pivot = ring.getAt(high);
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (compare(ring.getAt(j), pivot)) {
            ++i;
            std::swap(ring.getAt(i), ring.getAt(j));
        }
    }
    std::swap(ring.getAt(i + 1), ring.getAt(high));
    return i + 1;
}

template<class T>
void Algorithm<T>::quickSortUtil(Ring<T>& ring, int low, int high, std::function<bool(const T&, const T&)> compare) {
    if (low < high) {
        int pi = partition(ring, low, high, compare);
        quickSortUtil(ring, low, pi - 1, compare);
        quickSortUtil(ring, pi + 1, high, compare);
    }
}

template<class T>
void Algorithm<T>::quickSort(Ring<T>& ring, std::function<bool(const T&, const T&)> compare) {
    int n = ring.getLength();
    if (n <= 1) {
        return;
    }
    quickSortUtil(ring, 0, n - 1, compare);
}

template<class T>
void Algorithm<T>::saveInFile(Ring<T>& ring, const char* fileName) {

    std::ofstream outFile(fileName, std::ios::out); // Открытие файла для записи

    if (!outFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return;
    }

    // Итерируемся по кольцу и записываем данные в файл
    if (!ring.isEmpty()) {
        typename Ring<T>::Iterator it = ring.begin();
        
        do {
            outFile << *it << std::endl; // Запись данных элемента в файл
            it++;
        } while (it != ring.begin());
    }

    outFile.close(); // Закрываем файл
}

template<class T>
void Algorithm<T>::loadFromFile(Ring<T>& ring, const char* fileName, const std::string& target) {

    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        return;
    }

    std::string line;
    if (target == "ALL") { // Если target равен "ALL", добавляем все строки из файла
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            T data;
            if (iss >> data) {
                ring.push(data); // Добавляем элемент в кольцо
            }
        }
    }
    else {
        while (std::getline(inFile, line)) {
            if (target.empty() || line.find(target) == 0) { // Проверяем наличие target в строке
                std::istringstream iss(line);
                T data;
                if (iss >> data) {
                    ring.push(data); // Добавляем элемент в кольцо
                }
            }
        }
    }
    inFile.close();
}

template<class T>
void Algorithm<T>::removeFromFile(const char* fileName, const T& target) {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        return;
    }

    std::ostringstream tempFile;
    std::string line;
    bool found = false;

    while (std::getline(inFile, line)) {
        T data;
        std::istringstream iss(line);
        if (iss >> data) {
            if (data != target) {
                tempFile << line << std::endl; // Записываем во временный файл все строки, кроме той, которую нужно удалить
            }
            else {
                found = true; // Установка флага, что элемент был найден и удален
            }
        }
    }

    inFile.close();

    if (!found) {
        std::cerr << "Element not found in the file." << std::endl;
        return;
    }

    std::ofstream outFile(fileName, std::ios::trunc); // Открываем файл для записи, удаляя его содержимое
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        return;
    }

    outFile << tempFile.str(); // Записываем содержимое временного файла обратно в основной файл
    outFile.close();
}
