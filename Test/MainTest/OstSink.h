#pragma once

#include "Sink.h"
using namespace std;
/*!
* @brief ���������� ���������� Sink, ��������� ������ � ����������� ����� 
*/
class OstSink :public Sink
{
public:
	/*!
	* @brief ������ ������ � ����������� �����
	* 
	* @param str ������ ��� ������
	*/
	void writeString(const string& str) override;

};