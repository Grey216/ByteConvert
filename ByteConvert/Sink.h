#pragma once
#include <iostream>
#include <string>


/*!
* @brief Интерфейс для записи строки в приемник
*/
class Sink
{
public:
	/*!
	* @brief Конструктор по умолчанию
	*/
	Sink() = default;

	/*!
	* @brief Запись строки в приемник
	*
	* @param str Строка, которую необходимо вывести 
	*/
	virtual void writeString(const std::string& str) = 0;

	/*!
	* @brief Виртуальный диструктор по умолчанию
	*/
	virtual ~Sink() = default;
};




