#ifndef FLAGS_H
#define FLAGS_H
#include <string>

using namespace std;

class globalFlags
{
    private:
        globalFlags(){}

    public:
        static bool fDebug;
        static bool fLearning;
        static bool fTest;
        static bool fInteractive;

        static string appPath;
};

#endif