#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

void reverseWord(std::string word) {
    std::reverse(word.begin(), word.end());
    std::cout << "Слово задом наперед: " << word << std::endl;
}

void removeVowels(std::string word) {
    std::string vowels = "аеёиоуыэюя";
    word.erase(std::remove_if(word.begin(), word.end(), [vowels](char c) {
        return vowels.find(c) != std::string::npos;
        }), word.end());
    std::cout << "Слово без гласных: " << word << std::endl;
}

void removeConsonants(std::string word) {
    std::string consonants = "бвгджзйклмнпрстфхцчшщ";
    word.erase(std::remove_if(word.begin(), word.end(), [consonants](char c) {
        return consonants.find(c) != std::string::npos;
        }), word.end());
    std::cout << "Слово без согласных: " << word << std::endl;
}

void shuffleWord(std::string word) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(word.begin(), word.end(), g);
    std::cout << "Рандомно раскиданные буквы: " << word << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    int choice;
    std::cout << "Выберите действие:\n1. Слово выводится задом наперед.\n2. Вывести слово без гласных.\n3. Вывести слово без согласных.\n4. Рандомно раскидывать буквы заданного слова.\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        reverseWord(word);
        break;
    case 2:
        removeVowels(word);
        break;
    case 3:
        removeConsonants(word);
        break;
    case 4:
        shuffleWord(word);
        break;
    default:
        std::cout << "Неверный выбор. Попробуйте еще раз.\n";
    }

    return 0;
}

// Функция для удаления согласных из слова
// s// td::string removeConsonants(std::string word) {
//    std::string russianVowels = "аоуыэеёюя";
//     word.erase(std::remove_if(word.begin(), word.end(), [&russianVowels](char c) {
//        return !std::ispunct(c) && !std::isspace(c) && !russianVowels.find(std::tolower(c)) != std::string::npos;
//        }), word.end());
//    return word;
// }



    