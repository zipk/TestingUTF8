#include "stdafx.h"

#include <locale>
#include <codecvt>
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>

enum class EInitializeUnicodeInOut {
	WINDOWS_WAY,
	STD_WAY,
	DEFAULT_WAY, // no initialization would be done
};

int main()
{

	// hardcoded way of how initialization shall be done
	EInitializeUnicodeInOut wayToInit = EInitializeUnicodeInOut::WINDOWS_WAY;

	// init the environment to support UNICODE for in/out
	switch (wayToInit)
	{
	case EInitializeUnicodeInOut::WINDOWS_WAY: {
		// option A : windows style
		setlocale(LC_ALL, "");
		_setmode(_fileno(stdout), _O_WTEXT);
		_setmode(_fileno(stdin), _O_WTEXT);
		break;
	}
	case EInitializeUnicodeInOut::STD_WAY: {
		// option B : crossplatform based on STD locales
		const std::locale empty_locale = std::locale::empty();
		typedef std::codecvt_utf8<wchar_t> converter_type;
		const converter_type* converter = new converter_type;
		const std::locale utf8_locale = std::locale(empty_locale, converter);
		std::wcin.imbue(utf8_locale);
	}
	default:
		// no initialization?
		break;
	}

	// perform some print-outs of test data
	std::wcout << L"This app tests the following:" << std::endl;
	std::wcout << L"  - printing out UNICODE characters to the console via std::wcout." << std::endl;
	std::wcout << L"  - reading out UNICODE characters from the console via std:wcin." << std::endl;
	std::wcout << L"  - storing values in the std::wstring." << std::endl;
	std::wcout << L"  - putting into C++ source code UNICODE const strings (.cpp is with UTF16 LE BOM)." << std::endl;
	std::wcout << L"  - all things are checked yet on Windows only (other platforms are in plans)." << std::endl;
	std::wcout << std::endl;
	std::wcout << L"Some texts with various characters: Yes, Süß, Да." << std::endl;
	std::wcout << std::endl;
	std::wcout << L"You will be asked for a text, type any to be replied with, or empty to end the application." << std::endl;

	// loop to read a string from std::*in and put it into std::*cout
	while (true) {
		std::wstring str;
		std::wcout << L"Enter/乗り込む/Введите/ያስገቡ/প্রবেশ করান: ";
		std::getline(std::wcin, str);
		if (str.empty()) {
			break;
		}
		std::wcout << L"Введено (ßüs): \"" << str << "\"" << std::endl;
	}

	// finished
	std::wcout << L"Финиш, Färtiß, Done." << std::endl;

	return 0;
}

