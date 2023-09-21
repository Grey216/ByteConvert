/*!
* @file
* @brief Модульные тесты для класса ByteToConvert с использованием Google Test и Google Mock.
*/
#include <iostream>
#include "ByteConvert.h"
#include "MockSink.h"
#include "MockSource.h"
#include "gtest/gtest.h"

#include <random>

using namespace testing;

/*!
* @test ByteToConverterTest
* @brief Тестовый случай для проверки конвертации байта в строковое представление.
*/
TEST(ByteToConvertTest, ConvertByteTest) {
    MockSource mockSource; ///< Макет источника данных.
    MockSink mockSink;     ///< Макет приемника данных.

    
    // Устанавливаем ожидания
    EXPECT_CALL(mockSource, readByte(_))
        .Times(4)
        .WillOnce(DoAll(SetArgReferee<0>(0b00000000), Return(true)))
        .WillOnce(DoAll(SetArgReferee<0>(0b01000000), Return(true)))  
        .WillOnce(DoAll(SetArgReferee<0>(0b10000001), Return(true)))
        .WillOnce(Return(false)); 

    EXPECT_CALL(mockSink, writeString("0")).Times(2); 
    EXPECT_CALL(mockSink, writeString("b")).Times(1);

    ByteConvert converter(&mockSource, &mockSink);

    converter.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    converter.stop();
}

/*!
* @test ByteToConverterTest
* @brief Тестовый случай для проверки конвертации случайного байта в строковое представление.
*/
TEST(ByteToConvertTest, ConvertRandomByteTest) {
    MockSource mockSource; ///< Макет источника данных.
    MockSink mockSink;     ///< Макет приемника данных.

    // Генерация случайного байта
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(0, 255);
    uint8_t randomByte = dist(mt);
    uint8_t type = (randomByte >> 6) & 0x3; /// Берем 2 первых бита
    uint8_t data = randomByte & 0x3F; /// Убираем 2 первых бита


    // Устанавливаем ожидания
    EXPECT_CALL(mockSource, readByte(_))
        .Times(2)
        .WillOnce(DoAll(SetArgReferee<0>(randomByte), Return(true)))
        .WillOnce(Return(false));

    // Ожидаемые значения записанных строк зависят от случайно сгенерированного байта.
    // Здесь описаны условия для всех возможных категорий.
    if (type == 0b00) {  // unsigned int
        EXPECT_CALL(mockSink, writeString(std::to_string(data))).Times(1);
    }
    else if (type == 0b01) {  // signed int
        EXPECT_CALL(mockSink, writeString(std::to_string((data & 0x20 ? static_cast<int8_t>(data | 0xC0) :data)))).Times(1);
    }
    else if (type == 0b10) {  // char
        EXPECT_CALL(mockSink, writeString(('a' + data > 'z' ? "unknown"s : string(1, 'a' + data)))).Times(1);
    }
    else {  // unknown
        EXPECT_CALL(mockSink, writeString("unknown"s)).Times(1);
    }
 
    ByteConvert converter(&mockSource, &mockSink);

    converter.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    converter.stop();
}

/*!
* @test ByteToConverterTest
* @brief Тестовый случай для проверки конвертации массива случайных байтов в строковое представление.
*/
TEST(ByteToConvertTest, ConvertRandomByteArrayTest) {
    MockSource mockSource; ///< Макет источника данных.
    MockSink mockSink;     ///< Макет приемника данных.

    // Генерация массива случайных байтов
    const int ARRAY_SIZE = 100;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(0, 255);
    std::vector<uint8_t> randomBytes;

    ByteConvert converter(&mockSource, &mockSink);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        uint8_t randomByte = dist(mt);
        uint8_t type = (randomByte >> 6) & 0x3; /// Берем 2 первых бита
        uint8_t data = randomByte & 0x3F; /// Убираем 2 первых бита
        randomBytes.push_back(randomByte);

        EXPECT_CALL(mockSource, readByte(_)).Times(2)
            .WillOnce(DoAll(SetArgReferee<0>(randomByte), Return(true))).WillOnce(Return(false));

        if (type == 0b00) {  // unsigned int
            EXPECT_CALL(mockSink, writeString(std::to_string(data))).Times(1);
        }
        else if (type == 0b01) {  // signed int
            EXPECT_CALL(mockSink, writeString(std::to_string((data & 0x20 ? static_cast<int8_t>(data | 0xC0) : data)))).Times(1);
        }
        else if (type == 0b10) {  // char
            EXPECT_CALL(mockSink, writeString(('a' + data > 'z' ? "unknown"s : string(1, 'a' + data)))).Times(1);
        }
        else {  // unknown
            EXPECT_CALL(mockSink, writeString("unknown"s)).Times(1);
        }
        

        converter.start();
        converter.stop();

    }


    
}


int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}