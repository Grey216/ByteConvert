#pragma once
#include "Source.h"
#include <vector>

using namespace std;


/*!
* @brief Реализация интерфейса Source для считывания байтов из вектора
*/
class VecSource : public Source {
private:
    vector<uint8_t> bytes; ///< Вектор байтов для чтения
    size_t index = 0; ///< Текущий индекс для чтения

public:

    /*!
    * @brief Конструктор класса
    * 
    * @param data Вектор байтов для чтения
    */
    VecSource(const std::vector<uint8_t>&data);

    /*!
    * @brief Конструктор класса
    * 
    * @param data Вектор байтов для чтения
    */
    VecSource(std::vector<uint8_t>&& data);

    /*!
     * @brief Чтение байта из вектора
     * 
     * @param byte Ссылка на байт, в который будет записан один из элементов вектора
     * @return Возвращает true, если чтение успешно, иначе false
     */
    bool readByte(uint8_t& byte) override;
};