cmake_minimum_required(VERSION 3.12)
project(pybind_example)

# 查找Pybind11包
find_package(pybind11 REQUIRED)

# 创建C++库
add_library(funcpp MODULE func.cpp)

# 链接Pybind11库
target_link_libraries(funcpp PRIVATE pybind11::module)

# 设置Python模块扩展名（.pyd或.so）
# set_target_properties(example PROPERTIES SUFFIX ".pyd")
# 注意一定要有这句话，将编译好的文件的前缀设置为模块名才能调用，否则找不到该模块
set_target_properties(funcpp PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
                                        SUFFIX "${PYTHON_MODULE_EXTENSION}")


# boost python
find_package(Boost COMPONENTS python REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

# find_package(PythonLibs REQUIRED)
# include_directories(${PYTHON_INCLUDE_DIRS})
# set(PYTHON_LIBRARY "/path/to/your/python/library.so")
set(PYTHON_INCLUDE_DIR "/usr/include/python3.10")

add_library(funcpp_boost MODULE func_boost.cpp)

target_link_libraries(funcpp_boost ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
# 注意一定要有这句话，将编译好的文件的前缀设置为模块名才能调用，否则找不到该模块
set_target_properties(funcpp_boost PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
                                        SUFFIX "${PYTHON_MODULE_EXTENSION}")


