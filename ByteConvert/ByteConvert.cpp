#include "ByteConvert.h"

ByteConvert::ByteConvert(Source* src, Sink* snk):source(src),sink(snk){}

void ByteConvert::start()
{
	work_th = thread(&ByteConvert::run, this);
}

void ByteConvert::stop()
{
	if (work_th.joinable())
	{
		work_th.join();
	}
}

void ByteConvert::run()
{
	uint8_t byte;
	while (source->readByte(byte))
	{
		sink->writeString(convert(byte));
	}
}

string ByteConvert::convert(const uint8_t& byte)
{
	uint8_t type = (byte >> 6) & 0x3; /// Берем 2 первых бита
	uint8_t data = byte & 0x3F; /// Убираем 2 первых бита

	switch (type)
	{
	case 0b00: /// unsigned
		return to_string(data);
	case 0b01: /// signed 
		return to_string(static_cast<int8_t>(data<<2)>>2); /// Идентично to_string((32>a?a:a-64)) или to_string((a & 0x20 ? static_cast<int8_t>(a | 0xC0) : a))
	case 0b10: /// char
		return ('a' + data > 'z' ? "unknown"s : string(1, 'a' + data));
	default:
		 return "unknown"s;
	}

}