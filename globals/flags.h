#ifndef FLAGS_H
#define FLAGS_H

class globalFlags
{
    private:
        globalFlags(){}

    public:
        static bool fDebug;
        static bool fLearning;
        static bool fTest;
        static bool fInteractive;
};

#endif