add_executable(mario_rpg_game main.cpp)

include_directories(../Mario_RPG_Engine/include)

target_link_libraries(mario_rpg_game Mario_RPG_Engine)