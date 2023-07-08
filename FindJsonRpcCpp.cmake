find_path(JsonRpcCpp_INCLUDE_DIRS NAMES jsonrpccpp/client.h HINTS /usr/local/Cellar/libjson-rpc-cpp/1.3.0/include)
find_library(JsonRpcCpp_LIBRARIES NAMES jsonrpccpp-client HINTS /usr/local/Cellar/libjson-rpc-cpp/1.3.0/lib)

set(JsonRpcCpp_FOUND FALSE)
if(JsonRpcCpp_INCLUDE_DIRS AND JsonRpcCpp_LIBRARIES)
    set(JsonRpcCpp_FOUND TRUE)
endif()

if(JsonRpcCpp_FOUND)
    if(NOT JsonRpcCpp_FIND_QUIETLY)
        message(STATUS "Found libjson-rpc-cpp: ${JsonRpcCpp_LIBRARIES}")
    endif()
else()
    if(JsonRpcCpp_FIND_REQUIRED)
        message(FATAL_ERROR "Could not find libjson-rpc-cpp")
    endif()
endif()

mark_as_advanced(JsonRpcCpp_INCLUDE_DIRS JsonRpcCpp_LIBRARIES)