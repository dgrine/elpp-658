#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[])
{
    el::Loggers::addFlag(el::LoggingFlag::HierarchicalLogging);
    if (argc <= 1)
    {
        std::cerr << "Error: missing level name.\nUsage: " << argv[0] << " <level_name>" << std::endl;
        return 1;
    }
    const std::string level_name = argv[1];
    int level = 0;
    if (level_name == "trace")
    {
        level = static_cast<int>(el::Level::Fatal)
              | static_cast<int>(el::Level::Error)
              | static_cast<int>(el::Level::Warning)
              | static_cast<int>(el::Level::Info)
              | static_cast<int>(el::Level::Debug)
              | static_cast<int>(el::Level::Trace);
    }
    else if (level_name == "debug")
    {
        level = static_cast<int>(el::Level::Fatal)
              | static_cast<int>(el::Level::Error)
              | static_cast<int>(el::Level::Warning)
              | static_cast<int>(el::Level::Info)
              | static_cast<int>(el::Level::Debug);
    }
    else if (level_name == "info")
    {
        level = static_cast<int>(el::Level::Fatal)
              | static_cast<int>(el::Level::Error)
              | static_cast<int>(el::Level::Warning)
              | static_cast<int>(el::Level::Info);
    }
    else if (level_name == "warning")
    {
        level = static_cast<int>(el::Level::Fatal)
              | static_cast<int>(el::Level::Error)
              | static_cast<int>(el::Level::Warning);
    }
    else if (level_name == "error")
    {
        level = static_cast<int>(el::Level::Fatal)
              | static_cast<int>(el::Level::Error);
    }
    else if (level_name == "fatal")
    {
        level = static_cast<int>(el::Level::Fatal);
    }
    else
    {
        level = static_cast<int>(el::Level::Fatal);
    }
    el::Loggers::setLoggingLevel(static_cast<el::Level>(level));

    LOG(TRACE)   << "TRACE";
    LOG(DEBUG)   << "DEBUG";
    LOG(INFO)    << "INFO";
    LOG(WARNING) << "WARNING";
    LOG(ERROR)   << "ERROR";
    LOG(FATAL)   << "FATAL";
    return 0;
}
