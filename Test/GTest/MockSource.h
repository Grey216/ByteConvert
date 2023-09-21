#pragma once
#include "gmock/gmock.h"
#include "Source.h"

/*!
* @brief ����� ������ ��� ���������� Source, ��������� Google Mock
*/
class MockSource : public Source
{
public:
    /*!
    * @brief �������� ����� ��� �������� ������ �����
    *
    * @param byte ������ �� ����������, � ������� ����� ������������ ��������� ����
    * @return ���������� true, ���� ���� ��� ������� ������ ����� false
    */
    MOCK_METHOD(bool, readByte, (uint8_t& byte), (override));
};


