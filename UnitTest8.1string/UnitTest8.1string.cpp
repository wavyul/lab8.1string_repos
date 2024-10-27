#include "pch.h"
#include "CppUnitTest.h"
#include "../LB8.1string/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(ChangeTest)
        {
            string str1 = "abcaabbccdef";
            string str2 = "abcdef";

            Change(str1);
            Assert::AreEqual(string("abc*********def"), str1);

            Change(str2);
            Assert::AreEqual(string("abcdef"), str2);
        }
    };
}
