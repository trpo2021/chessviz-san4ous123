#Минимальная версия CMake
cmake_minimum_required(VERSION 3.16)

#Имя проекта
project(chess)

#Добавление субдиректории
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gtest"
"google test"
)

#Главная цель
add_executable(chess
src/main.cpp
)

#Тестовая цель
add_executable(test_list
test/test_list.cpp
)

#Сборка библиотеки
add_library(chesslib 
src/chesslib.cpp
src/include/chesslib.hpp
)

#Добавление ресурсов программы к тестам 
target_include_directories(
test_list PRIVATE 
"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

#Линковка библиотек к test_list
target_link_libraries(
test_list PRIVATE
gtest 
gtest_main 
chesslib
)

#Линковка библиотек к chess
target_link_libraries(chess
chesslib
)

#Указание папку с заголовками
include_directories(
src/include
gtest/googletest/include/gtest
)