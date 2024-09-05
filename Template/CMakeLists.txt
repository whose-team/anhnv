cmake_minimum_required(VERSION 3.29)
project(Template)

set(CMAKE_CXX_STANDARD 17)

add_executable(Template main.cpp
        DFS_Visit.h
        BFS_Visit.h
        KhopVaCau.h
        SangNguyenTo.cpp
        DuongDiNganNhat_FordBellman.cpp
        DuongDiNganNhat_Dijkstra.cpp
        DuongDiNganNhat_Dijkstra_Heap.cpp
        DuongDiNganNhat_Floyd_FullPath.cpp
        ThanhPhanLienThongTrenDoThiCoHuong.cpp
        SongLienThong.cpp)
