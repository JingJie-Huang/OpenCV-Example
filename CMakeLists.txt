# 設定cmake最小版本
cmake_minimum_required( VERSION 2.8 )
# 設定專案名稱
project( imageBasics )

# 設定C++ 11標準
set( CMAKE_CXX_FLAGS "-std=c++11" )

# 尋找OpenCV函式庫
find_package( OpenCV 3 REQUIRED )
# 加入頭文件
include_directories( ${OpenCV_INCLUDE_DIRS} )

# 加入要編譯成執行檔的.cpp檔案
add_executable( Basic Basic.cpp )
# 鏈結OpenCV函式庫
target_link_libraries( Basic ${OpenCV_LIBS} )
