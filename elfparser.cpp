#include "cELFFile.h"
#include <iostream>

using namespace std;

INT main(INT argc, CHAR* argv[])
{
	cELFFile *file = new cELFFile("D:\\Code Drafts\\elfparser\\Debug\\helloc++");

	if (file->FileLoaded) 
		cout << "File is loaded" << endl << file->Filename << endl;

	cout << endl << "Sections: " << file->nSections << endl << endl;

	for (UINT j=0; j<file->nSections; j++)
	{
		cout << "\t" << file->Sections[j].Name << endl;
	}

	cout << endl << "Imports: " << file->nImports << endl << endl;

	for (UINT i=0; i<file->nImports; i++)
	{
		cout << "\t" << file->Imports[i].Name << endl;
	}

	cout << endl << "DynamicSymbols: " << file->nDynamicSymbols << endl << endl;

	for (UINT k=0; k<file->nDynamicSymbols; k++)
	{
		cout << "\t" << file->DynamicSymbols[k].Name << endl;
	}
	
	cout << endl << "Symbols: " << file->nSymbols << endl << endl;

	for (UINT k=0; k<file->nSymbols; k++)
	{
		cout << "\t" << (PDWORD)file->Symbols[k].Address << "\t" << file->Symbols[k].Name << endl;
	}
	system("PAUSE");
	return 0;
};