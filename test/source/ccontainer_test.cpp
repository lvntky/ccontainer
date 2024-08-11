#include <cstdlib>
#include <memory>
#include <string>
#include <type_traits>

#include <catch2/catch.hpp>

#include "ccontainer/ccontainer.h"

namespace {

template<typename T>
void c_free(T* ptr)
{
  using U = typename std::remove_cv<T>::type;
  std::free(static_cast<void*>(const_cast<U*>(ptr)));
}

}

TEST_CASE("Name is ccontainer", "[library]")
{
  using c_string_ptr = std::unique_ptr<char const, void(*)(char const*)>;
  auto name_ptr = c_string_ptr(header_only_name(), &c_free<char const>);

  REQUIRE(std::string("ccontainer") == name_ptr.get());
}
