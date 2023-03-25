#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <locale>
#include <iostream>

/**
 * @brief Шифрование методом табличной перестановки
 * @details Ключ устанавливается в конструкторе,
 * а также с помощью метода set_key. Для зашифрования
 * и расшифрования предназначены методы encrypt и decrypt.
 * Метод set_tableform - вспомогающий. Методы: getValidKey, 
 * getValidOpenText, getValidCipherText - специализируются
 * на проверке входных данных.
 * @warning Реализация только для русского языка! С использованием wstring.
 */
class Cipher ///Шифрование методом табличной перестановки
{
private:

	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec; ///< codec для преобразования в широкий формат строки и обратно
	int columns; ///< Количество столбцов в таблице (ключ)
	int rows;  ///< Количество строк в таблице
	int len_text; ///< Количество символов в слове
public:
	Cipher()=delete; ///< Конструктор по умолчанию запрещён
	Cipher(std::wstring & ws_key); ///< Конструктор принимает ключ (количество столбцов в таблице)
	std::wstring encrypt( std::wstring& ws_open_text); ///< Метод для зашифрования
	std::wstring decrypt(const std::wstring& ws_cipher_text); ///< Метод для расшифрования
	void set_tableform(const std::wstring& ws_text); ///< Формирование информации о таблице
	void set_key(std::wstring & ws_key); ///< Установка нового ключа
	int getValidKey(std::wstring& ws_key); ///< Проверка на правильность ключа
	std::wstring getValidOpenText(const std::wstring & ws_open_text); ///< Проверка на правильность текста для зашифровки
	std::wstring getValidCipherText(const std::wstring & ws_cipher_text); ///< Проверка на правильность текста для расшифровки
};
/**
 * @file Cipher.h
 * @brief Класс-исключение
 */
class cipher_error: public std::invalid_argument /// Класс-исключение
{
public:
	/**
	 * @brief Принимает строку, поднимает исключение
	 * @param what_arg
	 */
	explicit cipher_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	/**
	* @brief Принимает си строку, поднимает исключение
	* @param what_arg
	*/
	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};
