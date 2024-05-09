#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <nuclear/NuclearConstants.hpp>

/*
*  TEST CASES
* */
TEST_CASE("Testing nuclear::DynamicConstant") {
    nuclear::DynamicConstant c1;
    nuclear::DynamicConstant c2(3, "numver");
    nuclear::DynamicConstant c3(std::string("Hello there"), "somestring");
    nuclear::DynamicConstant c4(double(45) ,"dbl");

    SUBCASE("Constructors") {
        CHECK_MESSAGE(c1.Ptr() == nullptr, "Nullptr check");
        CHECK_MESSAGE(c1.Name() == "UnknownConstant", "Unknown Message text");

        CHECK_MESSAGE(c2.GetValue<int>() == 3, "c2");
        CHECK(c2.Name() == "numver");

        CHECK(c3.GetValue<std::string>() == "Hello there");
        CHECK(c3.Name() == "somestring");

        CHECK(c4.GetValue<double>() == 45);
        CHECK(c4.Name() == "dbl");
    }

    SUBCASE("Constant map") {
        nuclear::AddConstant<double>(3e8, "celerity");

        CHECK(nuclear::GetConstant("celerity") != nullptr);
        CHECK(nuclear::GetConstant("celerity")->GetValue<double>() == 3e8);
    }
}