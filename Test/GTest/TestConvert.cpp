/*!
* @file
* @brief ��������� ����� ��� ������ ByteToConvert � �������������� Google Test � Google Mock.
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
* @brief �������� ������ ��� �������� ����������� ����� � ��������� �������������.
*/
TEST(ByteToConvertTest, ConvertByteTest) {
    MockSource mockSource; ///< ����� ��������� ������.
    MockSink mockSink;     ///< ����� ��������� ������.

    
    // ������������� ��������
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
* @brief �������� ������ ��� �������� ����������� ���������� ����� � ��������� �������������.
*/
TEST(ByteToConvertTest, ConvertRandomByteTest) {
    MockSource mockSource; ///< ����� ��������� ������.
    MockSink mockSink;     ///< ����� ��������� ������.

    // ��������� ���������� �����
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(0, 255);
    uint8_t randomByte = dist(mt);
    uint8_t type = (randomByte >> 6) & 0x3; /// ����� 2 ������ ����
    uint8_t data = randomByte & 0x3F; /// ������� 2 ������ ����


    // ������������� ��������
    EXPECT_CALL(mockSource, readByte(_))
        .Times(2)
        .WillOnce(DoAll(SetArgReferee<0>(randomByte), Return(true)))
        .WillOnce(Return(false));

    // ��������� �������� ���������� ����� ������� �� �������� ���������������� �����.
    // ����� ������� ������� ��� ���� ��������� ���������.
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
* @brief �������� ������ ��� �������� ����������� ������� ��������� ������ � ��������� �������������.
*/
TEST(ByteToConvertTest, ConvertRandomByteArrayTest) {
    MockSource mockSource; ///< ����� ��������� ������.
    MockSink mockSink;     ///< ����� ��������� ������.

    // ��������� ������� ��������� ������
    const int ARRAY_SIZE = 100;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(0, 255);
    std::vector<uint8_t> randomBytes;

    ByteConvert converter(&mockSource, &mockSink);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        uint8_t randomByte = dist(mt);
        uint8_t type = (randomByte >> 6) & 0x3; /// ����� 2 ������ ����
        uint8_t data = randomByte & 0x3F; /// ������� 2 ������ ����
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