#define _CRT_SECURE_NO_WARNINGS
#include "TMyTextFile.h"
#include <string.h>
#include <utility>
#include <iostream>
#include <stdio.h>
#include <sys/stat.h>

TMyTextFile::TMyTextFile(const char* aFileName)
{
	fp = NULL;
	mode[0] = 'r';
	mode[1] = 0;
	strcpy(FileName, aFileName);
}

void TMyTextFile::Open(const char* fMode)
{
	if ((fp = fopen(FileName, fMode)) == NULL)
	{
		throw std::ios_base::failure("Can not open file!");
	};
	strcpy(mode, fMode);
}

void TMyTextFile::Close()
{
	fclose(fp);
}

void TMyTextFile::Append(const char* aString)
{

	fprintf(fp, aString);
}

void TMyTextFile::Write(const char* aString)
{
	if (fprintf(fp, aString)<0)
	{
		throw std::ios_base::failure("Can not write in file.");
	}
	return;
}

fpos_t TMyTextFile::GetPos()
{
	fpos_t tmp;
	if (fgetpos(fp, &tmp)) 
	{
		throw std::ios_base::failure("Can not read position.");
	}

	return tmp;
}

void TMyTextFile::SetPos(fpos_t aPos)
{
	if (fsetpos(fp, &aPos))
	{
		throw std::ios_base::failure("Can not set position.");
	}
	return;
}

fpos_t TMyTextFile::Size()
{
	fpos_t savePos = GetPos();
	fpos_t result;
	fgetpos(fp, &savePos);
	while (fgetc(fp) != EOF);
	fgetpos(fp, &result);
	SetPos(savePos);
	return result;
	//struct stat fi;
	//stat(FileName, &fi);
	//return fi.st_size;
}

void TMyTextFile::Save()
{
	Close();
	Open(mode);
}

fpos_t TMyTextFile::Find(const char* aSubStr, const fpos_t aStartPos)
{
	fpos_t result = -1;
	FILE* tempF;
	tempF = fopen(FileName, "r");
	char cur;
	fsetpos(tempF, &aStartPos);
	while ((cur = fgetc(tempF)) != EOF)
	{
		// проверяем совпадение
		if (cur == aSubStr[0]) {
			fpos_t curPos;
			fgetpos(tempF, &curPos);
			bool isFind = true;
			for (int i = 1; i < strlen(aSubStr); i++)
			{
				cur = fgetc(tempF);
				if ((cur == EOF)||(aSubStr[i] != cur)) {
					isFind = false;
					break;
				}
			}
			if (isFind) {
				result = curPos-1;
				break;
			}
			fsetpos(tempF, &curPos);
		};
	}

	fclose(tempF);
	return result;
}

void TMyTextFile::Print() const
{
	FILE* tempF;
	tempF = fopen(FileName, "r");
	char cur;
	while ((cur = fgetc(tempF)) != EOF)
	{
		std::cout << cur;
	}
	fclose(tempF);
}
