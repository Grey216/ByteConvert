#include "VecSource.h"

VecSource::VecSource(const vector<uint8_t>& data):Source(),bytes(data){}

VecSource::VecSource(vector<uint8_t>&& data):Source(),bytes(std::move(data)){}

bool VecSource::readByte(uint8_t& byte)
{
	if (index < bytes.size())
	{
		byte = bytes[index++];
		return true;
	}
	return false;
}


