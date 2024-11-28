#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab11.1\FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            const char* testFileName = "test.txt";
            ofstream fout(testFileName);
            fout << "+-+=\n";
            fout << "Some text\n";
            fout << "---\n";
            fout << "+=Another line+=\n";
            fout.close();

            // Act
            int result = CountSymbols((char*)testFileName);

            // Assert
            Assert::AreEqual(11, result); // Очікуваний результат: 10 символів '+', '-', '='

            // Clean up (Видалення тимчасового файлу)
            remove(testFileName);
        }
    };
}
