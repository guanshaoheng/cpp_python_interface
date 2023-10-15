#include <pybind11/pybind11.h>

class MyClass {
public:
    MyClass(int value) : value_(value) {}

    int getValue() const {
        return value_;
    }

    void setValue(int value) {
        value_ = value;
    }

private:
    int value_;
};

namespace py = pybind11;


PYBIND11_MODULE(my_module, m) {
    py::class_<MyClass>(m, "cpp_class")
        .def(py::init<int>())
        .def("get_value", &MyClass::getValue)
        .def("set_value", &MyClass::setValue);
}
// 上述为pybind11的宏命令，用于创建python中可调用的模块
// 其中 MyClass为C++代码中的类名
// "cpp_class"为注册到python中的类名
