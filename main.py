import sys
sys.path.append("./build")
import build.funcpp as funcpp
import build.funcpp_boost as funcpp_boost

# pybind
a = funcpp.cpp_class(1)
a.set_value(33)

b = funcpp.cpp_class(2)

print(funcpp.add(1, 2))

print(funcpp.subtract(1, 2))


# boost python
c = funcpp_boost.cpp_class(6)
d = funcpp_boost.cpp_class(7)

print(c.get_value())