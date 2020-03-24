#pragma once
// 1. Разработать класс File. 
// Предусмотреть функции для работы с файлом 
// – открытие файла, 
// - закрытие файла, 
// - чтение из файла, 
// - запись в файл, 
// - поиск в файле.
#include <stdio.h>

class TMyTextFile
{
private:
	FILE *fp;
	char FileName[256];
	char mode[5];


public:
	TMyTextFile(const char* aFileName);

	void Open(const char* fMode);
	void Close();
	void Append(const char* aString);
	void Write(const char* aString);
	fpos_t GetPos();
	void SetPos(fpos_t aPos);
	fpos_t Size();
	void Save();
	fpos_t Find(const char* aSubStr, const fpos_t aStartPos=0);
	void Print() const;
};

