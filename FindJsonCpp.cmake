find_path(JSONCPP_INCLUDE_DIRS json/json.h HINTS /usr/local/Cellar/jsoncpp/1.9.5/include/json)
find_library(JSONCPP_LIBRARIES NAMES jsoncpp HINTS /usr/local/Cellar/jsoncpp/1.9.5/lib)

if (JSONCPP_INCLUDE_DIRS AND JSONCPP_LIBRARIES)
    set(JSONCPP_FOUND TRUE)
endif()

# Provide information about JSONcpp
if (JSONCPP_FOUND)
    message(STATUS "Found JSONcpp: ${JSONCPP_LIBRARIES}")
else()
    message(STATUS "JSONcpp not found")
endif()

# Export the variables
if (JSONCPP_FOUND)
    set(JSONCPP_INCLUDE_DIRS ${JSONCPP_INCLUDE_DIRS} CACHE PATH "Include directories for JSONcpp" FORCE)
    set(JSONCPP_LIBRARIES ${JSONCPP_LIBRARIES} CACHE FILEPATH "Link libraries for JSONcpp" FORCE)
endif()