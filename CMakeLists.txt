cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(wxBUILD_SHARED OFF)

project(wxwidgets_sample)

find_package(wxWidgets COMPONENTS core base aui xrc html adv xml)

if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

set(INC_DIRS
  include
  rc
)

set(SRC_FILES
  src/appmain.cpp
)


add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INC_DIRS})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
