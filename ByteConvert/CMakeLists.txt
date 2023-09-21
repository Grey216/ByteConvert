add_library (ByteConvert STATIC "ByteConvert.cpp" "ByteConvert.h" "Source.h" "Sink.h")

target_include_directories(ByteConvert PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})