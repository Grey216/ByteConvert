#pragma once
#include <iostream>

/*!
* @brief ��������� ��� ������ ������ �� ���������
*/
class Source
{
public:
	/*!
	* @brief ����������� �� ���������
	*/
	Source() = default;

	/*!
	* @brief ������ ���� �� ���������
	* 
	* @param byte ������ �� ����������, � ������� ����� ������������ ��������� ����
	* @return ���������� true, ���� ���� ��� ������� ������ ����� false
	*/
	virtual bool readByte(uint8_t& byte) = 0;


	/*!
	* @brief ����������� ���������� �� ��������� 
	*/
	virtual ~Source()=default;
};




