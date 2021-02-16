/*
The MIT License (MIT)

Copyright (c) 2021 Davide Pataracchia

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include <emscripten/bind.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace emscripten;
using namespace std;

class Benford
{
private:
    vector<int> data;

public:
    Benford(string input)
    {
        stringstream sStream;
        sStream << input;

        string tempWord;
        int foundInteger;
        while (!sStream.eof())
        {
            sStream >> tempWord;
            if (stringstream(tempWord) >> foundInteger)
                data.push_back(foundInteger);

            tempWord = "";
        }
    }

    double getFreq(int leading_digit)
    {
        if (data.size() == 0)
        {
            return 0;
        }
        if (leading_digit <= 0 || leading_digit > 9)
        {
            return 0;
        }

        int totalOcc = 0;
        for (int i = 0; i < data.size(); i++)
        {
            int firstDigit = data[i];

            while (firstDigit >= 10)
                firstDigit /= 10;

            if (firstDigit == leading_digit)
                totalOcc++;
        }

        return totalOcc * 100 / data.size();
    }
};

EMSCRIPTEN_BINDINGS(benford_class)
{
    class_<Benford>("Benford")
        .constructor<std::string>()
        .function("getFreq", &Benford::getFreq);
}