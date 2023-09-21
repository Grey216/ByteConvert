#pragma once

#include <iostream>
#include <thread>

#include "Sink.h"
#include "Source.h"

using namespace std;


/*!
* @brief Конвектирует байты в строки согласно заданной логике и передает результат в приемник
*/
class ByteConvert
{
public:
	/*!
	* @brief Конструктор
	* 
	* @param src Указатель на источник байтов
	* @param snk Указатель на приемник строк
	* 
	*/
	ByteConvert(Source* src, Sink* snk);

	/*!
	* @brief Запус процесса конвертации в отдельном потоке
	*/
	void start();

	/*!
	* @brief Остановка процесса конвертации и завершение потока
	*/
	void stop();

protected:
	/*!
	* @brief Конвектируем байт в строку согласно заданной логике
	*
	* @param byte Байт для конвертации
	* @return Строковое представление байта
	*/
	string convert(const uint8_t& byte);


private:
	Source* source; ///< Указатель на экземпляр источника байтов
	Sink* sink;		 ///< Указатель на экземпляр приемника строк
	thread work_th;	 ///< Поток в котром происходит конвертация

	/*!
	*@brief Считываем байты из источника, конвектируем их и передаем в приемник.  
	*/
	void run();

};