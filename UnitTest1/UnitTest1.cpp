#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_1_rec/Main.cpp"
#define _CRT_SECURE_NO_WARNINGS

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(testCount)
        {
            char str1[] = "BKACCIS";

            Assert::AreEqual(6, Count(str1));
        }

        TEST_METHOD(testChange)
        {
            char str1[] = "BASIC{}";

            char* tmp = new char[strlen(str1) * 6 / 5 + 1];
            char* t = tmp;
            tmp[0] = '\0';

            char* result1 = Change(str1, tmp, t, 0);

            Assert::AreEqual(-1, strcmp("BASIC{}", result1));

            delete[] result1;
        }
    };
}