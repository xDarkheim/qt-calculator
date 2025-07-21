cmake_minimum_required(VERSION 3.16)
project(Calculator)

set(CMAKE_CXX_STANDARD 20)

# Добавить флаги для отладки
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
endif()

# Установить пути поиска для Qt5
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/usr/lib/qt5" "/usr/lib/x86_64-linux-gnu/qt5" "/usr/lib/cmake/Qt5")

# Альтернативный способ поиска Qt5
if(NOT Qt5_DIR)
    set(Qt5_DIR "/usr/lib/cmake/Qt5")
endif()

# Настройка Qt5 и пути модулей
find_package(Qt5 COMPONENTS Core Widgets QUIET)

# Проверка наличия Qt5
if(NOT Qt5_FOUND)
    message(FATAL_ERROR "Qt5 не найден. Установите пакеты Qt5: sudo apt install qtbase5-dev qt5-qmake")
endif()

# Включение автоматической генерации MOC-файлов для Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(Calculator main.cpp
        Calculator.cpp
        Calculator.h)

target_link_libraries(Calculator Qt5::Core Qt5::Widgets)