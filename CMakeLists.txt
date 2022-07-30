file(GLOB sourcefiles "Src/*.cpp")
file(GLOB headerfiles "*.hpp")
add_executable(HFT ${sourcefiles} ${headerfiles} main.cpp CSVRow.h)