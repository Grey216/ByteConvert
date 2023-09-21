#pragma once
#include "Source.h"
#include <vector>

using namespace std;


/*!
* @brief ���������� ���������� Source ��� ���������� ������ �� �������
*/
class VecSource : public Source {
private:
    vector<uint8_t> bytes; ///< ������ ������ ��� ������
    size_t index = 0; ///< ������� ������ ��� ������

public:

    /*!
    * @brief ����������� ������
    * 
    * @param data ������ ������ ��� ������
    */
    VecSource(const std::vector<uint8_t>&data);

    /*!
    * @brief ����������� ������
    * 
    * @param data ������ ������ ��� ������
    */
    VecSource(std::vector<uint8_t>&& data);

    /*!
     * @brief ������ ����� �� �������
     * 
     * @param byte ������ �� ����, � ������� ����� ������� ���� �� ��������� �������
     * @return ���������� true, ���� ������ �������, ����� false
     */
    bool readByte(uint8_t& byte) override;
};