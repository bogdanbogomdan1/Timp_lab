#pragma once
#include <string>
class Cipher
{
private:
	int columns, rows, len_text;
public:
	Cipher()=delete;
	Cipher(const int& key);
	std::wstring encrypt(const std::wstring& open_text);
	std::wstring decrypt(const std::wstring& cipher_text);
	void set_tableform(const std::wstring& text);
	void set_key(const int& key);
};
