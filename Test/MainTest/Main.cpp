#include <iostream>
#include <vector>

#include "ByteConvert.h"
#include "OstSink.h"
#include "VecSource.h"


using namespace std;



int main()
{	
	vector<uint8_t> data = { 0b00101110, 0b11100001, 0b01100010, 0b10000001, 0b01001100 };

	VecSource source(data);
	OstSink sink(cout);

	ByteConvert con(&source, &sink);
	con.start();
	con.stop();

	return 0;
}

