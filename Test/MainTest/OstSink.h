#pragma once

#include "Sink.h"
using namespace std;
/*!
* @brief Реализация интерфейса Sink, выводящая строки в стандартный вывод 
*/
class OstSink :public Sink
{
public:
	/*!
	* @brief Запись строки в стандартный вывод
	* 
	* @param str Строка для вывода
	*/
	void writeString(const string& str) override;

};