#include <Cipher.h>
Cipher::Cipher(const int& key) {columns = key;}
void Cipher::set_key(const int& key) {columns = key;}
void Cipher::set_tableform(const std::wstring& open_text)
{
	len_text = open_text.size();
	if (len_text>columns) {
		rows = len_text/columns;
		if (len_text%columns >0) rows+=1;
	} else {
		rows = 1;
	}
}
std::wstring Cipher::encrypt(const std::wstring& open_text)
{
	set_tableform(open_text);
	std::wstring table_chiper[rows][columns];
	int nums_text = 0;
	for (int y=0; y<rows; y++) {
		for (int x=0; x<columns; x++) {
			if (nums_text < len_text) {
				table_chiper[y][x] = open_text[nums_text];
			} else {
				table_chiper[y][x] = L"-";
			}
			nums_text++;
		}
	}
	std::wstring encrypt_text;
	for (int x=columns-1; x>=0; x--) {
		for (int y=0; y<rows; y++) {
			encrypt_text+=table_chiper[y][x];
		}
	}
	return encrypt_text;
}
std::wstring Cipher::decrypt(const std::wstring& cipher_text)
{
	set_tableform(cipher_text);
	std::wstring table_chiper[rows][columns];
	int nums_text = 0;
	for (int x=columns-1; x>=0; x--) {
		for (int y=0; y<rows; y++) {
			table_chiper[y][x] = cipher_text[nums_text];
			nums_text++;
		}
	}
	std::wstring decrypt_text;
	for (int y=0; y<rows; y++) {
		for (int x=0; x<columns; x++) {
			decrypt_text+=table_chiper[y][x];
		}
	}
	return decrypt_text;
}
