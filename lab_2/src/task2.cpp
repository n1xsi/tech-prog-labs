#include <iostream>
#include <fstream>
#include <string>
#include "tasks.h"

void findAndPrintQuotes(const std::string& text) {
    std::cout << "Найденные цитаты:" << std::endl;
    std::cout << "-----------------" << std::endl;

    size_t startPos = 0;
    bool found = false;

    while ((startPos = text.find('"', startPos)) != std::string::npos) {
        size_t endPos = text.find('"', startPos + 1);

        if (endPos != std::string::npos) {
            std::string quote = text.substr(startPos + 1, endPos - startPos - 1);
            std::cout << "- " << quote << std::endl;
            found = true;
            startPos = endPos + 1;
        } else {
            break;
        }
    }

    if (!found) {
        std::cout << "Цитаты в файле не найдены." << std::endl;
    }
}

void runTask2() {
    std::string filename = "input.txt";
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл '" << filename << "'" << std::endl;
        return;  // Если файла нет - выход из функции
    }

    std::cout << "Файл '" << filename << "' успешно открыт. Чтение содержимого..." << std::endl;

    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    inputFile.close();

    if (fileContent.empty()) {
        std::cout << "Файл пуст." << std::endl;
    } else {
        findAndPrintQuotes(fileContent);
    }
}