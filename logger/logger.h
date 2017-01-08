#include <iostream>
#include <sstream>
#include <fstream>

#define LOGLINE             logger::LineWriter()
#define LOGSETFILENAME(f)   logger::setFileName(f);

namespace logger
{
    struct Data
    {
        std::string filename;
        std::ofstream file;
        bool showLineNumbers;
        unsigned int lineNumber;
        Data() : lineNumber(0), showLineNumbers(true) {}
    };

    extern Data data;

    inline void setShowLineNumbers(bool value)
    {
        data.showLineNumbers = value;
    }

    inline void setFileName(const std::string& filename)
    {
        if (filename == data.filename)
            return;
        data.filename = filename;
        data.file.close();
    }

    class LineWriter
    {
    public:
        LineWriter();
        virtual ~LineWriter();
        template <typename T>
        logger::LineWriter& operator<<(const T&rhs)
        {
            ss << rhs;
            return *this;
        }
    private:
        std::stringstream ss;
    };
}