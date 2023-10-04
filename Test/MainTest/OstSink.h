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
	* @brief Конструктор принимающий стандартый поток вывода
	* 
	* @param Поток вывода
	*/
	OstSink(ostream& a);
		
	/*!
	* @brief Запись строки в стандартный вывод
	* 
	* @param str Строка для вывода
	*/
	void writeString(const string& str) override;

private:
	ostream& ostream_; ///< Ссылка на стандартный поток вывода
};