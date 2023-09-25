# ByteConvert

ByteConvert - это библиотека для конвертации байтов в строки согласно определенной логике. Она предоставляет простой и удобный интерфейс для чтения байтов из различных источников, их конвертации и последующей записи в различные приемники.

## Основные особенности

- Преобразование байтов в строки на основе двух старших битов байта.
- Поддержка многопоточной конвертации.
- Гибкий интерфейс для чтения и записи данных.

## Установка

Для сборки проекта используется CMake. Следуйте этим шагам:

```bash
mkdir build
cd build
cmake ..
make
```

## Пример использования

```cpp
#include "ByteConvert.h"
#include "VecSource.h"
#include "OstSink.h"

int main() {
    // Создание вектора байтов
    std::vector<uint8_t> data = { ... };

    // Инициализация источника и приемника
    VecSource source(data);
    OstSink sink(std::cout);

    // Конвертация и вывод
    ByteConvert converter(&source, &sink);
    converter.start();
    converter.stop();

    return 0;
}
```

## Тестирование

Проект содержит модульные тесты на базе Google Test. Для запуска тестов выполните следующие команды:

```bash
cd build
./TestRunner
```
