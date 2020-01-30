#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <thread>

#include "my_utils.h"
#include "async.h"

using namespace std;



int main(int, const char **)
{
    MY_DEBUG_ONLY(cout << "Homework async (DEBUG detected)" << endl);

    #if (defined WIN32) || (defined WIN64)
        cout << "Windows detected" << endl;
    #else
        // some
    #endif

    size_t block_size = 5;
    auto h = async::connect(block_size);
    auto h2 = async::connect(block_size);
    async::receive(h, "1", 1);
    async::receive(h2, "1\n", 2);
    async::receive(h, "\n2\n3\n4\n5\n6\n{\na\n", 15);
    async::receive(h, "b\nc\nd\n}\n89\n", 11);
    async::disconnect(h);
    async::disconnect(h2);

    return 0;
}




//int main(int argc, const char **argv)
//{

//    auto  cmds = make_unique<Commands>( (argc<2) ? 3 : static_cast<size_t>(atoi(argv[1])) );

//    auto ConsoleObs = make_shared<ConsoleObserver>();
//    ConsoleObs->JustNotConstructor(cmds);

//    auto LocalFileObs = std::make_shared<LocalFileObserver>();
//    LocalFileObs->JustNotConstructor(cmds);

//    string line;
//    while (getline(i_stream, line))
//    {
//        #if (defined WIN32) || (defined WIN64)
//            std::this_thread::sleep_for(1.0s);
//            cout << line << endl; // just echo
//        #else
//            // nothing
//        #endif

//        cmds->AnalyzeCommand(line);
//    }
//    cmds->ExecForAllSubs(true);

//    return 0;
//}

