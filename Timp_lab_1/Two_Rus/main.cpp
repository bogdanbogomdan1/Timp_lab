#include <iostream>
#include "Cipher.h"
#include <locale>
#include <codecvt>
using namespace std;
int main(int argc, char **argv)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
	int key;
	wstring text;
	unsigned op;
	wcout<<L"Введите ключ(Кол-во столбцов): ";
	wcin>>key;
	Cipher cipher(key);
	do {
		wcout<<L"Выберите операцию (0-exit, 1-encrypt, 2-decrypt, 3-setkey): ";
		wcin>>op;
		if (op > 3) {
			wcout<<L"Не может быть, попробуй другую операцию\n";
		} else if (op > 0 && op < 3) {
			wcout<<L"Введите текст: ";
			wcin>>text;
			if (op==1) {
				wcout<<L"Зашифрованный текст: "<<cipher.encrypt(text)<<endl;
			} else {
				wcout<<L"Расшифрованный текст: "<<cipher.decrypt(text)<<endl;
			}
		} else if (op == 3) {
			wcout<<L"Введите ключ заново: ";
			wcin>>key;
			cipher.set_key(key);
		}
	} while (op!=0);
	return 0;
}
