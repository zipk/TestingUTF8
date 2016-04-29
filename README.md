# TestingUTF8

(Main goal of the project - check capabilities/usability of the MS VS2015 integration with github)

Playground to check in C++ various utf8/UNICODE related routines and console apps.

This app tests the following:
* printing out UNICODE characters to the console via std::wcout.
* reading out UNICODE characters from the console via std:wcin.
* storing values in the std::wstring.
* putting into C++ source code UNICODE const strings (.cpp is with UTF16 LE BOM).
* all things are checked yet on Windows only (other platforms are in plans).


Environment used: MS VS2015 C++

