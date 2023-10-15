#include <boost/python.hpp>


int add(int a, int b) {
    return a + b;
}


class MyClass {
public:
    MyClass(int value) : value_(value) {}

    int getValue() {
        return value_;
    }

    void setValue(int newValue) {
        value_ = newValue;
    }

private:
    int value_;
};


BOOST_PYTHON_MODULE(funcpp_boost) {
    using namespace boost::python;
    def("add", add, "Add two numbers.");
    class_<MyClass>("cpp_class", init<int>())
        .def("get_value", &MyClass::getValue)
        .def("set_value", &MyClass::setValue);
}
