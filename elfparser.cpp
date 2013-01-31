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

#include "cELFFile.h"
#include <iostream>

using namespace std;

INT main(INT argc, CHAR* argv[])
{
	cELFFile *file = new cELFFile("D:\\Code Drafts\\elfparser\\Debug\\helloc++");

	if (file->FileLoaded) 
		cout << "File is loaded" << endl << file->Filename << endl;

	cout << endl << "Sections: " << file->nSections << endl << endl;

	/*for (UINT j=0; j<file->nSections; j++)
	{
		cout << "\t" << file->Sections[j].Name << endl;
	}*/

	cout << endl << "Imports: " << file->nImports << endl << endl;

	for (UINT i=0; i<file->nImports; i++)
	{
		DWORD t = file->Imports[i].Tag;
		if (t==DT_NEEDED || t==DT_SONAME || t==DT_RPATH)
			cout << "\t" << file->Imports[i].Name << endl;

		else if (t==DT_PLTGOT || t==DT_HASH || t==DT_STRTAB || t==DT_SYMTAB || t==DT_RELA || 
			t==DT_INIT || t==DT_FINI || t==DT_REL || t==DT_JMPREL || t==DT_GNU_HASH ||
			t==SHT_GNU_VERNEED || t==DT_VERSYM)
			cout << "\t" << (PDWORD)file->Imports[i].Value << endl;
		else
			cout << "\t" << file->Imports[i].Value << " (bytes)" << endl;
	}

	cout << endl << "DynamicSymbols: " << file->nDynamicSymbols << endl << endl;

	/*for (UINT k=0; k<file->nDynamicSymbols; k++)
	{
		cout << "\t" << file->DynamicSymbols[k].Name << endl;
	}*/
	
	cout << endl << "Symbols: " << file->nSymbols << endl << endl;

	/*for (UINT k=0; k<file->nSymbols; k++)
	{
		cout << "\t" << (PDWORD)file->Symbols[k].Address << "\t" << file->Symbols[k].Name << endl;
	}*/
	system("PAUSE");
	return 0;
};
