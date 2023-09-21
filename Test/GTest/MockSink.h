#pragma once
#include "Sink.h"
#include "gmock/gmock.h"
#include <string>
/*!
* @brief Макет класса для интерфейса Sink, использую Google Mock
*/
class MockSink : public Sink
{
public:
    /*!
    * @brief Макетный метод для имитации записи строки
    *
    * @param str Строка, которую необходимо вывести
    */
    MOCK_METHOD(void, writeString, (const std::string& str), (override));
};
