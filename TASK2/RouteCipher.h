/** @file
 * @author Казанкин М.Н.
 * @version 1.0
 * @date 12.12.23
 * @copyright ИБСТ ПГУ
 * @warning Лабораторная работа №4
 * @brief Заголовочный файл для модуля шифра табличной перестановки
 */

#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
using namespace std;

/** @brief Шифрование методом Табличной перестановки
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для английского языка
 */
 
class RouteCipher
{
private:
	///ключ для конструктора
    int key;
public:
	///запретим конструктор без параметров
    RouteCipher() = delete;
    ///конструктор для установки ключа
    RouteCipher(int k);
    /**
    * @brief Метод для проверки текста для зашифрования/расшифрования \n
    * Все символы не принадлежащие английскому алфавиту удаляются \n
    * @param [in] text строка с сообщением типа string
    * @return строка типа string
    * @throw cipher_error, если строка пуста
   	*/
    string getValidText(const std::string & text);
    /**
    * @brief Зашифрование
    * @param [in] text Строка для зашифрования
    * @return Зашифрованная строка
    */   
    string encrypt(const string& text);
    /**
    * @brief Расшифровывание
    * @param [in] cioher_text Строка для зашифрования
    * @return Расшифрованная строка
    */
    string decrypt(const string& cipher_text);
};
 /** @brief класс-исключение cipher_error 
 * @details производный от класса std::invalid_argument \n
 * В данном классе перегружены конструкторы с параметрами. \n
 * При перегрузке явно указан вызов конструктора базового класса с параметром
 */
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
