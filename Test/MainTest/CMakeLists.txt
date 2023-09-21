add_executable(MainTest Main.cpp  "VecSource.cpp" "VecSource.h" "OstSink.cpp" "OstSink.h")
target_link_libraries(MainTest ByteConvert)