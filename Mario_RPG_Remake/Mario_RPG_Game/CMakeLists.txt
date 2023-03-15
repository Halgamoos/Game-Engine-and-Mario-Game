add_executable(Mario_RPG_Game main.cpp)

include_directories(../Mario_RPG_Engine/include)

target_link_libraries(Mario_RPG_Game Mario_RPG_Engine)