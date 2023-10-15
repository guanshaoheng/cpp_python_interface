#include <pybind11/pybind11.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b){
    return a-b;
}

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

PYBIND11_MODULE(funcpp, m) {
    m.def("add", &add, "A function that adds two numbers.");
    m.def("subtract", &subtract, "A function that subtract two numbers.");

    pybind11::class_<MyClass>(m, "cpp_class")  // 注册C++中的类 MyClass，在python中为cpp_class
        .def(pybind11::init<int>())            // 注册析构函数
        .def("get_value", &MyClass::getValue)  // 注册类的方法
        .def("set_value", &MyClass::setValue); // 注册类的方法
}
// funcpp 为模块名，注意此名字需要与CMakeLists.txt文件中的编译库名相同（不知道是不是可以不同，但是避免错误此处相同）



