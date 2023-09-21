#pragma once
#include "gmock/gmock.h"
#include "Source.h"

/*!
* @brief ћакет класса дл€ интерфейса Source, использую Google Mock
*/
class MockSource : public Source
{
public:
    /*!
    * @brief ћакетный метод дл€ имитации чтени€ байта
    *
    * @param byte —сылка на переменную, в которую будет записыватьс€ считанный байт
    * @return ¬озвращает true, если байт был успешно считан иначе false
    */
    MOCK_METHOD(bool, readByte, (uint8_t& byte), (override));
};


