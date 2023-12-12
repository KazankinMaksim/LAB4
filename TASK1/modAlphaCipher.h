/** @file
 * @author Казанкин М.Н.
 * @version 1.0
 * @date 12.12.23
 * @copyright ИБСТ ПГУ
 * @warning Лабораторная работа №4
 * @brief Заголовочный файл для модуля Gronsfeld
 */

#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>

/** @brief Шифрование методом Гронсфельда
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для русского языка
 */
 class modAlphaCipher {

    private:
        ///алфавит по порядку
        std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        ///ассоциативный массив "номер по символу"
        std::map <char,int> alphaNum;
        ///ключ 
        std::vector <int> key; 
        /**
        * @brief Преобразование строка-вектор
        * @param [in] s Строка
        * @return Вектор типа int
        */
        std::vector<int> convert(const std::wstring& s); //преобразование строка-вектор
        /**
        * @brief Преобразование вектор-строка
        * @param [in] v Вектор типа int
        * @return string
        */
        std::wstring convert(const std::vector<int>& v); //преобразование вектор-строка
        /**
        * @brief Проверка на хороший ключ
        * @param [in] s Строка wstring
        * @return Строка wstring
        * @throw cipher_error, если ключ пустой или в ключе находится символ не принадлежащий алфавиту 
        */
        std::wstring getValidKey(const std::wstring & s);
        /**
        * @brief Метод для валидации открытого текста \n
        * Все символы не принадлежащие алфавиту игнорируются \n
        * Все строчные символы преобразуются к прописным
        * @param [in] s Строка wstring
        * @return Строка wstring
        * @throw cipher_error, если текст пустой 
        */
        std::wstring getValidOpenText(const std::wstring & s);
        /**
        * @brief Метод для валидации текста зашифрования \n
        * @param [in] s Строка wstring
        * @return Строка wstring
        * @throw cipher_error, если текст пустой и в тексте содержатся строчные буквы 
        */
        std::wstring getValidCipherText(const std::wstring & s);
    public:
        ///запретим конструктор без параметров
        modAlphaCipher()=delete; 
        ///конструктор для установки ключа
        modAlphaCipher(const std::wstring& skey); 
        /**
         * @brief Зашифровывание
         * @param [in] open_text Открытый текст. Не должен быть пустой строкой.
         * Строчные символы автоматически преобразуются к 
        прописным.
        * Все не-буквы удаляются
        * @return Зашифрованная строка
        * @throw cipher_error, если текст пустой
        */
        std::wstring encrypt(const std::wstring& open_text); //зашифрование
        /**
         * @brief Расшифровывание
         * @param [in] cipher_text Строка для зашифрования
        * @return Расшифрованная строка
        * @throw cipher_error, если текст пустой
        */
        std::wstring decrypt(const std::wstring& cipher_text);//расшифрование
};

/** @brief класс-исключение cipher_error 
 * @details производный от класса std::invalid_argument
 * В данном классе перегружены конструкторы с параметрами. \n
 * При перегрузке явно указан вызов конструктора базового класса с параметром
 */

class cipher_error: public std::invalid_argument {
    public:
        explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
        explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
