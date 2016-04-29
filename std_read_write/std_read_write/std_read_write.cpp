#include "stdafx.h"

#include <locale>
#include <codecvt>
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>

int main()
{
	// option A : windows style
	setlocale(LC_ALL, "");
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);

	// option B : crossplatform based on STD locales
	//const std::locale empty_locale = std::locale::empty();
	//typedef std::codecvt_utf8<wchar_t> converter_type;
	//const converter_type* converter = new converter_type;
	//const std::locale utf8_locale = std::locale(empty_locale, converter);
	//std::wcin.imbue(utf8_locale);

	std::wcout << L"Some texts with various characters: Yes, Süß, Да." << std::endl;
	std::wcout << std::endl;
	std::wcout << L"You will be asked for a text, type any to be replied with, or empty to end the application." << std::endl;

	while (true) {
		std::wstring str;
		std::wcout << L"Enter/乗り込む/Введите/ያስገቡ/প্রবেশ করান: ";
		std::getline(std::wcin, str);
		if (str.empty()) {
			break;
		}
		std::wcout << L"Введено (ßüs): \"" << str << "\"" << std::endl;
	}

	std::wcout << L"Финиш, Färtiß, Done." << std::endl;

	return 0;
}

