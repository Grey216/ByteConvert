#pragma once
#include <iostream>

/*!
* @brief Интерфейс для чтения байтов из источника
*/
class Source
{
public:
	/*!
	* @brief Конструктор по умолчанию
	*/
	Source() = default;

	/*!
	* @brief Читает байт из источника
	* 
	* @param byte Ссылка на переменную, в которую будет записываться считанный байт
	* @return Возвращает true, если байт был успешно считан иначе false
	*/
	virtual bool readByte(uint8_t& byte) = 0;


	/*!
	* @brief Виртуальный диструктор по умолчанию 
	*/
	virtual ~Source()=default;
};




