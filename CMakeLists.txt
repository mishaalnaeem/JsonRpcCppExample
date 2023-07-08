cmake_minimum_required(VERSION 3.10)
project(rpcClient)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
find_package(Jsoncpp REQUIRED)
include_directories(${JSONCPP_INCLUDE_DIRS})



set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})

find_package(JsonRpcCpp REQUIRED)
include_directories(${JsonRpcCpp_INCLUDE_DIRS})
#include_directories(/usr/local/Cellar/libjson-rpc-cpp/1.4.1_2/include)

set(SOURCES
    main.cpp
    util.h
    #./usr/local/include/jsonrpccpp/client.h
    #./usr/local/include/jsonrpccpp/client/
)

add_executable(${PROJECT_NAME} ${SOURCES})

#target_link_libraries(${PROJECT_NAME} /usr/local/Cellar/libjson-rpc-cpp/1.4.1_2/lib/libjson-rpc-cpp.so)
#target_link_libraries(${JsonRpcCpp_LIBRARIES} ${JSONCPP_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${JsonRpcCpp_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${JSONCPP_LIBRARIES})

