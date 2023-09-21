#pragma once
#include <iostream>
#include <string>


/*!
* @brief ��������� ��� ������ ������ � ��������
*/
class Sink
{
public:
	/*!
	* @brief ����������� �� ���������
	*/
	Sink() = default;

	/*!
	* @brief ������ ������ � ��������
	*
	* @param str ������, ������� ���������� ������� 
	*/
	virtual void writeString(const std::string& str) = 0;

	/*!
	* @brief ����������� ���������� �� ���������
	*/
	virtual ~Sink() = default;
};




