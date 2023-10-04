#include "OstSink.h"

OstSink::OstSink(ostream& a) : ostream_(a) {};

void OstSink::writeString(const string& str)
{
	ostream_ << str << endl;
}


