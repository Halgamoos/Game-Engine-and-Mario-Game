set(HEADER_FILES
    src/MarioRPGUtils.h
    src/MarioRPGApp.h
)

set(SOURCE_FILES
    src/MarioRPGApp.cpp
)

add_library(Mario_RPG_Engine SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DMARIORPG_LIB)