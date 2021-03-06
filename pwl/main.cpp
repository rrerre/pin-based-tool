#include "MemoryAllocator.h"

int main(int argc, char *argv[])
{
	if( argc < 5 )
	{
		cerr << "Lack of args: need three args!" << endl;
		return -1;
	}

	ADDRINT nSizePower;
	stringstream ss(argv[1]);
	ss >> nSizePower;	
	cerr << "Memory Size (in bytes):\t" << hex << (1<<nSizePower) << dec << endl;	

	string szFile = argv[2];

	ADDRINT nLineSizeShift;
	stringstream ss1(argv[3]);
	ss1 >> nLineSizeShift;

	bool bStackAllocator = true;
	stringstream ss2(argv[4]);
	ss2 >> bStackAllocator;	

	
	

	CAllocator *allocator;

if(bStackAllocator)
	allocator = new CStackAllocator(nSizePower, nLineSizeShift, szFile);
else
	allocator = new CHeapAllocator(nSizePower, nLineSizeShift, szFile);


	allocator->run();
	return 0;
}
