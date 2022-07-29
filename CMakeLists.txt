file(GLOB sourcefiles "Src/*.cpp")
file(GLOB headerfiles "*.hpp")
add_executable(HFT ${sourcefiles} ${headerfiles} Trades.cpp Trades.h main.cpp CSVRow.h)