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
	//DWORD Address;
	//DWORD Offset;
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
