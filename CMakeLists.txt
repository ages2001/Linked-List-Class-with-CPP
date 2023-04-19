cmake_minimum_required(VERSION 3.23)
project(StudentDoublyLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(StudentDoublyLinkedList main.cpp Student.cpp Student.h Node.cpp Node.h DoublyLinkedList.cpp DoublyLinkedList.h)
