#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
bool isValid(const wstring& ws)
{
	for(auto c:ws) {
		if(!iswalpha(c) || !iswupper(c))
			return false;
	}
	return true;
}
int main(int argc, char **argv)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
	string key_s;
	string text_s;
	wstring text_ws;
	unsigned op;
	cout<<"Cipher ready. Input key: ";
	cin>>key_s;
	wstring key_ws = codec.from_bytes(key_s);
	key_s = codec.to_bytes(key_ws);
	if (!isValid(key_ws)) {
		cerr<<"key not valid\n";
		return 1;
	}
	cout<<"Key loaded\n";
	modAlphaCipher cipher(key_ws);
	do {
		cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
		cin>>op;
		if (op > 2) {
			cout<<"Illegal operation\n";
		} else if (op >0) {
			cout<<"Cipher ready. Input text: ";
			cin>>text_s;
			text_ws = codec.from_bytes(text_s);
			if (isValid(text_ws)) {
				if (op==1) {
					string encr = codec.to_bytes(cipher.encrypt(text_ws));
					cout<<"Encrypted text: "<<encr<<endl;
				} else {
					string decr = codec.to_bytes(cipher.decrypt(text_ws));
					cout<<"Decrypted text: "<<decr<<endl;
				}
			} else {
				cout<<"Operation aborted: invalid text\n";
			}
		}
	} while (op!=0);
	return 0;
}
