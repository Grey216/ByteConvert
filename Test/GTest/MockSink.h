#pragma once
#include "Sink.h"
#include "gmock/gmock.h"
#include <string>
/*!
* @brief ����� ������ ��� ���������� Sink, ��������� Google Mock
*/
class MockSink : public Sink
{
public:
    /*!
    * @brief �������� ����� ��� �������� ������ ������
    *
    * @param str ������, ������� ���������� �������
    */
    MOCK_METHOD(void, writeString, (const std::string& str), (override));
};
