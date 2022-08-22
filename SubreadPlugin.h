#ifndef SUBREADPLUGIN_H
#define SUBREADPLUGIN_H

#include "Plugin.h"
#include "Tool.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class SubreadPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "Subread";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
