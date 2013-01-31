/*
 *
 *  Copyright (C) 2013  Anwar Mohamed <anwarelmakrahy[at]gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to Anwar Mohamed
 *  anwarelmakrahy[at]gmail.com
 *
 */

#include "elf.h"
#include "cFile.h"


/* elf parser */
struct SECTIONS 
{
	char* Name;
	DWORD Address;
	DWORD Offset;
	DWORD Size;
};

struct DYNAMICSYMBOLS 
{
	char* Name;
	DWORD Address;
	DWORD Offset;
	//DWORD Size;
};

struct SYMBOLS 
{
	char* Name;
	DWORD Address;
	DWORD Offset;
	//DWORD Size;
};

struct DYNAMICS
{
	DWORD Address;
	DWORD Offset;
	DWORD Value;
	DWORD Tag;
	//char* Name;
};

struct IMPORTS
{
	DWORD Tag;
	DWORD Value;
	char* Name;
};

class cELFFile : public cFile {
private:

	//Functions:
	bool ParseELF();
	void initSections();
	void initDynSymbols();
	void initImports();
	void initSymbols();

	char* sStringTable;
	char* dStringTable;
	unsigned int DynSymArray;
	unsigned int SymArray;
	unsigned int DynArray;
	Elf32_Sym* DynamicSymbolsTable;
	Elf32_Sym* SymbolsTable;
	Elf32_Dyn* DynamicTable;
	
public:
	//Variables
	bool FileLoaded;
	elf32_header* ExeHeader;
	elf32_program_header* PHeader;
	elf32_section_header* SHeader;

	unsigned int nSections;
	unsigned int nSymbols;
	unsigned int nImports;
	unsigned int nDynamics;
	unsigned int nDynamicSymbols;

	SECTIONS* Sections;
	DYNAMICSYMBOLS* DynamicSymbols;
	SYMBOLS* Symbols;
	IMPORTS* Imports;
	DYNAMICS* Dynamics;
	
	DWORD Magic;
	DWORD Subsystem;
	DWORD SizeOfImage;
	DWORD SizeOfHeader;
	DWORD SizeOfProgramHeader;
	DWORD Entrypoint;
	unsigned short int Type;

	//Functions
	cELFFile(char* szFilename);
	cELFFile(char* buffer,DWORD size);
	~cELFFile();
	static bool identify(cFile* File);
	DWORD RVAToOffset(DWORD RVA);
	DWORD OffsetToRVA(DWORD RawOffset);

};
