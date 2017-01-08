#include "logger.h"
#include <stdio.h>

namespace logger
{
    Data data;

    LineWriter::LineWriter()
    {
    }

    LineWriter::~LineWriter()
    {
#if 0
        if (logger::data.filename.empty())
            throw std::exception("File name has not been set");
#else
        if (data.filename.empty())
            data.filename = "c:\\temp\\logger.log";
#endif
        if (!data.file.is_open())
            data.file.open(logger::data.filename);

        char buffer[256];

        if (data.showLineNumbers)
        {
            sprintf_s(buffer, "%5i", data.lineNumber++);
            data.file << buffer << " | ";
        }

        data.file << ss.str();
        data.file << std::endl;
    }
} // end of namespace